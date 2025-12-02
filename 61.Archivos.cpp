#include <iostream>
using namespace std;
int main() {
    int cuenta;
    char nombre[30];
    double saldo;
    FILE *p;
    if((p=fopen("clientes.txt", "w"))==NULL)
    {
       printf("El archivo no pudo abrirse\n");
    }
    else
    {
       printf("Ingrese la cuenta, el nombre y el saldo\n");
       printf("Ingrese la marca de fin de archivo\n");
       printf("? ");
       scanf("%d %s %lf", &cuenta, nombre, &saldo);
       while(!feof(stdin))
       {
           fprintf(p,"%d %s %.2f", cuenta, nombre, saldo);
           printf("? ");
           scanf("%d %s %lf", &cuenta, nombre, &saldo);
       }
       fclose(p);
    }
    return 0;
}