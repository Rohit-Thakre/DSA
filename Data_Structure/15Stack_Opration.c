#include <stdio.h>
#include <stdlib.h>

// 1.  parenthesis matching

struct stk
{
    int top;
    int size;
    char *array;
};

typedef struct stk stack;

void create(stack *s)
{
    printf("Enter the size of stack: ");
    scanf("%d", &s->size);

    s->top = -1;
    s->array = (char *)malloc(sizeof(int) * s->size);
}

void push(stack *s, char value)
{
    if (s->top >= s->size - 1)
        printf("stack overflow.\n");

    else
    {
        s->top++;
        s->array[s->top] = value;
    }
}

int pop(stack *s)
{
    if (s->top < 0)
    {
        printf("stack underflow.\n");
        return -1;
    }

    else
    {
        int x = s->array[s->top];
        s->top--;
        return x;
    }
}

int isEmpty(stack s)
{
    if (s.top < 0)
        return 1;
    else
        return 0;
}

int isBalanced(stack *s, char arg[])
{
    int i = 0;
    for (i; arg[i] != '\0'; i++)
    {
        if (arg[i] == '(')
            push(s, '(');

        else if (arg[i] == ')')
            if (s->top >= 0)
                pop(s);
            else
                return 0;
    }

    if (s->top < 0)
        return 1; // true

    else
        return 0; // false
}

int main()
{
    system("cls");
    system("color a");
    stack s;
    create(&s);
    char test[] = "(a+b) * (x*y)";
    printf("isBalanced : %d", isBalanced(&s, test));
}