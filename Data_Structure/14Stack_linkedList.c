#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
} *top = NULL;

typedef struct node Node;

void push(int data)
{
    Node *temp = (Node *)malloc(sizeof(Node));

    if (temp == NULL)
        printf("stack overflow.\n");
    else
    {
        temp->data = data;
        temp->next = top;
        top = temp;
    }
}

int pop()
{
    int x = top->data;
    Node *temp = top;

    if (top == NULL)
    {
        printf("stack underflow.\n");
        return -1;
    }

    else
    {
        top = top->next;
        free(temp);
        temp = NULL;
    }

    return x;
}

void display()
{
    while (top != NULL)
    {
        printf("%d ", top->data);
        top = top->next;
    }

    printf("\n");
}

int peak(int pos)
{
    if (pos > 0)
    {
        int i = 1;
        Node *temp = top;

        for (i; i != pos; i++)
            temp = temp->next;

        return temp->data;
    }

    else
        printf("index is out of range.\n");
}

int isFull()
{
    if (top == NULL)
        return 1;
    else
        return 0;
}

int isEmpty()
{
    if (top == NULL)
        return 1;
    else
        return 0;
}

int top_element()
{
    if (top == NULL)
        return -1;
    else
        return top->data;
}
int main()
{
    system("cls");
    system("color a");

    // push(1);
    // push(2);
    // push(3);
    // push(4);
    // printf("poped element : %d \n", pop());
    // push(5);
    // push(6);
    // push(7);

    // // pop();

    // printf("peak(5): %d \n", peak(5));

    // display();

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
            push(data);
            break;

        case 2:
            printf("%d is poped from stack.\n\n", pop());
            break;

        case 3:
            display();
            break;

        case 4:
            printf("at which position would you like to peak. ? :  ");
            scanf("%d", &data);

            printf("peak value is : %d\n\n", peak(data));
            break;

        case 5:
            printf("the top element is :%d\n\n", top_element());
            break;

        case 6:
            printf("is stack Empty : %d\n\n", isEmpty());
            break;

        case 7:
            printf("is stack Full : %d\n\n", isFull());
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