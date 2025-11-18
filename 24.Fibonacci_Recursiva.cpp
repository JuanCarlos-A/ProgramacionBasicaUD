#include <iostream>
using namespace std;

int fibonacci(int n){
    int a, b, c, i;

    // Inicializar variables
    a = 0;
    b = 1;
    c = 0;

    // Bucle para generar la serie
    for (int i = 0; i < n; i = i + 1) {
        cout << a << endl;
        c = a + b;
        a = b;
        b = c;
    }

    return b - a;
}

int main() {
    int n, a, b, c, i;

    // Inicializar variables
    a = 0;
    b = 1;
    c = 0;

    cout << "Ingrese el n-esimo termino de la serie de Fibonacci:" << endl;
    cin >> n;

    // Validar que n sea mayor que 0
    if (n <= 0) {
        cout << "El numero debe ser mayor que 0." << endl;
    } else {
        cout << "Serie de Fibonacci hasta " << n << ":" << endl;

        // Mostrar el enésimo término
        cout << "El valor de Fibonacci para " << n << " es: " << fibonacci(n) << endl;
    }

    return 0;
}
