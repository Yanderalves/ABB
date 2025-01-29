#include <stdio.h>
#include "lib.h"

int main()
{
    Node *root = NULL;

    insertABB(4, &root);
    insertABB(8, &root);
    insertABB(7, &root);
    insertABB(9, &root);
    insertABB(57, &root);
    insertABB(25, &root);
    insertABB(78, &root);

    print(root);

    int heigth = calc_heigth(root);

    printf("\nHeigth: %d\n", heigth);
}
