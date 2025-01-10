#include <stdio.h>
#include "lib.h"
#include <stdlib.h>

int main()
{
    Node *root = malloc(sizeof(Node));
    root->esq = NULL;
    root->dir = NULL;
    root->key = 80;
    insertABB(78, &root);
    insertABB(9, &root);
    insertABB(87, &root);
    insertABB(2, &root);
    insertABB(82, &root);
    insertABB(3, &root);
    print(root);
}
