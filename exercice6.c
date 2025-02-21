#include <stdio.h>

#define MAX_TAILLE 5

// Fonction pour verifier si la file est pleine
int estPleine(int debut, int fin, int taille)
{
    return ((fin + 1) % taille == debut);
}

// Fonction pour verifier si la file est vide
int estVide(int debut, int fin)
{
    return (debut == fin);
}

// Fonction pour ajouter un element
void enfile(int *file, int *debut, int *fin, int taille, int valeur)
{
    if (estPleine(*debut, *fin, taille))
    {
        printf("Error: La file est pleine!\n");
        return;
    }

    file[*fin] = valeur;
    *fin = (*fin + 1) % taille;
}

// Fonction pour retirer un element
int defile(int *file, int *debut, int *fin, int taille)
{
    if (estVide(*debut, *fin))
    {
        printf("Error: La file est vide!\n");
        return -1;
    }

    int valeur = file[*debut];
    *debut = (*debut + 1) % taille;
    return valeur;
}

// Fonction pour afficher la file
void afficherFile(int *file, int debut, int fin, int taille)
{
    printf("File: ");
    if (estVide(debut, fin))
    {
        printf("(vide)\n");
        return;
    }

    int i = debut;
    while (i != fin)
    {
        printf("%d ", file[i]);
        i = (i + 1) % taille;
    }
    printf("\n");
}

int main()
{
    int file[MAX_TAILLE];
    int debut = 0, fin = 0;
    int choix, valeur;

    while (1)
    {
        printf("\n1. Enfiler un element");
        printf("\n2. Defiler un element");
        printf("\n3. Afficher la file");
        printf("\n4. Quitter");
        printf("\nVotre choix: ");
        scanf("%d", &choix);

        switch (choix)
        {
        case 1:
            printf("Entrez la valeur a enfiler: ");
            scanf("%d", &valeur);
            enfile(file, &debut, &fin, MAX_TAILLE, valeur);
            afficherFile(file, debut, fin, MAX_TAILLE);
            break;

        case 2:
            valeur = defile(file, &debut, &fin, MAX_TAILLE);
            if (valeur != -1)
            {
                printf("Element defile: %d\n", valeur);
                afficherFile(file, debut, fin, MAX_TAILLE);
            }
            break;

        case 3:
            afficherFile(file, debut, fin, MAX_TAILLE);
            break;

        case 4:
            printf("Programme termine.\n");
            return 0;

        default:
            printf("Choix invalide!\n");
        }
    }

    return 0;
}
