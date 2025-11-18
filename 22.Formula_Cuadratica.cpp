#include <iostream>     // cout, cin
#include <cmath>        // sqrt(), pow()
#include <string>       // string
using namespace std;

double determinar_determinante(int a, int b, int c) {
    return pow(b, 2) - 4 * a * c;
}

double calcular_raiz_positiva(int a, int b, double determinante) {
    return ((-1.0 * b) + sqrt(determinante)) / (2 * a);
}

double calcular_raiz_negativa(int a, int b, double determinante) {
    return ((-1.0 * b) - sqrt(determinante)) / (2 * a);
}

double calcular_raiz_compleja_parte_real(int a, int b) {
    return (-1.0 * b) / (2 * a);
}

int main() {

    // Declaración de variables
    int a, b, c;
    double determinante;
    double n1, n2;
    string complePositiva, compleNegativa;

    // Inicialización
    a = b = c = 0;
    determinante = 0;
    n1 = n2 = 0;

    // Mensajes de introducción
    cout << "Programa para resolver una ecuacion cuadratica." << endl;
    cout << "Usaremos la formula general (Bhaskara)." << endl;
    cout << "Recuerda: el coeficiente A NO debe ser 0." << endl;

    // Entrada de datos
    cout << "Ingresa el coeficiente A: ";
    cin >> a;

    cout << "Ingresa el coeficiente B: ";
    cin >> b;

    cout << "Ingresa el coeficiente C: ";
    cin >> c;

    // Validación: A no puede ser 0
    while (a == 0) {
        cout << "Error matematico: A no puede ser 0." << endl;
        cout << "Ingresa nuevamente A: ";
        cin >> a;
    }

    // Cálculo del determinante
    determinante = determinar_determinante(a, b, c);

    // Si el determinante es positivo o cero: raíces reales
    if (determinante >= 0) {

        cout << "Primera x = " << calcular_raiz_positiva(a, b, determinante) << endl;
        cout << "Segunda x = " << calcular_raiz_negativa(a, b, determinante) << endl;

    } 
    // Caso raíces complejas
    else {

        // Trabajamos el determinante negativo convirtiéndolo a positivo
        double detPositivo = determinante * -1;

        // Parte real = -b / 2a
        n1 = calcular_raiz_compleja_parte_real(a, b);

        // Si la raíz NO es un entero exacto
        if (sqrt(detPositivo) != trunc(sqrt(detPositivo))) {

            // Construcción literal de cadenas
            complePositiva = to_string(n1) + " + (" + to_string(sqrt(detPositivo)) + "i / " + to_string(2 * a) + ")";
            compleNegativa = to_string(n1) + " - (" + to_string(sqrt(detPositivo)) + "i / " + to_string(2 * a) + ")";

        } 
        // Caso raíz exacta
        else {

            n2 = sqrt(detPositivo) / (2 * a);

            complePositiva = to_string(n1) + " + " + to_string(n2) + "i";
            compleNegativa = to_string(n1) + " - " + to_string(n2) + "i";
        }

        cout << "Primera x = " << complePositiva << endl;
        cout << "Segunda x = " << compleNegativa << endl;
    }

    // Imprimir coeficientes
    cout << "\nCoeficientes ingresados:" << endl;
    cout << "A : " << a << endl;
    cout << "B : " << b << endl;
    cout << "C : " << c << endl;

    return 0;
}
