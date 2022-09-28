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

void selection_sort(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        int j, smallest;
        j = smallest = i;

        while (j < size)
        {
            if (array[j] < array[smallest])
                smallest = j;
            j++;
        }
        swap(&array[i], &array[smallest]);
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

    selection_sort(array, size);
    printf("after sorting: \n");
    print_array(array, size);

    int a = 10;
    int b = 50;

    return 0;
}