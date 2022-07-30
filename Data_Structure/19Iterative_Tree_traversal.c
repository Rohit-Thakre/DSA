/* #include <stdlib.h>
#include <stdio.h>

struct tree_node
{
    struct node *left;
    int data;
    struct node *right;
} *root = NULL;

typedef struct tree_node tree_Node;

// -------------------------------------------------
// queue using linke list
struct node
{
    tree_Node *data;
    struct node *next;
} *front = NULL, *rear = NULL;

typedef struct node Node;

void enqueue(tree_Node *data)
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

tree_Node *dequeue()
{
    Node *t = front;
    // tree_Node *x;

    if (front == NULL)
        printf("\nsorry the queue is already empty.\n\n");

    else
    {
        // x = front->data;
        front = front->next;
        free(t);

        return t->data;
    }
    // return x;
}
// -----------------------------------------------------------
// stack using linked list
struct stack_node
{
    tree_Node *data;
    struct node *next;
} *top = NULL;

typedef struct node stack_Node;

void push(tree_Node *data)
{
    stack_Node *temp = (stack_Node *)malloc(sizeof(stack_Node));

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
    tree_Node *x = top->data;
    stack_Node *temp = top;

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

int isEmpty()
{
    if (top == NULL)
        return 1;
    else
        return 0;
}
// ---------------------------------------------------------------

void create_tree()
{
    int lans;
    int rans;
    int data;
    int next = 10;

    tree_Node *t = NULL;
    tree_Node *temp = malloc(sizeof(tree_Node));
    temp->left = temp->right = NULL;

    printf("Enter the data to be inserted.: ");
    scanf("%d", &data);

    temp->data = data;

    if (root == NULL)
        root = temp;

    enqueue(temp);

    while (next)
    {
        t = dequeue();

        printf("is left child of %d  : ", t->data);
        scanf("%d", &lans);
        if (lans)
        {
            temp = malloc(sizeof(tree_Node));
            temp->left = temp->right = NULL;
            // printf("Enter the data to be inserted. :");
            // scanf("%d", &data);
            temp->data = lans;
            enqueue(temp);
            t->left = temp;
        }

        printf("is right child of %d : ", t->data);
        scanf("%d", &rans);
        if (rans)
        {
            temp = malloc(sizeof(tree_Node));
            temp->left = temp->right = NULL;
            // printf("Enter the data to be inserted. :");
            // scanf("%d", &data);
            temp->data = rans;
            enqueue(temp);
            t->right = temp;
        }

        printf("is there any next node left? ");
        scanf("%d", &next);
        if (next == 0)
            break;
    }
}

void display_pre()
{
    tree_Node *t = root;

    while (t || !isEmpty())
    {
        if (t)
        {
            printf("%d ", t->data);
            push(t);
            t = t->left;
        }
        else
        {
            t = pop();
            t = t->right;
        }
    }
}

int main()
{
    system("cls");
    system("color a");

    create_tree();
    // display_pre(root);

    return 0;
} */

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

    printf("Enter the data to be inserted in root node.: ");
    scanf("%d", &data);

    temp->data = data;

    if (root == NULL)
        root = temp;

    enqueue(q, temp);

    while (next)
    {
        t = dequeue(q);

        printf("is left child %d of : ", t->data);
        scanf("%d", &lans);
        if (lans)
        {
            temp = malloc(sizeof(Node));
            temp->left = temp->right = NULL;
            // printf("Enter the data to be inserted. :");
            // scanf("%d", &data);
            temp->data = lans;
            enqueue(q, temp);
            t->left = temp;
        }

        printf("is right child %d of : ", t->data);
        scanf("%d", &rans);
        if (rans)
        {
            temp = malloc(sizeof(Node));
            temp->left = temp->right = NULL;
            // printf("Enter the data to be inserted. :");
            // scanf("%d", &data);
            temp->data = rans;
            enqueue(q, temp);
            t->right = temp;
        }

        printf("is there any next node left? ");
        scanf("%d", &next);
        if (next == 0)
            break;
    }
}

// -------------------------------------------------
// stack
struct snode
{
    Node *data;
    struct node *next;
} *top = NULL;

typedef struct snode sNode;

void push(Node *data)
{
    sNode *temp = (sNode *)malloc(sizeof(sNode));

    if (temp == NULL)
        printf("stack overflow.\n");
    else
    {
        temp->data = data;
        temp->next = top;
        top = temp;
    }
}

Node *pop()
{
    Node *x = top->data;
    sNode *temp = top;

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
int isEmpty()
{
    if (top == NULL)
        return 1;
    else
        return 0;
}
// -------------------------------------------------

void preorder()
{
    Node *t = root;

    while (t || !isEmpty())
    {
        if (t)
        {
            printf("%d ", t->data);
            push(t);
            t = t->left;
        }

        else
        {
            t = pop();
            t = t->right;
        }
    }
}

// --------------------------------------------

void inorder()
{
    Node *t = root;

    while (t || !isEmpty())
    {
        if (t)
        {
            push(t);
            t = t->left;
        }

        else
        {
            t = pop();
            printf("%d ", t->data);
            t = t->right;
        }
    }
}
// -----------------------------------
int main()
{
    system("cls");
    system("color a");

    Queue *q = createq();
    create(q);

    printf("\npreorder :::\n");
    preorder();

    printf("\n\ninorder :::\n");
    inorder();
}