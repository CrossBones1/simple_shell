#include "shell.h"
/**
* main - Entry point for the simple shell program.
*
* Return: Always 0.
*/
int main(void)
{
info_t info = INFO_INIT;
signal(SIGINT, sigintHandler);
populate_env_list(&info);
while (1)
{
_puts("$ ");
if (get_input(&info) == -1)
break;
find_structure(&info);
clear_info(&info);
}
write_history(&info);
free_info(&info, 1);
return (0);
}

