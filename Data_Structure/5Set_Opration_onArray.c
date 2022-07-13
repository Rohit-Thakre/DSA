// set oprations on array
// (sorted array)

// 1. union (add both set elements to single one) O(m +n)
// 2. difference (elements which is in set A but not in B)
// 3. intersection (common element in both set A and B) incomplete
// 4. membership check

#include <stdio.h>
#include <stdlib.h>

struct array
{
    int A[10];
    int size;
    int length;
};

typedef struct array Array;

void display(Array *arr)
{
    for (int i = 0; i < arr->length; i++)
        printf(" %d ", arr->A[i]);
    printf("\n\n");
}

Array *Union(Array a, Array b)
{
    Array *c = (Array *)malloc(sizeof(Array));
    int i = 0, j = 0, k = 0;

    while (i < a.length && j < b.length)
    {
        if (a.A[i] < b.A[j])
        {
            c->A[k] = a.A[i];
            i++;
            k++;
        }

        else if (a.A[i] > b.A[j])
        {
            c->A[k] = b.A[j];
            k++;
            j++;
        }

        else
        {
            c->A[k] = a.A[i];
            i++;
            j++;
            k++;
        }
    }
    if (i < a.length)
        for (int index = i; index < a.length; index++)
            c->A[k++] = a.A[index];

    else if (j < b.length)
    {
        for (int index = j; index < a.length; index++)
            b.A[k++] = b.A[index];
    }
    c->length = k;
    return c;
}

Array *Difference(Array a, Array b)
{
    Array *c = (Array *)malloc(sizeof(Array));
    int i = 0, j = 0, k = 0;

    while (i < a.length)
    {
        if (a.A[i] < b.A[j])
        {
            c->A[k] = a.A[i];
            k++;
            i++;
        }

        else if (a.A[i] > b.A[j])
            j++;

        else // both same
        {
            i++;
            j++;
        }
    }
    c->length = k;
    return c;
}

Array *intersection(Array a, Array b)
{
    Array *common = (Array *)malloc(sizeof(Array));
    int i = 0, j = 0, k = 0;

    while (i < a.length)
    {
        if (a.A[i] < b.A[j])
        {
            // k++;
            i++;
        }

        else if (a.A[i] > b.A[j])
            j++;

        else // both same
        {
            common->A[k] = a.A[i];
            k++;
            i++;
            j++;
        }
    }
    common->length = k;
    return common;
}
int main()
{
    system("cls");
    system("color a");
    // Array = {{elemets}, size, length};

    // Array arr1 = {{1, 3, 5, 7, 9}, 10, 5};
    Array arr1 = {{2, 4, 5, 9, 15}, 10, 5};
    Array arr2 = {{2, 4, 6, 8, 10}, 10, 5};

    printf("array 1:\n");
    display(&arr1);
    printf("array 2:\n");
    display(&arr2);
    Array *arr3;
    arr3 = Union(arr1, arr2);
    printf("union of array 1 and array 2:\n");
    display(arr3);

    Array *arr4;
    arr4 = Difference(arr1, arr2);
    printf("difference of array array 1 and array 2:\n");
    display(arr4);

    Array *arr5 = intersection(arr1, arr2);
    printf("intersection(common) of array 1 and array 2:\n");
    display(arr5);

    printf("\n\n");

    return 0;
}