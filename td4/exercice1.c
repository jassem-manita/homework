#include <stdio.h>
#include <string.h>

int compter_lettre(char *texte, char lettre)
{
    int compteur = 0;
    int i = 0;

    while (texte[i] != '\0')
    {
        if (texte[i] == lettre)
            compteur++;
        i++;
    }
    return compteur;
}

void supprimer_lettre(char *texte, char lettre)
{
    int i = 0;
    int j = 0;

    while (texte[i] != '\0')
    {
        if (texte[i] != lettre)
        {
            texte[j] = texte[i];
            j++;
        }
        i++;
    }
    texte[j] = '\0';
}

void inverser_chaine(char *texte)
{
    int longueur = strlen(texte);
    int i, j;
    char temp;

    for (i = 0, j = longueur - 1; i < j; i++, j--)
    {
        temp = texte[i];
        texte[i] = texte[j];
        texte[j] = temp;
    }
}

int main()
{
    char phrase[133];
    char lettre;

    printf("Entrez une phrase : ");
    fgets(phrase, sizeof(phrase), stdin);
    phrase[strcspn(phrase, "\n")] = '\0';

    printf("Entrez une lettre a analyser : ");
    scanf("%c", &lettre);

    int occurrences = compter_lettre(phrase, lettre);
    printf("Nombre de '%c' : %d\n", lettre, occurrences);

    char phrase_sans_lettre[133];
    strcpy(phrase_sans_lettre, phrase);
    supprimer_lettre(phrase_sans_lettre, lettre);
    printf("Phrase sans '%c' : %s\n", lettre, phrase_sans_lettre);

    char phrase_inversee[133];
    strcpy(phrase_inversee, phrase);
    inverser_chaine(phrase_inversee);
    printf("Phrase inversee : %s\n", phrase_inversee);

    return 0;
}
