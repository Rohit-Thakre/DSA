#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void print_array(int array[], int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", array[i]);

    printf("\n\n");
}

void bubble_sort(int array[], int size)
{
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size - 1 - i; j++)
            if (array[j] > array[j + 1])
                swap(&array[j], &array[j + 1]);
}
int main()
{
    system("cls");
    system("color a");

    int array[] = {4, 5, 2, 1, 3, 7, 8, 9, 6, 10};
    int size = 10;

    printf("before sorting: \n");
    print_array(array, size);

    bubble_sort(array, size);
    printf("after sorting: \n");
    print_array(array, size);

    int a = 10;
    int b = 50;

    return 0;
}