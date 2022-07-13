#include <stdio.h>
#include <stdlib.h>

struct arr
{
    int a[10];
    int size;
    int length;
};

typedef struct arr Array;

void display(Array array)
{
    for (int i = 0; i < array.length; i++)
        printf("%d\t", array.a[i]);
    printf("\n\n");
}

void insert(Array *array, int index, int value)
{
    index--;
    if (index >= 0 && index <= array->size)
    {
        int i = array->length;

        for (i = array->length; index != i; i--)
        {
            array->a[i] = array->a[i - 1];
        }
        array->a[index] = value;
        array->length++;
    }
}

void append(Array *array, int value)
{
    if (array->length < array->size)
    {
        array->a[array->length] = value;
        array->length++;
    }
}

int del(Array *array, int index)
{
    index--;
    if (index >= 0 && index <= array->length)
    {
        int x = array->a[index];
        for (int i = index; i < array->length - 1; i++)
            array->a[i] = array->a[i + 1];
        array->length--;
        return x;
    }
    return 0;
}

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
int LinearSearch(Array *array, int key)
{
    for (int i = 0; i < array->length; i++)
    {
        if (array->a[i] == key)
        {
            // LinearSearch optimazation
            // 1.transpose (one position closer to 0th index so that when same element is searched it will found one step closer)
            // swap(&array->a[i], &array->a[i - 1]);

            // 2.move to head/ top (directly move the searched element to index 0)
            swap(&array->a[i], &array->a[0]);
            return i;
        }
    }
    return -1;
}
int main()
{
    system("cls");
    system("color a");

    Array array = {{1, 2, 3, 4, 5}, 10, 5};
    printf("origional array \n");
    display(array);

    insert(&array, 4, 50);
    printf("after insertion of 50\n");
    display(array);

    append(&array, 20);
    printf("after  append of 20\n");
    display(array);

    // int x = del(&array, 3);
    printf("after deletion of 3rd position's element:  %d\n", del(&array, 3));
    display(array);

    printf("the seatch  element is 5 :\n", LinearSearch(&array, 5));
    printf("after Linear search move to head method\n");
    display(array);
}
