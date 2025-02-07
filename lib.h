#ifndef ARQUIVO_H
#define ARQUIVO_H

typedef struct Node
{
    int key;
    struct Node *esq;
    struct Node *dir;
} Node;

int searchABB(int x, Node **pt, int *f);
void insertABB(int x, Node **root);
void print(Node *root);
void visit(Node *no);
int calc_heigth(Node *no);
void remove_node(int x, Node **root);
int max_number(int a, int b);
#endif
