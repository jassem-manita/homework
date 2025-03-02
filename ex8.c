#include <stdio.h>
#include <stdlib.h>

// Fonction pour allouer la matrice
int **allouerMatrice(int N)
{
    int **mat = (int **)malloc(N * sizeof(int *));
    if (mat == NULL)
        return NULL;

    for (int i = 0; i < N; i++)
    {
        mat[i] = (int *)malloc(N * sizeof(int));
        if (mat[i] == NULL)
        {
            // Liberation de la memoire deja alloue en cas d'echec
            for (int j = 0; j < i; j++)
            {
                free(mat[j]);
            }
            free(mat);
            return NULL;
        }
    }
    return mat;
}

// Fonction pour liberer la meoire
void libererMatrice(int **mat, int N)
{
    for (int i = 0; i < N; i++)
    {
        free(mat[i]);
    }
    free(mat);
}

// Fonction pour afficher la matrice
void afficherMatrice(int **mat, int N)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf("%d\t", mat[i][j]);
        }
        printf("\n");
    }
}

// Fonction pour transposer la matrice
void transposerMatrice(int **mat, int N)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            int temp = mat[i][j];
            mat[i][j] = mat[j][i];
            mat[j][i] = temp;
        }
    }
}

// Fonction pour calculer et afficher la somme des diagonales
void calculerDiagonales(int **mat, int N)
{
    int somme_diag1 = 0, somme_diag2 = 0;

    for (int i = 0; i < N; i++)
    {
        somme_diag1 += mat[i][i];
        somme_diag2 += mat[i][N - 1 - i];
    }

    printf("Somme diagonale principale : %d\n", somme_diag1);
    printf("Somme diagonale secondaire : %d\n", somme_diag2);
}

int main()
{
    int N;
    int **matrice;

    // Saisie de la taille
    printf("Entrez la taille de la matrice carree : ");
    scanf("%d", &N);

    // Allocation de la matrice
    matrice = allouerMatrice(N);
    if (matrice == NULL)
    {
        printf("Erreur d'allocation de memoire\n");
        return 1;
    }

    // Remplissage de la matrice
    printf("Saisissez les éléments de la matrice :\n");
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf("Element [%d][%d] : ", i, j);
            scanf("%d", &matrice[i][j]);
        }
    }

    // Affichage de la matrice originale
    printf("\nMatrice originale :\n");
    afficherMatrice(matrice, N);

    // Calcul et affichage des sommes des diagonales
    printf("\nSommes des diagonales :\n");
    calculerDiagonales(matrice, N);

    // Transposition et affichage
    printf("\nMatrice transposée :\n");
    transposerMatrice(matrice, N);
    afficherMatrice(matrice, N);

    // Libération de la mémoire
    libererMatrice(matrice, N);

    return 0;
}
