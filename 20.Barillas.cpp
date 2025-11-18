#include <iostream>     // Para cin y cout
#include <cmath>        // Para sqrt()

using namespace std;

double conversionCmAM(double cm){
    return cm / 100.0;
}

double altura_interseccion(double A, double B, double base){
    double y1 = sqrt(A*A - base*base);
    double y2 = sqrt(B*B - base*base);
    return (y1 * y2) / (y1 + y2);
}



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
    A = conversionCmAM(A_cm);
    B = conversionCmAM(B_cm);

    // Validaciones como en el pseudocódigo
    if (A <= 0 || B <= 0 || base <= 0) {

        cout << "Error: las medidas deben ser mayores que cero.\n";

    } else {

        if (A < base || B < base) {

            cout << "Error: las varillas deben ser mas largas que la base del pozo.\n";

        } else {

            // Mostrar resultados
            cout << "\nResultados:\n";
            cout << "Varilla A: " << A << " m\n";
            cout << "Varilla B: " << B << " m\n";
            cout << "Base del pozo: " << base << " m\n";
            cout << "Altura de interseccion (h): " << altura_interseccion(A, B, base) << " m\n";
        }
    }

    return 0;
}
