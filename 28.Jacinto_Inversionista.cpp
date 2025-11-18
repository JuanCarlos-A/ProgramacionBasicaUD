#include <iostream>
using namespace std;

double capitalRecursivo(double capital, double tasa, int años) {
    if (años == 0) {
        return capital; 
    } else {
        double nuevoCapital = capital * (1 + tasa / 100.0);
        return capitalRecursivo(nuevoCapital, tasa, años - 1);
    }
}

int main() {
    double c, x; 
    int n;      

    cout << "=== CALCULO DE INTERES COMPUESTO (RECURSIVO) ===" << endl;
    cout << "Ingrese el capital inicial: ";
    cin >> c;
    cout << "Ingrese la tasa de interes (%): ";
    cin >> x;
    cout << "Ingrese el numero de años: ";
    cin >> n;

    double capitalFinal = capitalRecursivo(c, x, n);

    cout << "\nEl valor final de la inversion es: $" << capitalFinal << endl;

    return 0;
}