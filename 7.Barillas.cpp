#include <iostream>     // Para cin y cout
#include <cmath>        // Para sqrt()

using namespace std;

int main() {

    // Declaración de variables en C++
    double A_cm, B_cm;           // Entradas en centímetros
    double A, B, base;           // Convertidas a metros
    double h, y1, y2;            // Resultados intermedios

    cout << "Ingrese la longitud de la varilla A (cm): ";
    cin >> A_cm;

    cout << "Ingrese la longitud de la varilla B (cm): ";
    cin >> B_cm;

    cout << "Ingrese la base del pozo (m): ";
    cin >> base;

    // Conversión de cm a m
    A = A_cm / 100.0;
    B = B_cm / 100.0;

    // Validaciones como en el pseudocódigo
    if (A <= 0 || B <= 0 || base <= 0) {

        cout << "Error: las medidas deben ser mayores que cero.\n";

    } else {

        if (A < base || B < base) {

            cout << "Error: las varillas deben ser mas largas que la base del pozo.\n";

        } else {

            // Cálculo corregido: en pseudocódigo ponía a*a pero la variable es A
            y1 = sqrt(A*A - base*base);
            y2 = sqrt(B*B - base*base);

            h = (y1 * y2) / (y1 + y2);

            // Mostrar resultados
            cout << "\nResultados:\n";
            cout << "Varilla A: " << A << " m\n";
            cout << "Varilla B: " << B << " m\n";
            cout << "Base del pozo: " << base << " m\n";
            cout << "Altura de interseccion (h): " << h << " m\n";
        }
    }

    return 0;
}
