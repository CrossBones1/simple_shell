#include "shell.h"
int main(void)
{
char *line;
size_t len = 0;
ssize_t read;
info_t info = INFO_INIT;
if (signal(SIGINT, sigintHandler) == SIG_ERR)
perror("signal");
populate_env_list(&info);
read_history(&info);
while (1)
{
if (isatty(STDIN_FILENO))
_puts("$ ");
read = _getline(&info, &line, &len);
if (read == -1)
{
if (isatty(STDIN_FILENO))
_putchar('\n');
break;
}
find_structure(&info);
clear_info(&info);
}
write_history(&info);
free_info(&info, 1);
return (0);
}
void fork_cmd(info_t *info)
{
pid_t child_pid;
int status;
child_pid = fork();
if (child_pid == -1)
{
perror("fork");
info->status = 2;
}
else if (child_pid == 0)
{
if (execve(info->argv[0], info->argv, info->environ) == -1)
{
perror("execve");
info->status = 127;
}
}
else
{
wait(&status);
info->status = WEXITSTATUS(status);
}
}
