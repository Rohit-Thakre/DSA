#include <stdlib.h>
#include <stdio.h>

struct node
{
    int data;
    struct node *next;
} *front = NULL, *rear = NULL;

typedef struct node Node;

void enqueue(int data)
{
    Node *t = malloc(sizeof(Node));
    t->next = NULL;
    t->data = data;

    if (front == NULL)
        front = rear = t;
    else
    {
        rear->next = t;
        rear = t;
    }
}

int dequeue()
{
    Node *t = front;
    int x = -1;

    if (front == NULL)
        printf("\nsorry the queue is already empty.\n\n");

    else
    {
        x = front->data;
        front = front->next;
        free(t);
        t = NULL;
    }
    return x;
}

int peak()
{
    if (front == NULL)
        return -1;
    else
        return front->data;
}

void display()
{
    if (front == NULL)
        printf("sorry there is no element in queue.\n");
    else
    {
        printf("\n");
        Node *t = front;
        while (t != NULL)
        {
            printf("%d\n", t->data);
            t = t->next;
        }
        printf("\n");
    }
}

int isEmpty()
{
    if (front == NULL)
        return 1;
    else
        return 0;
}

int main()
{
    system("cls");
    system("color a");

    int i = 1;
    int choice;
    int data;
    while (i)
    {

        printf("1.Enqueue.\n");
        printf("2.Dequeue queue.\n");
        printf("3.is queue empty?\n");
        printf("4.display.\n");
        printf("5.peak.\n");
        printf("6.exit.\n");

        printf("please Enter one of your operation do be done.: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:

            printf("\nEnter the data which you want to be inserted.: ");
            scanf("%d", &data);
            enqueue(data);
            break;

        case 2:
            printf("\n\npoped element : %d \n\n", dequeue());
            break;
        case 3:
            printf("\n\nisEmpty : %d\n\n", isEmpty());
            break;

        case 4:
            display();
            break;

        case 5:
            printf("\n\npeak value is : %d \n\n", peak());
            break;

        case 6:
            exit(1);
            break;
        default:
            i = 0;
            break;
        }
    }
}