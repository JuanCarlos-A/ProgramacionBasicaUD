#include <iostream>
using namespace std;
int fib(int n) {
    if (n == 0) return 0;      // Caso base 1
    if (n == 1) return 1;      // Caso base 2
    return fib(n - 1) + fib(n - 2); // Llamada recursiva doble
}

int main() {

    int n;

    cout << "Ingrese el n-esimo termino de la serie de Fibonacci:" << endl;
    cin >> n;

    if (n <= 0) {
        cout << "El numero debe ser mayor que 0." << endl;
    } else {

        cout << "Serie de Fibonacci hasta " << n << ":" << endl;

        // Generar la serie usando la función recursiva
        for (int i = 0; i < n; i++) {
            cout << fib(i) << endl;
        }

        // Mostrar el n-ésimo término
        cout << "El valor de Fibonacci para " << n << " es: " << fib(n - 1) << endl;
    }

    return 0;
}
