#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>
#include <signal.h>

/* ... (rest of the code) ... */

/* Function prototypes */
ssize_t _getline(info_t *info, char **lineptr, size_t *n);
int find_structure(info_t *info);
void find_cmd(info_t *info);
void fork_cmd(info_t *info);
void clear_info(info_t *info);
int is_delim(char c, char *delim);

/* ... (rest of the code) ... */

#endif /* _SHELL_H_ */

