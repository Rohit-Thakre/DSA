#include <stdio.h>
#include <stdlib.h>

void print_array(int array[], int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", array[i]);

    printf("\n\n");
}

int *merge(int array1[], int ar1_size, int array2[], int ar2_size)
{
    int *merge_array = (int *)malloc(sizeof(ar1_size + ar1_size));

    int i, j, k;
    i = j = k = 0;

    if (array1[i] < array1[j])
        merge_array[k] = array1[i];

    if (array1[i] > array1[j])
        merge_array[k] = array2[j];

    while (i < ar1_size && j < ar2_size)
    {
        if (array1[i] < array2[j])
            merge_array[k++] = array1[i++];

        if (array1[i] > array2[j])
            merge_array[k++] = array2[j++];

        if (array1[i] == array2[j])
        {
            merge_array[k++] = array2[j++];
            i++;
        }
    }

    if (i > ar1_size)
        while (j < ar2_size)

            merge_array[k++] = array2[j++];

    if (j > ar2_size)
        while (i < ar1_size)
            merge_array[k++] = array1[i++];

    return merge_array;
}

void merge_single(int array[], int low, int high)
{
    // int merged_array[high + 1];
    int merged_array[10];

    int mid = (low + high) / 2;
    int i = low, j = mid + 1, k = low;
    while (i <= mid && j <= high)
    {
        if (array[i] < array[j])
            merged_array[k++] = array[i++];

        if (array[i] > array[j])
        {
            printf("adding %d\n", array[j]);
            merged_array[k++] = array[j++];
        }
        else
        {
            // (array[i] > array[j]);
            merged_array[k++] = array[j++];
            i++;
        }
        // printf("inside loop");
    }
    for (i; i <= mid; i++)
    {
        merged_array[k++] = array[i];
        // printf("end adding %d\n", array[i]);
    }
    for (j; j <= high; j++)
    {
        // printf("end adding %d\n", array[j]);
        merged_array[k++] = array[j];
    }

    // printf("high = %d\n", high);

    for (int x = 0; x < high + 1; x++)
        // printf("%d  ", merged_array[x]);
        array[x] = merged_array[x];
}

void merge_sort(int array[], int low,
                int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        merge_sort(array, low, mid);
        merge_sort(array, mid + 1, high);
        merge_single(array, low, high);
    }
    return;
}
int main()
{
    int array[] = {1, 2, 6, 7, 4, 9, 3};
    int size = 7;

    // int array[] = {2, 1};
    // int size = 2;
    merge_sort(array, 0, size - 1);
    // merge_single(array, 0, size - 1);

    for (int i = 0; i < size; i++)
        printf("%d ", array[i]);

    return 0;
}