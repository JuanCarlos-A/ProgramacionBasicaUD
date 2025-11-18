#include <iostream>     // Para usar cout y cin
#include <cmath>        // Para pow()

using namespace std;

int main() {

    // Declaración de variables
    double R, D, P, J, L;

    // Solicitar datos
    cout << "Ingrese el valor del diametro del lago: ";
    cin >> D;

    // Validación: número mayor que 0
    while (D < 0) {
        cout << "Por favor ingrese un numero mayor: ";
        cin >> D;
    }

    cout << "Diametro del lago: " << D << endl;

    // Cálculo del radio
    R = D / 2.0;
    cout << "Radio del lago: " << R << endl;

    // Solicitar L
    cout << "Ingrese el valor del sobresaliente del junco (cm): ";
    cin >> L;

    while (L < 0) {
        cout << "Por favor ingrese un numero mayor: ";
        cin >> L;
    }

    cout << "Longitud sobresaliente del junco (cm): " << L << endl;

    // Convertir cm a m
    L = L * 0.01;

    cout << "Longitud sobresaliente del junco (m): " << L << endl;

    // Fórmula (bien escrita en C++)
    P = (pow(R, 2) - pow(L, 2)) / (2 * L);

    // Longitud total del junco
    J = P + L;

    cout << "Longitud total del junco (m): " << J << endl;
    cout << "Profundidad del lago (m): " << P << endl;

    return 0;
}
