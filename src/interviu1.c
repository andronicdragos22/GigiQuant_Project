#include "biblioteci.h"

int main(int argc, char const *argv[])
{
    FILE *f = fopen(argv[1], "r");
    char elem[60];
    if (f == NULL)
        return 1;
    fscanf(f, "%59s", elem);
    fclose(f);
    if (strchr(elem, ','))
    {
        FILE *fin = fopen(argv[1], "r");
        char nume[10][5];
        double preturi[100][10];
        int zile = 0;
        for (int i = 0; i < 10; i++)
        {
            fscanf(fin, "%[^, \n]", nume[i]);
            fgetc(fin);
        }
        while (fscanf(fin, "%lf,", &preturi[zile][0]) == 1)
        {
            for (int j = 1; j < 9; j++)
                fscanf(fin, "%lf,", &preturi[zile][j]);
            fscanf(fin, "%lf", &preturi[zile][9]);
            zile++;
        }
        TreeNode *root = (TreeNode *)calloc(1, sizeof(TreeNode));
        for (int j = 0; j < 10; j++)
        {
            TreeNode *curr = root;
            for (int i = 1; i < zile; i++)
            {
                if (preturi[i][j] < preturi[i - 1][j])
                {
                    if (!curr->left)
                        curr->left = (TreeNode *)calloc(1, sizeof(TreeNode));
                    curr = curr->left;
                }
                else
                {
                    if (!curr->right)
                        curr->right = (TreeNode *)calloc(1, sizeof(TreeNode));
                    curr = curr->right;
                }
            }
            adauga_in_lista_final(&(curr->stocks), nume[j]);
        }
        fclose(fin);
        FILE *fout = fopen(argv[2], "w");
        for (int i = 0; i < 10; i++)
        {
            TreeNode *nod_ogl = oglindit(root, preturi, i, zile);
            if (nod_ogl && nod_ogl->stocks)
            {
                StockList *s = nod_ogl->stocks;
                while (s)
                {
                    int id = -1;
                    for (int k = 0; k < 10; k++)
                        if (strcmp(nume[k], s->symbol) == 0)
                        {
                            id = k;
                            break;
                        }
                    if (i < id)
                        fprintf(fout, "%s-%s\n", nume[i], s->symbol);
                    s = s->next;
                }
            }
        }
        fclose(fout);
    }
    else if (!isdigit(elem[0]))
    {
        FILE *fin = fopen(argv[1], "r");
        Node *s1 = NULL;
        Node *s2 = NULL;
        Node *s3 = NULL;
        int id = -1;
        char p1[50];
        char p2[50];
        char p3[50];
        char temp[50];
        while (fscanf(fin, " %49[^\n]", temp) == 1)
        {
            if (isdigit(temp[0]))
            {
                if (id == 0)
                    adaugare_inceput(&s1, atof(temp));
                else if (id == 1)
                    adaugare_inceput(&s2, atof(temp));
                else if (id == 2)
                    adaugare_inceput(&s3, atof(temp));
            }
            else
            {
                id++;
                if (id == 0)
                    strcpy(p1, temp);
                else if (id == 1)
                    strcpy(p2, temp);
                else if (id == 2)
                    strcpy(p3, temp);
            }
        }
        fclose(fin);
        FILE *fout = fopen(argv[2], "w");
        int zi = 1;
        while (s1 && s2 && s3)
        {
            double v1 = pop(&s1);
            double v2 = pop(&s2);
            double v3 = pop(&s3);
            if (v1 == v2 && v1 != v3)
                fprintf(fout, "ziua %d - %.2f - %s\n", zi, fabs(v3 - v1), p3);
            else if (v1 == v3 && v1 != v2)
                fprintf(fout, "ziua %d - %.2f - %s\n", zi, fabs(v2 - v1), p2);
            else if (v2 == v3 && v2 != v1)
                fprintf(fout, "ziua %d - %.2f - %s\n", zi, fabs(v1 - v2), p1);
            zi++;
        }
        fclose(fout);
    }

    else
    {
        FILE *fin = fopen(argv[1], "r");
        int n;
        Node *head = NULL;
        fscanf(fin, "%d", &n);
        for (int i = 0; i < n; i++)
        {
            double val;
            fscanf(fin, "%lf", &val);
            adaugare_final(&head, val);
        }
        fclose(fin);
        if (n < 2)
        {
            free_list(head);
            return 0;
        }
        calculeaza_Rt(head);
        double Rm = calculeaza_Rm(head, n);
        double Vol = calculeaza_Volatilitatea(head, n, Rm);
        double Sharpe = 0.0;
        if (Vol != 0)
            Sharpe = Rm / Vol;
        FILE *fout = fopen(argv[2], "w");
        afisare_trunchiata(fout, Rm);
        afisare_trunchiata(fout, Vol);
        afisare_trunchiata(fout, Sharpe);
        fclose(fout);
        free_list(head);
    }
    return 0;
}