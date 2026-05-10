#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#include <ctype.h>
#include <string.h>

struct Elem
{
    double valoare;
    double randament;
    struct Elem *next;
};

typedef struct Elem Node;

typedef struct StockList
{
    char symbol[5];
    struct StockList *next;
} StockList;

typedef struct TreeNode
{
    StockList *stocks;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

void adaugare_inceput(Node **head, double v);
void adaugare_final(Node **head, double v);
void calculeaza_Rt(Node *head);
double calculeaza_Rm(Node *head, int n);
double calculeaza_Volatilitatea(Node *head, int n, double Rm);
void afisare_trunchiata(FILE *f, double val);
void free_list(Node *head);
int isEmpty(const Node *top);
double pop(Node **top);
void adauga_in_lista_final(StockList **head, char *nume);
TreeNode *oglindit(TreeNode *root, double preturi[][10], int col, int nr_zile);