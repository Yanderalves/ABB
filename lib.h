#ifndef ARQUIVO_H
#define ARQUIVO_H

typedef struct Node
{
    int key;
    struct Node *esq;
    struct Node *dir;
    int heigth;
} Node;

int searchABB(int x, Node **pt, int *f);
void insertABB(int x, Node **root);
void print(Node *root);
void visit(Node *no);
void calc_heigth(Node *no);
void remove_node(int x, Node **root);
#endif
