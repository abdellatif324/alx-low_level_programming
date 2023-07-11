#ifndef MAIN_h
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stddef.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

ssize_t read_textfile(const char *filename, size_t letters);
int create_file(const char *filename, char *text_content);



#endif
