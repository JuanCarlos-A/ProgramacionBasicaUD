#include <iostream>
using namespace std;

int main() {
    int n, i, j;
    double factorial, suma;

    cout << "Ingrese el valor que tomara n o el enesimo termino:" << endl;
    cin >> n;

    suma = 0;

    // Se recorre desde 0 hasta n-1
    for (i = 0; i <= n - 1; i = i + 1) {

        // Calcular el factorial de i
        factorial = 1;

        // Comprobamos que i sea mayor a 0
        if (i > 0) {
            // Calcular factorial de i
            for (j = 1; j <= i; j = j + 1) {
                factorial = factorial * j;
            }
        }

        // Agregar el término a la suma
        suma = suma + 1 / factorial;

        // Mostrar el término actual
        cout << "Termino " << i << ": 1/" << i << "! = " << 1 / factorial << endl;
    }

    cout << "------------------------------------" << endl;
    cout << "Valor aproximado de e hasta n = " << n << " es: " << suma << endl;

    return 0;
}
