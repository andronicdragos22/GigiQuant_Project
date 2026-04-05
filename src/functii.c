#include "biblioteci.h"

void adaugare_inceput(Node **head, double v)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->valoare = v;
    newNode->next = *head;
    *head = newNode;
}

void adaugare_final(Node **head, double v)
{
    Node *aux = *head;

    if (*head == NULL)
        adaugare_inceput(head, v);
    else
    {
        Node *newNode = (Node *)malloc(sizeof(Node));
        newNode->valoare = v;
        newNode->randament = 0.0;
        while (aux->next != NULL)
            aux = aux->next;
        aux->next = newNode;
        newNode->next = NULL;
    }
}

void calculeaza_Rt(Node *head)
{
    Node *aux = head;
    while (aux != NULL && aux->next != NULL)
    {
        aux->next->randament = (aux->next->valoare - aux->valoare) / aux->valoare;
        aux = aux->next;
    }
}

double calculeaza_Rm(Node *head, int n)
{
    double sum = 0;
    Node *aux = head->next;
    while (aux != NULL)
    {
        sum += aux->randament;
        aux = aux->next;
    }
    return sum / (n - 1);
}

double calculeaza_Volatilitatea(Node *head, int n, double Rm)
{
    double sum = 0;
    Node *aux = head;
    aux = aux->next;
    while (aux != NULL)
    {
        sum += pow(aux->randament - Rm, 2);
        aux = aux->next;
    }
    return sqrt(sum / (n - 1));
}

void afisare_trunchiata(FILE *f, double val)
{
    double trunchiat = trunc(val * 1000.0) / 1000.0;
    fprintf(f, "%.3f\n", trunchiat);
}

void free_list(Node *head)
{
    while (head != NULL)
    {
        Node *tmp = head;
        head = head->next;
        free(tmp);
    }
}