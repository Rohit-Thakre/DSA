#include <stdio.h>
#include <stdlib.h>

struct queue
{
    int size;
    int start;
    int end;
    int *array;
};

typedef struct queue Queue;

Queue *create()
{
    Queue *temp = malloc(sizeof(Queue));
    printf("\nEnter the size of Queue :  ");
    scanf("%d", &temp->size);
    // temp->size = 5;
    temp->start = 0;
    temp->end = 0;
    temp->array = malloc(sizeof(int) * temp->size);

    return temp;
}

void enqueue(Queue *q, int data)
{
    if (q->end < q->size)
        q->array[q->end++] = data;

    else
        printf("\n\nsorry the queue is full, value cannot be inseted.\n\n");
}

int dequeue(Queue *q)
{
    int x = -1;
    if (q->end > q->start)
    {
        x = q->array[q->start++];
        return x;
    }
    else
        printf("\n\nsorry the queue is already empty.\n\n");
}

int isEmpty(Queue q)
{
    if (q.start == q.end)
        return 1;
    else
        return 0;
}

void display(Queue q)
{
    printf("\n");
    while (q.start < q.end)
        printf("%d\n", q.array[q.start++]);
}

int peak(Queue q)
{
    return q.array[q.start];
}
int main()
{
    system("cls");
    system("color a");
    Queue *q = create();
    // // printf("isEmpty: %d\n", isEmpty(*q));
    // enqueue(q, 10);
    // enqueue(q, 20);
    // // printf("poped here :%d \n", dequeue(q));
    // // display(*q);
    // // printf("isEmpty: %d\n", isEmpty(*q));
    // printf("\npeak value is :%d \n\n", peak(*q));

    int i = 1;
    int choice;
    int data;
    while (i)
    {

        // printf("1.create queue.\n");
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

            printf("\nEnter the data which you want to be inserted.:\n");
            scanf("%d", &data);
            enqueue(q, data);
            break;

        case 2:
            data = dequeue(q);
            printf("\n%d is poped out from queue.\n", data);
            break;
        case 3:
            printf("\n\nisEmpty : %d\n\n", isEmpty(*q));
            break;

        case 4:
            display(*q);
            break;

        case 5:
            printf("\npeak value is :%d \n\n", peak(*q));
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