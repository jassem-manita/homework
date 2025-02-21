#include <stdio.h>
#define MAX_SIZE 1000

// Fonction pour calculer la longueur d'une chaine
int longueurChaine(char *str)
{
    int longueur = 0;
    char *ptr = str;
    while (*ptr != '\0')
    {
        longueur++;
        ptr++;
    }
    return longueur;
}

// Fonction pour compter le nombre de mots
int compterMots(char *str)
{
    int mots = 0;
    int dansMot = 0;
    char *ptr = str;

    while (*ptr != '\0')
    {
        if (*ptr == ' ' || *ptr == '\t' || *ptr == '\n')
        {
            dansMot = 0;
        }
        else if (dansMot == 0)
        {
            dansMot = 1;
            mots++;
        }
        ptr++;
    }
    return mots;
}

// Fonction pour inverser la chaine
void inverserChaine(char *str)
{
    char *debut = str;
    char *fin = str;
    char temp;
    while (*fin != '\0')
    {
        fin++;
    }
    fin--; 

    // Inverser la chaine
    while (debut < fin)
    {
        temp = *debut;
        *debut = *fin;
        *fin = temp;
        debut++;
        fin--;
    }
}

int main()
{
    char phrase[MAX_SIZE];

    printf("Veuillez saisir une phrase : ");
    fgets(phrase, MAX_SIZE, stdin);

    char *ptr = phrase;
    while (*ptr != '\0')
    {
        if (*ptr == '\n')
        {
            *ptr = '\0';
            break;
        }
        ptr++;
    }

   
    printf("Longueur de la phrase : %d\n", longueurChaine(phrase));
    printf("Nombre de mots : %d\n", compterMots(phrase));

    printf("Phrase originale : %s\n", phrase);
    inverserChaine(phrase);
    printf("Phrase inversee : %s\n", phrase);

    return 0;
}
