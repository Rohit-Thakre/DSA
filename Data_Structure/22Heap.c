#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void print_elements(int A[], int lst_idx)
{
    printf("\n");
    for (int i = 1; i <= lst_idx; i++)
        printf("%d ", A[i]);

    printf("\n");
}

void insert(int A[], int lst_idx)
{
    if (lst_idx > 1)
    {
        int i = lst_idx;
        int temp = A[i];

        while (i > 1 && temp > A[i / 2])
        {

            A[i] = A[i / 2];
            i = i / 2;
        }
        A[i] = temp;
    }
}

void delete (int A[], int lst_idx)
{
    int x = A[1];
    int i = 1, j = 2;
    A[1] = A[lst_idx];

    while (j < lst_idx)
    {
        if (A[j + 1] > A[j])
            j = j + 1;

        if (A[i] < A[j])
        {
            swap(&A[i], &A[j]);
            i = j;
            j = 2 * i;
        }

        else
            break;
    }

    A[lst_idx] = x;
}

void create_heap(int A[], int size)
{
    int i = 0;
    for (i = 1; i < size; i++)
        insert(A, i);
}

void heap_sort(int A[], int size)
{
    create_heap(A, size);

    for (int i = size - 1; i > 0; i--)
        delete (A, i);
}
int main()
{
    system("cls");
    system("color a");

    int A[10] = {0, 30, 10, 20, 50, 90, 80, 40, 60, 5};

    heap_sort(A, 10);
    print_elements(A, 9);

    return 0;
}