#include <stdio.h>
#include <stdlib.h>

void trierTableau(int *tab, int N)
{
    int i, j, min_idx, temp;

    for (i = 0; i < N - 1; i++)
    {
        min_idx = i;
        for (j = i + 1; j < N; j++)
        {
            if (*(tab + j) < *(tab + min_idx))
            {
                min_idx = j;
            }
        }
        if (min_idx != i)
        {
            temp = *(tab + i);
            *(tab + i) = *(tab + min_idx);
            *(tab + min_idx) = temp;
        }
    }
}

int main()
{
    int N, i;
    int *tableau;

    // Demande la taille du tableau
    printf("Entrez le nombre d'entiers a trier : ");
    scanf("%d", &N);

    // Allocation dynamique
    tableau = (int *)malloc(N * sizeof(int));
    if (tableau == NULL)
    {
        printf("Erreur d'allocation de memoire\n");
        return 1;
    }

    // Remplissage du tableau
    for (i = 0; i < N; i++)
    {
        printf("Entrez l'entier %d : ", i + 1);
        scanf("%d", tableau + i);
    }

    // Tri du tableau
    trierTableau(tableau, N);

    // Affichage du tableau trie
    printf("\nTableau trie :\n");
    for (i = 0; i < N; i++)
    {
        printf("%d ", *(tableau + i));
    }
    printf("\n");

    // Liberation de la memoire
    free(tableau);

    return 0;
}
