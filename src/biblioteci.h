#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

struct Elem
{
    double valoare;
    double randament;
    struct Elem *next;
};

typedef struct Elem Node;

void adaugare_inceput(Node **head, double v);
void adaugare_final(Node **head, double v);
void calculeaza_Rt(Node *head);
double calculeaza_Rm(Node *head, int n);
double calculeaza_Volatilitatea(Node *head, int n, double Rm);
void afisare_trunchiata(FILE *f, double val);
void free_list(Node *head);
int isEmpty(Node *top);
int pop(Node **top);