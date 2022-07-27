#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};

typedef struct node Node;

Node *create(int data)
{
    Node *head = (Node *)malloc(sizeof(Node));
    head->data = data;
    head->link = NULL;
    return head;
}

void add_lst(Node *head, int data)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = data;
    temp->link = NULL;

    while (head->link != NULL)
        head = head->link;

    head->link = temp;
}

Node *add_fst(Node *head, int data)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = data;
    temp->link = head;
    head = temp;
    return head;
}

void display(Node *head)
{
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->link;
    }
    printf("\n");
}

void Rdisplay(Node *head)
{
    if (head != NULL)
    {
        printf("%d ", head->data);
        Rdisplay(head->link);
    }
}

int count_node(Node *head)
{
    int count = 0;
    while (head != NULL)
    {
        head = head->link;
        count++;
    }

    return count;
}

int sum(Node *head)
{
    int sum = 0;
    while (head != NULL)
    {
        sum += head->data;
        head = head->link;
    }
    return sum;
}

void min_max(Node *head)
{
    int min = 0, max = 0;
    while (head != NULL)
    {
        if (head->data <= min)
            min = head->data;

        else
            max = head->data;

        head = head->link;
    }
    printf("min : %d   \nMax : %d\n", min, max);
}

void search(Node *head, int fnd)
{
    int count = 1;
    int data;
    while (head != NULL)
    {
        // data = head->data;

        if (fnd == head->data)
        {
            printf("the search  for %d was successfull.\n the element found at %d node.\n", fnd, count);
            break;
        }
        count++;
        head = head->link;
    }

    // if (fnd != head->data)
    printf("the search of %d was unsuccessfull.\n", fnd);
}

// improve search
// 1.transpose
// 2.move to head.

Node *Move_to_head(Node *head, int search)
{
    Node *t = NULL, *temp = head;

    while (temp->data != search)
    {
        t = temp;
        temp = temp->link;
    }
    t->link = temp->link;
    // t = temp->link;
    temp->link = head;
    head = temp;
    return head;
}

Node *del(Node *head, int pos)
{
    int ps = pos;
    pos--;
    Node *temp = head, *t = NULL;
    while (pos)
    {

        t = temp;
        temp = temp->link;
        pos--;
    }

    t->link = temp->link;

    // if (temp == NULL)
    printf("\n%d pos node containing value %d deleted succufully\n", ps, temp->data);
    free(temp);
    return head;
}

Node *reverse(Node *head)
{
    Node *pre = NULL, *mid = NULL, *cur = head;
    while (cur != NULL)
    {
        if (cur != NULL)
        {
            pre = mid;
            mid = cur;
            cur = cur->link;
            mid->link = pre;
        }
        else
        {
            head = mid;
            return head;
        }
    }
}

void insert(Node *head, int pos, int data)
{
    Node *t = (Node *)malloc(sizeof(Node));
    t->data = data;

    if (pos == 0)
    {
        t->link = head;
        head = t;
        return head;
    }
    else if (pos > 0)
    {
        pos -= 2;
        Node *t1 = head;

        while (pos)
        {
            // t = t1;
            t1 = t1->link;
            pos--;

            if (t1 == NULL)
            {
                printf("index out of range.\n");
                break;
            }
        }
        t->link = t1->link;
        t1->link = t;
    }
}

void concat(Node *fst, Node *snd)
{
    while (fst->link)
        fst = fst->link;

    fst->link = snd;
    snd = NULL;
}

Node *merge(Node *a, Node *b)
{
    Node *first = NULL, *last = NULL;
    if (a->data < b->data)
    {
        first = a;
        last = a;
        a = a->link;
        last->link = NULL;
    }
    else if (a->data > b->data)
    {
        first = b;
        last = b;
        b = b->link;
        last->link = NULL;
    }

    while (a && b)
    {
        if (a->data < b->data)
        {
            last->link = a;
            last = a;
            a = a->link;
            last->link = NULL;
        }
        else if (a->data > b->data)
        {
            last->link = b;
            last = b;
            b = b->link;
            last->link = NULL;
        }
    }

    if (a)
        last->link = a;
    if (b)
        last->link = b;

    return first;
}
int main()
{
    system("cls");
    system("color a");

    // Node *head = create(10);
    // // head = add_fst(head,);
    // // add_lst(head, 50);
    // // add_lst(head, 80);
    // // add_lst(head, 90);

    // display(head);

    // Node *snd = create(1);
    // // add_lst(snd, 2);
    // // add_lst(snd, 3);
    // // add_lst(snd, 4);
    // // add_lst(snd, 5);
    // // display(snd);

    // // concat(head , snd);
    // // printf("after concat \n");

    // // Node *ptr = mergg(head, snd);

    // // head = merge(head, snd);

    // // display(head);

    int i = 1;
    int data, fnd, value, pos;
    while (i)
    {
        int choice = -1;
        if (i == 0)
            break;

        printf("which operation do you want to do with linked list.\n");
        printf("1.create linked first node list\n");
        printf("2.add node at first\n");
        printf("3.add node at last\n");
        printf("4.display linked list\n");
        printf("5.display linked list using recursion.\n");
        printf("6.count nodes.\n");
        printf("7.addition of all node values.\n");
        printf("8.print minmun and maximum values of linked list\n");
        printf("9.search specific value is present in link list or not\n");
        printf("10.move the element to the first place.\n");
        printf("11.delete node.\n");
        printf("12.reverse linked list.\n");
        printf("13.insert the node in linked list.\n");
        printf("14.concat the two linke list.\n");
        printf("15.merge two linked list.\n");
        printf("15.Exit.\n");

        printf("Enter the correct operation to be perfomed.\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            /* code */
            // int data = 0;

            printf("Enter the value which you want to be inserted in first node.\n");
            scanf("%d", &data);

            Node *head = create(data);
            break;

        case 2:
            // int data = 0;
            printf("Enter the value to be inseted in first node.\n");
            scanf("%d", &data);
            add_fst(head, data);
            break;

        case 3:
            // int data = 0;
            printf("Enter the value to be inseted in last node.\n");
            scanf("%d", &data);
            add_lst(head, data);
            break;

        case 4:
            printf("displaying using interation.\n");
            display(head);
            break;

        case 5:

            printf("displaying using recursion.\n");
            Rdisplay(head);
            break;

        case 6:
            printf("there are %d nodes in linked list.\n", count_node(head));
            break;

        case 7:
            printf("the sum of linked list values is : %d.\n", sum(head));
            break;

        case 8:
            min_max(head);
            break;

        case 9:
            // int fnd = -1;
            printf("which value do you wanted to be searched.\n Enter here: ");
            scanf("%d", &fnd);
            printf("\n");
            search(head, fnd);
            break;
        case 10:

            // int value = -1;
            printf("which value do you want be inseted first in the linked list\n");
            scanf("%d", &value);
            Move_to_head(head, value);
            break;

        case 11:
            printf("enter which postion node you want to be deleted.\n");
            // int pos = -1;
            scanf("%d", &pos);
            del(head, pos);
            break;

        case 12:
            printf("reversing linked list.\n");
            head = reverse(head);
            break;

        case 13:
            printf("Enter the data which you want to be inseted in node.\n");
            // int data = -1;
            scanf("%d", &data);

            printf("Enter the position at which you want be your node inserted.\n");
            // int pos = -1;
            scanf("%d", &pos);
            insert(head, pos, data);
            break;

        case 14:
            printf("currecntly unavailabe.\n");
            break;

        case 15:
            printf("currecntly unavailabe.\n");
            break;

        case 16:
            i = 0;
            break;

        default:
            break;
        }
    }
    return 0;
}