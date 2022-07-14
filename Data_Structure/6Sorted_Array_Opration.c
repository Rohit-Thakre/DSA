#include <stdio.h>

void find_mis_elmt(int array[], int size)
{
    int sum = size * (size + 1) / 2;
    int ar_sum = 0;

    for (int i = 0; i < size - 1; i++)
        ar_sum = ar_sum + array[i];

    printf("the missing element is :%d\n", sum - ar_sum);
}

void fnd_mul_mis_elmnt(int array[], int size)
{
        int diff = array[0] - 0;

    for (int i = 0; i < size; i++)
    {
        if (array[i] - i != diff)
        {
            printf("%d is missing element.\n", array[i] - 1);
            diff = array[i] - i;
        }
        // printf("diff is : %d\n", diff);
    }
}

void fnd_duplicated(int array[], int size)
{
    int lst_duplicat = 0;

    for (int i = 0; i < size; i++)
    {
        if (array[i] == array[i + 1] && array[i] != lst_duplicat)
        {
            printf("%d is duplicated.\n", array[i]);
            lst_duplicat = array[i];
        }
    }
}

void count_duplicates(int array[], int size)
{
    int count = 0, i = 0;

    // for (int i = 0; i < size; i++)
    while (i < size)
    {
        if (array[i] == array[i + 1])
        {
            count += 1;
            while (array[count] == array[i])
                count++;
            printf("%d appeared %d times.\n", array[i], count);
            i = count - 1;
        }
        i++;
    }
}
int main()
{
    system("cls");
    system("color a");

    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 10};
    int size = 9;

    find_mis_elmt(array, size);
    int array1[] = {1, 2, 3, 5, 6, 7, 8, 10};
    int size1 = 8;

    printf("\n\narray 1 (find multiple missing element):\n");
    fnd_mul_mis_elmnt(array1, size1);

    int array2[] = {1, 2, 3, 3, 4, 5, 6, 7, 7, 8, 9};
    int size2 = 11;
    printf("\n\nfind duplicate in sorted array:\n");
    fnd_duplicated(array2, size2);
    count_duplicates(array2, size2);

    return 0;
}