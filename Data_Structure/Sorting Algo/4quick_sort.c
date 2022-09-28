#include <stdio.h>
void print_array(int array[], int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", array[i]);

    printf("\n\n");
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void quick_sort(int array[], int low, int high)
{
    if (high < 2)
        return;
    if (low >= high)
        return;

    int pivot_idx = low;
    int i = low + 1;
    int j = high;

    while (i < j)
    {
        while (array[i] < array[pivot_idx] && i < high)
            i++;

        while (array[j] >= array[pivot_idx] && j > low)
            j--;

        if (i < j)
        {
            printf("i %d j %d", i, j);
            print_array(array, 6);
            swap(&array[i], &array[j]);
        }
    }

    // printf("i %d \nj %d\n", i, j);
    if (array[j] <= array[pivot_idx])
    {
        swap(&array[j], &array[pivot_idx]);
        print_array(array, 7);
    }

    quick_sort(array, low, j - 1);
    quick_sort(array, i, high);
}
int main()
{
    // system("cls");
    // system("color a");
    int array[] = {90, 80, 70, 60, 50, 40, 30};
    int size = 7;

    printf("before sort:\n");
    print_array(array, size);

    quick_sort(array, 0, size - 1);
    printf("after sort\n");
    print_array(array, size);
    return 0;
}