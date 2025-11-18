#include <iostream>     // Para usar cout y cin
#include <cmath>        // Para pow()

using namespace std;

double radio(double diametro) {
    return diametro / 2.0;
}

double comvertir_cm_a_m(double centimetros) {
    return centimetros * 0.01;
}

double profundidad_lago(double R, double L) {
    return (pow(R, 2) - pow(L, 2)) / (2 * L);
}

double longitud_total_junco(double P, double L) {
    return P + L;
}

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
    cout << "Radio del lago: " << radio(D) << endl;
    R = radio(D);

    // Solicitar L
    cout << "Ingrese el valor del sobresaliente del junco (cm): ";
    cin >> L;

    while (L < 0) {
        cout << "Por favor ingrese un numero mayor: ";
        cin >> L;
    }

    // Convertir cm a m
    L = comvertir_cm_a_m(L);

    cout << "Longitud sobresaliente del junco (m): " << L << endl;
    cout << "Longitud total del junco (m): " << longitud_total_junco(profundidad_lago(R, L), L) << endl;
    cout << "Profundidad del lago (m): " << profundidad_lago(R, L) << endl;

    return 0;
}
