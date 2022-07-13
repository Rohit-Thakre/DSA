#include <stdio.h>
#include <stdlib.h>

struct array
{
    int A[10];
    int size;
    int length;
};

typedef struct array Array;

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

int get_value(Array arr, int index)
{
    if (index > 0 && index < arr.length)
        return arr.A[index];

    else
        printf("index out of range");
}

void set_value(Array *arr, int index, int value)
{
    if (index > 0 && index < arr->size)
    {
        arr->A[index] = value;
        printf("\nvalue inseted sucessfully\n");
        if (index >= arr->length)
            arr->length++;
    }
    else
        printf("\nunable to insert value\n");
}

int max(Array arr)
{
    int mx = arr.A[0];
    for (int i = 1; i < arr.length; i++)
        if (arr.A[i] > mx)
            mx = arr.A[i];

    return mx;
}
void display(Array arr)
{
    printf("\nthe array is : \n");
    for (int i = 0; i < arr.length; i++)
        printf(" %d ", arr.A[i]);
    printf("\n");
}

int min(Array arr)
{
    int mn = arr.A[0];
    for (int i = 1; i < arr.length; i++)
        if (mn > arr.A[i])
            mn = arr.A[i];

    return mn;
}

int sum(Array arr)
{
    int total = 0;
    for (int i = 0; i < arr.length; i++)
        total += arr.A[i];

    return total;
}

float Avg(Array arr)
{
    float total = sum(arr);
    float avg = total / arr.length;

    return avg;
}

void left_shift(Array *arr)
{
    for (int i = 0; i < arr->length - 1; i++)
        arr->A[i] = arr->A[i + 1];
    arr->length--;
}

void right_shift(Array *arr)
{
    for (int i = arr->length; i >= 0; i--)
        arr->A[i] = arr->A[i - 1];

    // arr->A[0] = 0;
    arr->length++;
}

void Reverse(Array *arr)
{
    // int i = 0, j = arr->length - 1;

    for (int i = 0, j = arr->length - 1; i < j; i++, j--)
    {
        // arr->A[i] = arr->A[j];
        swap(&arr->A[i], &arr->A[j]);
    }
}

int isSorted(Array arr)
{
    // int i = 0;
    for (int i = 0; i < arr.length; i++)
        if (arr.A[i] > arr.A[i + 1])
            return 0;

    return 1;
}

int get_index(Array arr, int value)
{
    for (int i = 0; i < arr.length; i++)
        if (arr.A[i] == value)
            return i;
    return -1;
}

void Rotation(Array *arr)
{
    int Zero_th = arr->A[0];
    left_shift(arr);
    arr->A[arr->length] = Zero_th;
    arr->length++;
}

void insert(Array *arr, int value)
{
    int i = arr->length;
    for (i; i >= 0; i--)

        if (value < arr->A[i])
        {
            arr->A[i + 1] = arr->A[i];
            arr->A[i] = value;
        }
    arr->length++;
}

void neg_Left(Array *arr)
{
    int i = 0;

    while (i < arr->length - 1)
    {
        int j = i + 1;
        while (j < arr->length)
        {
            if (arr->A[i] > arr->A[j])
                swap(&arr->A[i], &arr->A[j]);

            j++;
        }
        i++;
    }
}

Array *Merge(Array ar1, Array ar2)
{
    // Array *ar3 = (Array *)malloc(sizeof(Array));
    int size = (ar1.size + ar2.size) - 1;
    // Array *ar3;
    // ar3 =
    Array ar3 = {{1, 2, 3, 4, 4}, 1, size};

    int i = 0, j = 0, k = 0;
    while (i < ar1.length)
    {
        if (ar1.A[i] < ar2.A[j])
        {
            ar3.A[k] = ar1.A[i];
            i++;
            k++;
        }
        else if (ar1.A[i] > ar2.A[j])
        {
            ar3.A[k] = ar2.A[j];
            k++;
            j++;
        }

        else
        {
            ar3.A[k] = ar1.A[i];
            i++;
            j++;
            k++;
        }
    }

    ar3.length = k;

    Array *nm;
    nm = &ar3;
    return nm;
}

int main()
{
    system("cls");
    system("color a");

    Array arr = {{1, 2, 4, 15, 7, 8}, 10, 6};
    display(arr);

    printf("\nthe value at 4th index is: %d\n", get_value(arr, 4));

    set_value(&arr, 6, 50);
    printf("array after setting value at 6th pos 50 :\n");
    display(arr);

    printf("\nthe max in array is : %d \n", max(arr));
    printf("\nthe min in array is : %d \n", min(arr));
    printf("\nthe sum  of array is : %d \n", sum(arr));
    printf("\nthe Avg of array is : %.2f \n", Avg(arr));

    printf("\nafter left shifing array:\n");
    left_shift(&arr);
    display(arr);

    printf("\nafter right shifing array:\n");
    right_shift(&arr);
    display(arr);

    printf("\nReversion of array:\n");
    Reverse(&arr);
    display(arr);

    Reverse(&arr);
    display(arr);
    printf("\nis Array sorted: %d \n", isSorted(arr));

    printf("\nreplacing 15 with 6 using set_value and get_index func:");
    set_value(&arr, get_index(arr, 15), 6);
    display(arr);

    Rotation(&arr);
    printf("after rotation of array(left rotation)");
    display(arr);

    insert(&arr, 5);
    printf("\narray after insertion of 5\n");
    display(arr);

    Array arr_neg = {{1, -2, 4, -15, 7, 8}, 10, 6};
    printf("starting array look like this: \n");
    display(arr_neg);

    printf("after moving negative towards left\n");
    neg_Left(&arr_neg);

    display(arr_neg);

    Array mAr1 = {{1, 3, 5, 9}, 4, 5};
    Array mAr2 = {{2, 8, 10}, 4, 5};

    // system("cls");
    display(mAr1);
    display(mAr2);

    Array *Merged_Array;
    Merged_Array = Merge(mAr1, mAr2);

    display(*Merged_Array);

    printf("\n\n");

    return 0;
}