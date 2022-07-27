#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
typedef struct node Node;

Node *create(int data)
{
    Node *head = (Node *)malloc(sizeof(Node));
    head->data = data;
    head->next = NULL;
    return head;
}

void add_lst(Node *head, int data)
{
    Node *temp = create(data);

    while (head->next != NULL)
        head = head->next;

    head->next = temp;
}

Node *merge(Node *a, Node *b)
{
    Node *first = NULL, *last = NULL;

    if (a->data < b->data)
    {
        first = a;
        last = a;
        a = a->next;
        last->next = NULL;
    }
    else if (a->data > b->data)
    {
        first = b;
        last = b;
        b = b->next;
        last->next = NULL;
    }
    while (a && b)
    {
        if (a->data < b->data)
        {
            last->next = a;
            last = a;
            a = a->next;
            last->next = NULL;
        }
        else if (a->data > b->data)
        {
            last->next = b;
            last = b;
            b = b->next;
            last->next = NULL;
        }
    }

    if (a)
        last->next = a;
    if (b)
        last->next = b;

    return first;
}

void display(Node *head)
{
    Node *temp = head;
    while (temp)
    {
        printf(" %d ", temp->data);
        temp = temp->next;
    }
}
int main()
{
    system("cls");
    system("color a");

    Node *fst = create(0);
    add_lst(fst, 3);
    add_lst(fst, 5);
    add_lst(fst, 7);
    printf("fst:\n");
    display(fst);

    Node *snd = create(2);
    add_lst(snd, 4);
    add_lst(snd, 6);
    add_lst(snd, 8);
    printf("\nsnd:\n");
    display(snd);

    Node *mrg = NULL;
    mrg = merge(fst, snd);
    printf("\nmerge:\n");
    display(mrg);

    return 0;
}
