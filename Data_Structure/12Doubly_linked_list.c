#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *prev;
    int data;
    struct node *next;
};

typedef struct node Node;

Node *create(int A[], int size)
{
    Node *tpr, *tlst, *temp = malloc(sizeof(Node));

    temp->data = A[0];
    temp->next = temp->prev = NULL;
    tlst = temp;

    for (int i = 1; i < size; i++)
    {
        tpr = malloc(sizeof(Node));
        tpr->data = A[i];
        tpr->next = NULL;
        tpr->prev = tlst;
        tlst->next = tpr;
        tlst = tpr;
    }
    return temp;
}

void display(Node *head)
{
    while (head != NULL)
    {
        printf(" %d ", head->data);
        head = head->next;
    }

    printf("\n");
}

int len(Node *head)
{
    int count = 0;
    while (head != NULL)
    {
        head = head->next;
        count++;
    }
    return count;
}

Node *insert_fst(Node *head, int data)
{
    Node *temp = malloc(sizeof(Node));

    temp->prev = NULL;
    temp->data = data;

    head->prev = temp;
    temp->next = head;
    head = temp;
    return head;
}

Node *insert(Node *head, int data, int pos)
{
    if (pos >= 0 && pos < len(head))
    {
        if (pos == 0)
        {
            head = insert_fst(head, data);
            return head;
        }

        Node *ptr = head, *temp = malloc(sizeof(Node));
        temp->next = temp->prev = NULL;
        temp->data = data;

        int i = 0;
        while (i < pos)
        {
            ptr = ptr->next;
            i++;
        }

        temp->prev = ptr->prev;
        temp->next = ptr->next;
        ptr->prev->next = temp;
        ptr->next->prev = temp;

        return head;
    }
    else
        printf("index out of range");
}

void delete (Node *ptr, int pos)
{
    if (pos >= 0 && pos < len(ptr))
    {
        int i = 0;
        while (i < pos)
        {
            ptr = ptr->next;
            i++;
        }

        ptr->prev->next = ptr->next;
        ptr->next->prev = ptr->prev;
        free(ptr);
        ptr = NULL;
    }
}

void concat(Node *a, Node *b)
{
    int i = 0;
    while (a->next != NULL)
    {
        a = a->next;
        i++;
    }

    a->next = b;
    b->prev = a;
}

Node *Merge()
{
}
int main()
{
    system("cls");
    system("color a");

    Node *head;

    int a[] = {1, 2, 3, 4, 5, 6, 7};
    head = create(a, 7);
    display(head);

    printf("\n\ninsetring 55 at pos : 2\n");
    head = insert(head, 55, 2);
    display(head);

    printf("\n\ninsetring 11 at pos : 0\n");
    head = insert(head, 11, 0);
    display(head);

    printf("\n\ninserting 99 at first.\n");
    head = insert_fst(head, 99);
    display(head);

    printf("\n\ndeleting pos : 2\n");
    delete (head, 2);
    display(head);

    int t[] = {1, 3, 5, 7, 9};
    int t2[] = {1, 3, 5, 7, 9};
    Node *A = create(t, 5);
    Node *B = create(t2, 5);

    printf("\n\nA : ");
    display(A);
    printf("B : ");
    display(B);

    concat(A, B);

    printf("\nconcating A and B.\n");
    display(A);

    return 0;
}