#include <stdio.h>
#include <stdlib.h>

int main()
{
    system("cls");
    // in stack memory
    int arr1[3][4] = {{1, 2, 3, 4}, {1, 3, 5, 7}, {2, 4, 6, 8}};

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
            printf(" %d ", arr1[i][j]);
        printf("\n");
    }

    printf("________________________________\n");

    // stack and heap memory
    int *arr2[3];
    arr2[0] = malloc(4 * sizeof(int));
    arr2[1] = malloc(4 * sizeof(int));
    arr2[2] = malloc(4 * sizeof(int));

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
            printf(" %d ", arr2[i][j]);
        printf("\n");
    }

    printf("___________________________________\n");

    // only in heap memory
    int **arr3;
    arr3 = malloc(4 * sizeof(int *));
    arr3[0] = malloc(4 * sizeof(int));
    arr3[1] = malloc(4 * sizeof(int));
    arr3[2] = malloc(4 * sizeof(int));

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
            printf(" %d ", arr3[i][j]);
        printf("\n");
    }

    printf("____________________________________");
}
