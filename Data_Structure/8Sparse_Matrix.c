#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct element
{
    int i, j, value;
};

struct sparse
{
    int m, n, num;

    struct element *elmt;
};

void create(struct sparse *s)
{
    int i = 0;
    printf("Enter the dimention of matrix: \n");
    scanf("%d %d", &s->m, &s->n);

    printf("Enter the no. of non zero element : \n ");
    scanf("%d", &s->num);

    s->elmt = (struct element *)malloc(s->n * sizeof(struct element));

    printf("Enter Non zero elements(row, col, element):\n");
    for (i = 0; i < s->num; i++)
    {
        scanf("%d%d%d", &s->elmt[i].i, &s->elmt[i].j, &s->elmt[i].value);
    }

    // getch();
}

void display(struct sparse s)
{
    int i, j, k = 0;

    printf("The sparse matrix is :\n\n");
    for (i = 0; i < s.m; i++)
    {
        for (j = 0; j < s.n; j++)
        {
            if (i == s.elmt[k].i && j == s.elmt[k].j)
                printf("%d ", s.elmt[k++].value);
            else
                printf("0 ");
        }
        printf("\n");
    }
}
struct Sparse *add(struct Sparse *s1, struct Sparse *s2)
{
    struct Sparse *sum;
    int i, j, k;
    i = j = k = 0;

    if (s1->n != s2->n && s1->m != s2->m)
        return NULL;
    sum = (struct Sparse *)malloc(sizeof(struct Sparse));
    sum->ele = (struct Element *)malloc((s1->num + s2->num) * sizeof(struct Element));
    while (i < s1->num && j < s2->num)
    {
        if (s1->ele[i].i < s2->ele[j].i)
            sum->ele[k++] = s1->ele[i++];
        else if (s1->ele[i].i > s2->ele[j].i)
            sum->ele[k++] = s2->ele[j++];
        else
        {
            if (s1->ele[i].j < s2->ele[j].j)
                sum->ele[k++] = s1->ele[i++];
            else if (s1->ele[i].j > s2->ele[j].j)
                sum->ele[k++] = s2->ele[j++];
            else
            {
                sum->ele[k] = s1->ele[i];
                sum->ele[k++].x = s1->ele[i++].x + s2->ele[j++].x;
            }
        }
    }
    for (; i < s1->num; i++)
        sum->ele[k++] = s1->ele[i];
    for (; j < s2->num; j++)
        sum->ele[k++] = s2->ele[j];
    sum->m = s1->m;
    sum->n = s1->n;
    sum->num = k;

    return sum;
}

int main()
{
    system("cls");
    system("color a");

    struct Sparse s1, s2, *s3;

    create(&s1);
    create(&s2);

    s3 = add(&s1, &s2);

    printf("First Matrix\n");
    display(s1);
    printf("Second Matrix\n");
    display(s2);
    printf("Sum Matrix\n");
    display(*s3);

    return 0;
}