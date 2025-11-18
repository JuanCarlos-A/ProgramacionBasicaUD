#include <iostream>
using namespace std;

double factorialRec(int i) {
    if (i == 0) return 1;               // Caso base
    return i * factorialRec(i - 1);     // Llamada recursiva
}


double sumaRec(int k) {
    if (k == 0) return 1;  // 1/0! = 1

    // Llamada recursiva acumulando los términos anteriores
    return (1.0 / factorialRec(k)) + sumaRec(k - 1);
}

int main() {

    int n;
    cout << "Ingrese el valor que tomara n o el enesimo termino:" << endl;
    cin >> n;

    // Validación
    if (n <= 0) {
        cout << "El numero debe ser mayor que 0." << endl;
        return 0;
    }

    cout << "Serie de términos 1/i! :" << endl;

    // Mostrar la serie (usamos factorialRec aquí también)
    for (int i = 0; i <= n - 1; i++) {
        cout << "Termino " << i << ": 1/" << i << "! = "
             << 1.0 / factorialRec(i) << endl;
    }

    cout << "------------------------------------" << endl;

    // Calcular suma usando recursión
    double resultado = sumaRec(n - 1);

    cout << "Valor aproximado de e hasta n = " << n << " es: "
         << resultado << endl;

    return 0;
}
