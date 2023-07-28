#include "shell.h"
/* ... Déclarations de fonctions spécifiques à shell.c */
/* et variables globales si nécessaire ... */
/* Cette fonction lit la ligne d'entrée de l'utilisateur depuis stdin */
/* et la stocke dans info->arg.*/
/* Elle renvoie le nombre de caractères lus (y compris le '\n' final), */
/* ou -1 en cas d'erreur ou de fin de fichier. */
ssize_t get_input(info_t *info)
{
char *line = NULL;
size_t len = 0;
ssize_t nread;
/* Facultativement, ajoutez du code pour afficher */
/* l'invite de commandes du shell ici */
nread = _getline(info, &line, &len);
if (nread == -1)
{
/* Facultativement, ajoutez du code pour gérer les erreurs*/
/* ou la fin du fichier ici */
}
else
{
/* Facultativement, traitez davantage la ligne */
/* d'entrée si nécessaire */
/* Par exemple, vous pouvez supprimer les espaces */
/* en début/fin de ligne, etc. */
}
/* Facultativement, libérez toute mémoire allouée */
/* dynamiquement si nécessaire */
free(line);
return (nread);
}
/* Cette fonction analyse la ligne d'entrée (info->arg)*/
/* pour identifier les structures de commandes.*/
/* Elle met à jour info->cmd_buf et info->cmd_buf_type */
/* en fonction de la structure trouvée. */
int find_structure(info_t *info __attribute__((unused)))
{
/* Implémentez la logique pour trouver la structure de commande ici */
/* Vous pouvez utiliser des fonctions auxiliaires si nécessaire */
/* Par exemple, vous pouvez rechercher */
/* les opérateurs de commande (&&, ||, ;) */
return (0);
}
/* Cette fonction identifie la commande à exécuter */
/* à partir de info->cmd_buf.*/
/* Elle met à jour info->argv et info->argc pour stocker */
/* les arguments de la commande. */
void find_cmd(__attribute__((unused)) info_t *info)
{
/* Implémentez la logique pour extraire la commande */
/* et ses arguments de info->cmd_buf ici */
/* Vous pouvez utiliser des fonctions de séparation de chaînes */
/* ou d'autres méthodes pour cela */
}
/* Cette fonction crée un processus enfant pour exécuter */
/* la commande identifiée par info->argv.*/
/* Elle met à jour info->status avec le statut */
/* de sortie du processus enfant. */
void fork_cmd(info_t *info)
{
pid_t pid;
int status;
/* Créez un processus enfant */
pid = fork();
if (pid == -1)
{
/* Erreur de fork */
perror("fork");
exit(EXIT_FAILURE);
}
else if (pid == 0)
{
/* Code du processus enfant */
/* Exécutez la commande en utilisant execvp */
execvp(info->argv[0], info->argv);
/* Si execvp renvoie, cela signifie qu'il y a eu une erreur */
perror("execvp");
exit(EXIT_FAILURE);
}
else
{
/* Code du processus parent */
/* Attendez que le processus enfant se termine */
waitpid(pid, &status, 0);
/* Mettez à jour info->status avec le statut */
/* de sortie du processus enfant */
if (WIFEXITED(status))
{
info->status = WEXITSTATUS(status);
}
else
{
/* Gestion des erreurs si le processus enfant */
/* ne s'est pas terminé normalement */
info->status = -1;
}
}
}
