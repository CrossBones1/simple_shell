#include "shell.h"
int main(int argc, char *argv[])
{
info_t info = INFO_INIT;
(void)argc;
(void)argv;
/* Initialiser les structures de données ou */
/* les variables nécessaires ici */
while (1)
{
/* Afficher l'invite de commandes du shell ou tout autre message ici */
/* Lire la ligne d'entrée de l'utilisateur */
if (get_input(&info) == -1)
break;
/* Traiter la ligne d'entrée */
find_structure(&info);
find_cmd(&info);
/* Gérer éventuellement les enchaînements de commandes ici */
/* Exécuter les commandes */
fork_cmd(&info);
/* Libérer toute mémoire allouée dynamiquement */
/* ou effectuer le nettoyage ici */
}
/* Effectuer éventuellement le nettoyage final ici */
return (0);
}
