#include <stdio.h>
#include <stdlib.h>

// LIFO

struct stk
{
    int top;
    int size;
    int *p;
};

typedef struct stk stack;

void create(stack *s)
{
    printf("Enter the size of stack: ");
    scanf("%d", &s->size);

    s->top = -1;
    s->p = (int *)malloc(sizeof(int) * s->size);
}

void push(stack *s, int value)
{
    if (s->top >= s->size - 1)
        printf("stack overflow.\n");

    else
    {
        s->top++;
        s->p[s->top] = value;
    }
}

int pop(stack *s)
{
    if (s->top <= 0)
    {
        printf("stack underflow.\n");
        return -1;
    }

    else
    {
        int x = s->p[s->top];
        s->top--;
        return x;
    }
}

void display(stack s)
{
    int i = s.top;
    printf("display : ");
    while (i >= 0)
    {
        printf("%d ", s.p[i]);
        i--;
    }
    printf("\n");
}

int peak(stack s, int pos)
{

    if (pos > 0 && pos <= s.top)
        return s.p[s.top - pos + 1];

    else
        return -1;
}

int topElmt(stack s)
{
    return s.p[s.top];
}

int isEmpty(stack s)
{
    if (s.top < 0)
        return 1;
    else
        return 0;
}

int isFull(stack s)
{
    if (s.top >= s.size - 1)
        return 1;
    else
        return 0;
}
int main()
{
    system("cls");
    system("color a");
    stack *s;

    create(s);
    // push(s, 10);
    // push(s, 20);
    // push(s, 30);
    // push(s, 40);
    // printf("deleted element: %d\n", pop(s));
    // push(s, 50);

    // display(*s);

    // printf("peak value : %d\n", peak(*s, 2));

    // printf("isFull : %d \n", isFull(*s));
    // printf("isEmpty : %d \n", isEmpty(*s));

    // printf("Top value : %d \n", topElmt(*s));

    int i = 1;
    int choice = 0;
    int data;

    while (i)
    {
        printf("\n\n1.push\n");
        printf("2.pop\n");
        printf("3.display\n");
        printf("4.peak\n");
        printf("5.top_ element.\n");
        printf("6.isEmpty\n");
        printf("7.isFull.\n");
        printf("8.Exit.\n");

        printf("Please Enter your option. : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the value you want to push in stack :");
            scanf("%d", &data);
            push(s, data);
            break;

        case 2:
            printf("%d is poped from stack.\n\n", pop(s));
            break;

        case 3:
            display(*s);
            break;

        case 4:
            printf("at which position would you like to peak. ?\n");
            scanf("%d", &data);

            printf("peak value is : %d\n\n", peak(*s, data));
            break;

        case 5:
            printf("the top element is :%d\n\n", topElmt(*s));
            break;

        case 6:
            printf("is stack Empty : %d\n\n", isEmpty(*s));
            break;

        case 7:
            printf("is stack Full : %d\n\n", isFull(*s));
            break;

        case 8:
            exit(1);
            break;

        default:
            // i = 0;
            break;
        }
    }
}