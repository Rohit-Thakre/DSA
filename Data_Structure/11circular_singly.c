#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
} * head;
typedef struct node Node;
// Node head;

void create(int a[], int size)
{
    Node *temp = NULL, *last = NULL;

    head = (Node *)malloc(sizeof(Node));

    head->data = a[0];
    head->next = head;
    last = head;

    for (int i = 1; i < size; i++)
    {
        temp = (Node *)malloc(sizeof(Node));
        temp->data = a[i];
        temp->next = last->next;
        last->next = temp;
        last = temp;
    }
}
Node *create2(int a[], int size)
{
    Node *temp = NULL, *last = NULL, *t = NULL;

    t = (Node *)malloc(sizeof(Node));

    t->data = a[0];
    t->next = t;
    last = t;

    for (int i = 1; i < size; i++)
    {
        temp = (Node *)malloc(sizeof(Node));
        temp->data = a[i];
        temp->next = last->next;
        last->next = temp;
        last = temp;
    }

    return t;
}

// void create(i
void display(Node *head)
{
    Node *temp = head;

    printf("%d ", temp->data);
    temp = head->next;

    while (head != temp)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

void Rdisplay(Node *h)
{
    static int flag = 0;
    if (flag = 0 || h != head)
    {
        printf(" %d ", h->data);
        Rdisplay(h->next);
    }
}

int len()
{
    int i = 1;
    Node *temp = head;
    temp = temp->next;
    while (temp != head)
    {
        temp = temp->next;
        i++;
    }

    return i;
}

void insert_at_fst(int data)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = data;

    if (head == NULL)
    {
        head = temp;
        head->next = head;
    }

    else
    {
        Node *last = head->next;
        while (last->next != head)
            last = last->next;

        last->next = temp;
        temp->next = head;
        head = temp;
    }
}

void insert(int data, int pos)
{
    if (pos >= 0 && pos <= len())
    {
        Node *temp = (Node *)malloc(sizeof(Node));
        temp->data = data;

        if (head == NULL)
        {
            head = temp;
            head->next = head;
        }

        else
        {
            if (pos == 0)
            {
                insert_at_fst(data);
                return;
            }

            else
            {
                Node *last = head->next;
                for (int i = 1; i < pos - 1; i++)
                    last = last->next;

                temp->next = last->next;
                last->next = temp;
            }
        }
    }
}

void del(int pos)
{
    Node *temp = head, *t;
    if (pos == 0)
    {
        while (temp->next != head)
            temp = temp->next;
        temp->next = head->next;
        free(head);
        head = temp->next;
    }
    else
    {
        int i = 0;
        while (i != pos - 1)
        {
            temp = temp->next;
            i++;
        }
        t = temp->next;
        temp->next = t->next;
        free(t);
        t = NULL;
    }
}

Node *concat(Node *a, Node *b)
{
    Node *lstA = a, *lstB = b;

    while (lstA->next != a)
        lstA = lstA->next;

    while (lstB->next != b)
        lstB = lstB->next;

    lstA->next = b;
    lstB->next = a;

    return a;
}

/*
Node *Merge(Node *A, Node *B)
{
    Node *first = NULL, *last = NULL, *a = A, *b = B;

    if (a->data < b->data)
    {
        first = a;
        last = a;
        a = a->next;
        last->next = first;
    }
    else if (a->data > b->data)
    {
        first = b;
        last = b;
        b = b->next;
        last->next = first;
    }
    while (a->next != A && b->next != B)
    {
        if (a->data < b->data)
        {
            last->next = a;
            last = a;
            a = a->next;
            last->next = first;
        }
        else if (a->data > b->data)
        {
            last->next = b;
            last = b;
            b = b->next;
            last->next = first;
        }
    }

    if (a->next == A)
    {
        while (b->next != B)
        {
            // last->next = b;
            b = b->next;
            // last->next = merged;
            last = b;
            last->next = first;
        }
    }
    else if (b->next == B)
    {
        while (a->next != A)
        {
            // last->next = a;
            a = a->next;
            // last->next = merged;
            last = a;
            last->next = first;
        }
    }

    return first;
} */
int main()
{
    system("cls");
    system("color a");

    int A[] = {3, 4, 5, 6, 7};
    int size = 5;

    create(A, size);
    printf("create: \n");
    display(head);

    printf("\n\ninsert at first (2): \n");
    insert_at_fst(2);
    display(head);

    printf("\n\ninsert at any pos at 0the position (1)\n");
    insert(1, 0);
    display(head);

    printf("\n\ninsert at 7th position(8)\n");
    insert(8, 7);
    // insert(150, 7);
    display(head);

    printf("\n\nlen of circular singly link list is : %d \n", len());

    printf("\n\ndelete pos 5th  \n");
    del(4);
    display(head);

    printf("\n\ndelete 0th pos :\n");
    del(0);
    display(head);

    return 0;
}