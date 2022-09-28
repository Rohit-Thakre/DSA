#include <stdlib.h>
#include <stdio.h>

struct tree_node
{
    struct tnode *left;
    int data;
    struct tnode *right;
};

typedef struct tree_node tnode;

tnode *rInsert(tnode *root, int key)
{
    tnode *t;
    if (root == NULL)
    {
        t = malloc(sizeof(tnode));
        t->data = key;
        t->left = t->right = NULL;
        return t;
    }

    if (key < root->data)
        root->left = rInsert(root->left, key);

    else if (key > root->data)
        root->right = rInsert(root->right, key);

    // return t;
}

// [root, left ,right]
void display_pre(tnode *root)
{
    if (root)
    {
        printf("%d\n", root->data);
        display_pre(root->left);
        display_pre(root->right);
    }
}

tnode *rsearch(tnode *root, int key)
{
    if (root == NULL)
        return NULL;

    if (key == root->data)
        return root;

    if (key > root->data)
        return rsearch(root->right, key);

    if (key < root->data)
        return rsearch(root->left, key);
}

int main()
{
    system("color a");
    system("cls");
    // printf("hello world");

    tnode *root = NULL;

    root = rInsert(root, 30);
    rInsert(root, 20);
    rInsert(root, 10);
    rInsert(root, 40);
    rInsert(root, 50);

    tnode *search = rsearch(root, 50);
    if (search)
        printf("search was successfull.value at: %a\n", search);

    display_pre(root);
}