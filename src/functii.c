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

int isEmpty(const Node *top)
{
    return top == NULL;
}

double pop(Node **top)
{
    if (isEmpty(*top))
    {
        return 0.0;
    }

    Node *temp = (*top);
    double aux = temp->valoare;
    *top = (*top)->next;
    free(temp);
    return aux;
}

void adauga_in_lista_final(StockList **head, const char *nume)
{
    StockList *nou = (StockList *)calloc(1, sizeof(StockList));
    strcpy(nou->symbol, nume);
    if (*head == NULL)
        *head = nou;
    else
    {
        StockList *aux = *head;
        while (aux->next)
            aux = aux->next;
        aux->next = nou;
    }
}

TreeNode *oglindit(TreeNode *root, const double preturi[][10], int col, int nr_zile)
{
    TreeNode *curr = root;
    for (int i = 1; i < nr_zile; i++)
    {
        if (!curr)
            return NULL;
        if (preturi[i][col] < preturi[i - 1][col])
            curr = curr->right;
        else
            curr = curr->left;
    }
    return curr;
}

void free_tree(TreeNode *root)
{
    if (root == NULL)
        return;

    StockList *head = root->stocks;
    while (head != NULL)
    {
        StockList *tmp = head;
        head = head->next;
        free(tmp);
    }

    free_tree(root->left);
    free_tree(root->right);

    free(root);
}

long long cmmdc(long long a, long long b)
{
    while (b)
    {
        long long t = a % b;
        a = b;
        b = t;
    }
    return a;
}

Fractie simplifica(Fractie f)
{
    if (f.numarator == 0)
    {
        f.numitor = 1;
        return f;
    }
    long long div = cmmdc(f.numarator, f.numitor);
    f.numarator /= div;
    f.numitor /= div;
    return f;
}

Fractie inmultire(Fractie a, Fractie b)
{
    Fractie aux;
    aux.numarator = a.numarator * b.numarator;
    aux.numitor = a.numitor * b.numitor;
    return simplifica(aux);
}

Fractie adunare(Fractie a, Fractie b)
{
    Fractie aux;
    aux.numarator = a.numarator * b.numitor + b.numarator * a.numitor;
    aux.numitor = a.numitor * b.numitor;
    return simplifica(aux);
}