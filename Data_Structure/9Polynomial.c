#include <stdio.h>
#include <stdlib.h>

struct element
{
    int exp;
    int coi;
    // int value;
};

struct polynomial
{
    int size;
    struct element *elmt;
};

void create(struct polynomial *p)
{
    printf("enter the no. of terms in polynomial equation.\n");
    scanf("%d", &p->size);
    p->elmt = (struct element *)malloc(p->size * sizeof(struct element));

    printf("enter exp and coificient(exp , coi)\n");
    for (int i = 0; i < p->size; i++)
        scanf("%d%d", &p->elmt[i].exp, &p->elmt[i].coi);
}

void display(struct polynomial p)
{

    printf("exp     |     coi\n");
    for (int i = 0; i < p.size; i++)
    {
        printf("%d      |       %d\n", p.elmt[i].exp, p.elmt[i].coi);
    }
}

struct polynomial *add(struct polynomial p1, struct polynomial p2)
{
    int i, j, k;
    i = j = k = 0;
    struct polynomial *sum = (struct polynomial *)malloc(sizeof(struct polynomial));

    sum->elmt = (struct element *)malloc((p1.size + p2.size) * sizeof(struct element));

    while (i < p1.size && j < p2.size)
    {
        if (p1.elmt[i].exp > p2.elmt[i].exp)
            sum->elmt[k++] = p1.elmt[i++];

        else if (p1.elmt[i].exp < p2.elmt[i].exp)
            sum->elmt[k++] = p2.elmt[j++];

        else
        {
            sum->elmt[k++].exp = p1.elmt[i++].exp;
            sum->elmt[k++].coi = (p1.elmt[i++].coi + p2.elmt[j++].coi);
        }
    }

    return sum;
}
int main()
{
    system("cls");
    system("color a");
    struct polynomial p1, p2, *p3;
    printf("1st polynomial\n");
    create(&p1);

    display(p1);

    printf("2nd polynomial\n");
    create(&p2);

    display(p2);

    // p3 = add(p1, p2);

    // printf("sum is :\n");
    // display(*p3);

    // display(p1);
    return 0;
}
