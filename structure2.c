#include "shell.h"

/**
 * _myhistory - Shows the history list, with each command on a separate line,
 *              preceded by line numbers starting from 0.
 * @info: Structure containing possible arguments. Maintains
 *        a constant function prototype.
 * Return: Always returns 0.
 */

int _myhistory(info_t *info)
{
print_list(info->history);
return (0);
}

/**
 * unset_alias - removes an alias from the list
 * @info: parameter struct
 * @str: the string representing the alias to be removed
 *
 * This function removes the alias specified by @str from the alias list.
 *
 * Return: 0 on success, 1 if an error occurs
 */

int unset_alias(info_t *info, char *str)
{
char *z, e;
int ret;

z = _strchr(str, '=');
if (!z)
return (1);
e = *z;
*z = 0;
ret = delete_node_at_index(&(info->alias),
get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
*z = e;
return (ret);
}

/**
* set_alias - sets alias to string
* @info: parameter struct
* @str: the string alias
*
* Return: Always 0 on success, 1 on error
*/
int set_alias(info_t *info, char *str)
{
char *z;

z = _strchr(str, '=');
if (!z)
return (1);
if (!*++z)
return (unset_alias(info, str));

unset_alias(info, str);
return (add_node_end(&(info->alias), str, 0) == NULL);
}

/**
* print_alias - prints an alias string
* @node: the alias node
*
* Return: Always 0 on success, 1 on error
*/
int print_alias(list_t *node)
{
char *z = NULL, *a = NULL;

if (node)
{
z = _strchr(node->str, '=');
for (a = node->str; a <= z; a++)
_putchar(*a);
_putchar('\'');
_puts(z + 1);
_puts("'\n");
return (0);
}
return (1);
}

/**
* _myalias - mimics the alias structure (man alias)
* @info: Structure containing potential arguments. Used to maintain
*        constant function prototype.
* Return: Always 0
*/
int _myalias(info_t *info)
{
int i = 0;
char *z = NULL;
list_t *node = NULL;

if (info->argc == 1)
{
node = info->alias;
while (node)
{
print_alias(node);
node = node->next;
}
return (0);
}
for (i = 1; info->argv[i]; i++)
{
z = _strchr(info->argv[i], '=');
if (z)
set_alias(info, info->argv[i]);
else
print_alias(node_starts_with(info->alias, info->argv[i], '='));
}

return (0);
}
