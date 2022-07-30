#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *left;
    int data;
    struct node *right;
} *root = NULL;

typedef struct node Node;

// -------------------------------------------------------------

// queue using array
struct queue
{
    int size;
    int start;
    int end;
    int *array;
};

typedef struct queue Queue;

Queue *createq()
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

void enqueue(Queue *q, Node *data)
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

// -----------------------------------------------------------

void create(Queue *q)
{
    int lans;
    int rans;
    int data;
    int next = 1;

    Node *t = NULL;
    Node *temp = malloc(sizeof(Node));
    temp->left = temp->right = NULL;

    printf("Enter the data to be inserted.: ");
    scanf("%d", &data);

    temp->data = data;

    if (root == NULL)
        root = temp;

    enqueue(q, temp);

    while (next)
    {
        t = dequeue(q);

        printf("is left child present ?: ");
        scanf("%d", &lans);
        if (lans)
        {
            temp = malloc(sizeof(Node));
            temp->left = temp->right = NULL;
            printf("Enter the data to be inserted. :");
            scanf("%d", &data);
            temp->data = data;
            enqueue(q, temp);
            t->left = temp;
        }

        printf("is right child present ?: ");
        scanf("%d", &rans);
        if (rans)
        {
            temp = malloc(sizeof(Node));
            temp->left = temp->right = NULL;
            printf("Enter the data to be inserted. :");
            scanf("%d", &data);
            temp->data = data;
            enqueue(q, temp);
            t->right = temp;
        }

        printf("is there any next node left? ");
        scanf("%d", &next);
        if (next == 0)
            break;
    }
}

// pre order [root, left , right]
void display_pre(Node *root)
{
    if (root)
    {
        printf("%d\n", root->data);
        display_pre(root->left);
        display_pre(root->right);
    }
}

// post order  [left ,  right , root];
void display_post(Node *root)
{
    if (root)
    {
        display_post(root->left);
        display_post(root->right);
        printf("%d\n", root->data);
    }
}

// in order [left , root ,right]
void display_in(Node *root)
{
    if (root)
    {
        display_in(root->left);
        printf("%d\n", root->data);
        display_in(root->right);
    }
}

int main()
{
    system("cls");
    system("color a");

    Queue *q = createq();
    create(q);

    printf("\npre order\n");
    display_pre(root);

    printf("\n\npost order.\n");
    display_post(root);

    printf("\n\nin order.\n");
    display_in(root);
}