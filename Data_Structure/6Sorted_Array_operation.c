// operations :
// 1.Traverse
// 2.deletion(by value and by index)
// 3.search (by value and index)
// 4.update(update the value at given index or value)

#include <stdio.h>
#include <stdlib.h>

struct array
{
    int size;
    int *arr;
};

typedef struct array Array;

void create(Array *a)
{
    printf("Enter the size of array : \n");
    scanf("%d", &a->size);
    // a->size = 10;

    a->arr = malloc(sizeof(int) * a->size);

    printf("Enter the elements of array:\n");

    for (int i = 0; i < a->size; i++)
    {
        printf("Enter %dth element\n", i);
        scanf("%d", &a->arr[i]);
    }
}

void traverse(Array *a)
{
    // printf("\n");
    for (int i = 0; i < a->size; i++)
    {
        printf("%d\t", a->arr[i]);
    }
    printf("\n");
}

void insert(Array *a, int value)
{
    int i = a->size;
    while (a->arr[i] > value && i >= 0)
    {
        a->arr[i + 1] = a->arr[i];

        i--;
    }

    a->arr[i + 1] = value;
}

int del_pos(Array *a, int index)
{
    int del_value = a->arr[index];

    if (index > a->size)
    {
        printf("\nindex out or range\n");
        return -1;
    }
    else
    {
        int i = index;
        while (i < a->size)
        {
            a->arr[i] = a->arr[i + 1];
            i++;
        }
        a->size--;
        return del_value;
    }
}

int update_pos(Array *a, int pos, int value)
{
    a->arr[pos] = value;
}

int B_Search(Array a, int item)
{
    int low = 0;
    int high = a.size - 1;
    int mid = high / 2;

    while (a.arr[mid] != item && low <= high)
    {
        mid = (low + high) / 2;

        if (a.arr[mid] < item)
        {
            low = mid + 1;
        }

        if (a.arr[mid] > item)
            high = mid - 1;
    }

    if (a.arr[mid] == item)
        return mid;
    else
        return -1;
}

int main()
{
    system("cls");
    system("color a");

    Array *A1;
    create(A1);
    traverse(A1);

    // insert(A1, 5);
    // printf("after insertion of 5\n");
    // traverse(A1);

    // printf("deleted value : %d \n", del_pos(A1, 0));
    // traverse(A1);
    // printf("deleted value : %d \n", del_pos(A1, 5));
    // traverse(A1);

    // printf("deleted value : %d \n", del_pos(A1, 5));

    printf("\nAfter update of 0 at 0th pos.\n");
    update_pos(A1, 0, 0);
    traverse(A1);

    int index = B_Search(*A1, 5);
    printf("the value found at index : %d\n", index);
    traverse(A1);

    return 0;
}

/*
input  format given to this:
    5
-----------------

    1
    2
    3
    4
    5
 */