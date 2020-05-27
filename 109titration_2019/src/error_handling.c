/*
** EPITECH PROJECT, 2020
** 109titration
** File description:
** error_handling
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "titration.h"
#include "error_msg.h"

static int check_number(char *buff)
{
    if (buff[0] == ';')
        return (TRUE);
    for (int i = 1; buff[i] != '\0'; i++) {
        if (buff[i] == ';' && buff[i + 1] == '\0')
            return (TRUE);
        if (buff[i] == ';' && (buff[i - 1] == '\n' || buff[i + 1] == '\n'))
            return (TRUE);
    }
    return (FALSE);
}

static int check_buffer(char *buff)
{
    for (int i = 0; buff[i] != '\0'; i++) {
        if (buff[i] == '\n' || buff[i] == ';' || buff[i] == '.')
            continue;
        if (buff[i] < '0' || buff[i] > '9') {
            write_error(STR_ERROR_INV);
            return (TRUE);
        }
        if (check_number(buff)) {
            write_error(STR_ERROR_LINE);
            return (TRUE);
        }
    }
    return (FALSE);
}

static char *read_file(int fd, char *file)
{
    struct stat st;
    char *buffer;
    int rd = 0;

    stat(file, &st);
    buffer = malloc(sizeof(char) * st.st_size + 1);
    rd = read(fd, buffer, st.st_size);
    buffer[st.st_size] = '\0';
    if (rd == -1 || rd == 0)
        return (NULL);
    return (buffer);
}

int error_handling(char *file)
{
    int fd = open(file, O_RDONLY);
    char *buffer;

    if (fd == -1) {
        write_error(STR_ERROR_OPEN);
        return (TRUE);
    }
    if ((buffer = read_file(fd, file)) == NULL) {
        close(fd);
        free(buffer);
        return (TRUE);
    }
    if (check_buffer(buffer)) {
        close(fd);
        free(buffer);
        return (TRUE);
    }
    close(fd);
    free(buffer);
    return (FALSE);
}
