#include <stdio.h>
#include <stdlib.h>

struct tree_node
{
    struct tree_node *left;
    int data;
    struct tree_node *right;
};

typedef struct tree_node tnode;

tnode *insert(tnode *t, int key)
{
    tnode *r = NULL, *p;

    if (t == NULL)
    {
        p = malloc(sizeof(tnode));
        p->data = key;
        p->left = p->right = NULL;
        // return p;
        t = p;
        return t;
    }

    while (t)
    {
        r = t;
        if (key == t->data)
            return;
        else if (key < t->data)
        {
            t = t->left;
        }
        else
            t = t->right;
    }

    p = malloc(sizeof(tnode));
    p->data = key;
    p->left = p->right = NULL;

    if (p->data < r->data)
        r->left = p;
    else
        r->right = p;

    return t;
}

void display_pre(tnode *root)
{
    if (root)
    {
        printf("%d\n", root->data);
        display_pre(root->left);
        display_pre(root->right);
    }
}
void display_in(tnode *root)
{
    if (root)
    {
        display_in(root->left);
        printf("%d\n", root->data);
        display_in(root->right);
    }
}

tnode *isearch(tnode *root, int key)
{
    while (root)
    {
        if (root->data == key)
            return root;
        else if (root->data < key)
            root = root->right;

        else
            root = root->left;
    }
    // return root;
    return NULL;
}

int main()
{
    system("cls");
    system("color a");

    tnode *root = NULL;

    root = insert(root, 30);
    insert(root, 20);
    insert(root, 10);
    insert(root, 40);
    insert(root, 50);

    display_pre(root);

    // display_in(root);

    tnode *t = isearch(root, 50);
    // isearch(root, 50);
    if (t)
        printf("search was successfull.\nsearch value is :%d\n", t->data);
}