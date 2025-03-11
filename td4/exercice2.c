#include <stdio.h>
#include <string.h>

// Fonction pour conjuguer un verbe du premier groupe au present de l'indicatif
void conjuguer(char *verbe)
{
    char radical[30];
    int len = strlen(verbe);

    // Extraire le radical (enlever "er" à la fin)
    strncpy(radical, verbe, len - 2);
    radical[len - 2] = '\0';

    printf("je %s%s\n", radical, "e");
    printf("tu %s%s\n", radical, "es");
    printf("il %s%s\n", radical, "e");
    printf("nous %s%s\n", radical, "ons");
    printf("vous %s%s\n", radical, "ez");
    printf("ils %s%s\n", radical, "ent");
}

int main()
{
    char verbe[27]; // 26 + 1 pour le \0

    printf("Entrez un verbe du premier groupe : ");
    fgets(verbe, sizeof(verbe), stdin);
    verbe[strcspn(verbe, "\n")] = '\0'; // Enlever le \n

    int len = strlen(verbe);
    if (len >= 2 && verbe[len - 2] == 'e' && verbe[len - 1] == 'r')
    {
        conjuguer(verbe);
    }
    else
    {
        printf("Erreur : Ce n'est pas un verbe du premier groupe.\n");
    }

    return 0;
}
