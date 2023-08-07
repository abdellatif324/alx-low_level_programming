#ifndef _MAIN_H_
#define _MAIN_H_

#include <stddef.h>
#include <fcntl.h>
ssize_t read_textfile(const char *filename, size_t letters);
int create_file(const char *filename, char *text_content);
int append_text_to_file(const char *filename, char *text_content);

void check_arguments(int argc, char *argv[]);
int open_file(const char *filename, int flags, mode_t mode);
void copy_file(int source_fd, int dest_fd);
void close_file(int fd, const char *filename);

#endif
