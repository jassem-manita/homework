#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_ARGS 10
#define MAX_ARG_LENGTH 50

// Fonction pour compter le nombre d'arguments
int compter_arguments(int argc)
{
    return argc;
}

// Fonction pour afficher les arguments avec leur numéro d'ordre
void afficher_arguments(char **args, int argc)
{
    for (int i = 0; i < argc; i++)
    {
        printf("%d : %s\n", i + 1, args[i]);
    }
}

// Fonction pour afficher la longueur de chaque argument
void longueur_arguments(char **args, int argc)
{
    for (int i = 0; i < argc; i++)
    {
        int longueur = strlen(args[i]);
        printf("%d : %s (%d caractère%s)\n", i + 1, args[i], longueur,
               (longueur > 1) ? "s" : "");
    }
}

int main()
{
    char *arguments[MAX_ARGS];
    char buffer[MAX_ARG_LENGTH];
    int nb_args;

    printf("Combien d'arguments souhaitez-vous entrer (max %d) ? ", MAX_ARGS);
    scanf("%d", &nb_args);
    getchar();

    if (nb_args <= 0 || nb_args > MAX_ARGS)
    {
        printf("Nombre d'arguments invalide!\n");
        return 1;
    }

    printf("Veuillez entrer les arguments:\n");
    for (int i = 0; i < nb_args; i++)
    {
        printf("Argument %d: ", i + 1);
        fgets(buffer, MAX_ARG_LENGTH, stdin);
        buffer[strcspn(buffer, "\n")] = '\0';

        arguments[i] = (char *)malloc((strlen(buffer) + 1) * sizeof(char));
        if (arguments[i] == NULL)
        {
            printf("Erreur d'allocation memoire!\n");
            for (int j = 0; j < i; j++)
            {
                free(arguments[j]);
            }
            return 1;
        }
        strcpy(arguments[i], buffer);
    }

    printf("\nNombre d'arguments : %d\n", compter_arguments(nb_args));

    printf("\nArguments avec leur numero d'ordre:\n");
    afficher_arguments(arguments, nb_args);

    printf("\nArguments avec leur longueur:\n");
    longueur_arguments(arguments, nb_args);

    for (int i = 0; i < nb_args; i++)
    {
        free(arguments[i]);
    }

    return 0;
}
