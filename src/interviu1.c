#include "biblioteci.h"

int main(int argc, char *const argv[])
{
    FILE *fin = fopen(argv[1], "r");
    double v1, v2, v3;
    int n_citire = fscanf(fin, "%lf %lf %lf", &v1, &v2, &v3);
    fclose(fin);
    if (n_citire == 3)
    {
        }
    else
    {
        fin = fopen(argv[1], "r");
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