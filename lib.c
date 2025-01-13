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

void visit(Node *no)
{
    int ah1 = 0;
    int ah2 = 0;
    if (no->esq != NULL)
    {
        ah1 = no->esq->heigth;
    }
    else
    {
        ah1 = -1;
    }

    if (no->dir != NULL)
    {
        ah2 = no->dir->heigth;
    }
    else
    {
        ah2 = -1;
    }

    if (ah1 > ah2)
    {
        no->heigth = ah1 + 1;
    }
    else
    {
        no->heigth = ah2 + 1;
    }
}

void calc_heigth(Node *no)
{
    if (no->esq != NULL)
    {
        calc_heigth(no->esq);
    }
    if (no->dir != NULL)
    {
        calc_heigth(no->dir);
    }
    visit(no);
}

void remove_node(int x, Node **root)
{
    Node *pt = *root;
    int f = -1;
    searchABB(x, &pt, &f);
    if (f != 1)
        puts("Element not exists");
    else
    {
        if (pt->esq == NULL)
            pt = pt->dir;
        else if (pt->dir == NULL)
            pt = pt->esq;
        else
        {
            Node *s = pt->dir;
            if (s->dir != NULL)
            {
                Node *fatherS = s;
                while (s->dir != NULL)
                {
                    s = s->esq;
                }
                fatherS->esq = s->dir;
                s->dir = pt->dir;
            }
            s->esq = pt->esq;
            pt = s;
        }
    }
}