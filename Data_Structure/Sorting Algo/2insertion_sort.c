#include <stdio.h>

void print_array(int array[], int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", array[i]);

    printf("\n\n");
}

void insertion_sort(int array[], int size)
{
    for (int i = 1; i < size; i++)
    {
        int x = array[i];
        int j = i - 1;
        while (j > -1 && array[j] > x)
        {
            if (array[j] > x)
            {
                array[j + 1] = array[j];
            }
            j--;
        }
        printf("j : %d\n", j);
        array[j + 1] = x;
    }
}

int main()
{
    system("cls");
    system("color a");

    int array[] = {4, 5, 2, 1, 3, 7, 8, 9, 6, 10};
    int size = 10;

    printf("before sorting: \n");
    print_array(array, size);

    insertion_sort(array, size);
    printf("after sorting: \n");
    print_array(array, size);

    int a = 10;
    int b = 50;

    return 0;
}