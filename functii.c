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
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->valoare = v;
    if (*head == NULL)
        adaugare_inceput(&*head, v);
    else
    {
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

void free_list(Node *head)
{
    Node *tmp;
    while (head != NULL)
    {
        tmp = head;
        head = head->next;
        free(tmp);
    }
}