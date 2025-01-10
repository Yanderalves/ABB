#include "lib.h"
#include <stdlib.h>
#include <stdio.h>

int searchABB(int x, Node **pt, int *f)
{
    if (pt == NULL)
        f = 0;
    else
    {
        if (x == (*pt)->key)
            *f = 1;
        else
        {
            if (x < (*pt)->key)
            {
                if ((*pt)->esq == NULL)
                    *f = 2;
                else
                {
                    (*pt) = (*pt)->esq;
                    searchABB(x, pt, f);
                }
            }
            else
            {
                if ((*pt)->dir == NULL)
                    *f = 3;
                else
                {
                    (*pt) = (*pt)->dir;
                    searchABB(x, pt, f);
                }
            }
        }
    }
}

void insertABB(int x, Node **root)
{
    Node *pt = *root;
    int f;
    searchABB(x, &pt, &f);
    if (f == 1)
    {
        puts("Elemento já existe");
        return;
    }
    else
    {
        Node *newNode = malloc(sizeof(Node));
        newNode->key = x;
        newNode->dir = newNode->esq = NULL;
        switch (f)
        {
        case 0:
            *root = newNode;
            break;
        case 2:
            pt->esq = newNode;
            break;
        case 3:
            pt->dir = newNode;
            break;
        }
    }
}

void print(Node *root)
{
    printf("%d ", root->key);
    if (root->esq != NULL)
        print(root->esq);
    if (root->dir != NULL)
        print(root->dir);
}