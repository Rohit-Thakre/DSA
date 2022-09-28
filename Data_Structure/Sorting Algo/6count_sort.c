#include <stdio.h>

int max(int array[], int size)
{
    int max = -__INT_MAX__;
    for (int i = 0; i < size; i++)

        if (array[i] >= max)
            max = array[i];

    return max;
}

void count_sort(int array[], int size)
{
    int mx = max(array, size);
    int hash_Ar[mx + 1];

    for (int i = 0; i < mx + 1; i++)
        hash_Ar[i] = 0;

    for (int i = 0; i < size; i++)
        hash_Ar[array[i]]++;

    int k = 0;
    for (int i = 0; k < size; i++)
    {
        if (hash_Ar[i] != 0)
        {
            array[k++] = i;
            hash_Ar[i--]--;
            // i--;
        }
    }
}

void print_array(int array[], int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", array[i]);

    printf("\n\n");
}

int main()
{
    system("cls");
    system("color a");

    int array[] = {2, 3, 4, 4, 1, 7, 9, 10};
    int size = sizeof(array) / __SIZEOF_INT__;
    count_sort(array, size);
    print_array(array, size);

    return 0;
}
