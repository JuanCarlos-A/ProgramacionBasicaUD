#include <iostream>
using namespace std;

void tipos_numeros(int n) {
    int num;
    int positivos, negativos, ceros;

    positivos = 0;
    negativos = 0;
    ceros = 0;

    for (int i = 1; i <= n; i = i + 1) {
        cout << "Ingrese el numero " << i << ": ";
        cin >> num;
        cout << endl;

        if (num > 0) {
            positivos = positivos + 1;
        } else {
            if (num < 0) {
                negativos = negativos + 1;
            } else {
                ceros = ceros + 1;
            }
        }
    }

    cout << "Cantidad de numeros positivos: " << positivos << endl;
    cout << "Cantidad de numeros negativos: " << negativos << endl;
    cout << "Cantidad de ceros: " << ceros << endl;
    cout << "Cantidad total de numeros analizados: " << n << endl;
    
}  

int main() {
    int n;

    cout << "Bienvenido, ingresa la cantidad de numeros a evaluar : ";
    cin >> n;

    tipos_numeros(n);

    return 0;
}
