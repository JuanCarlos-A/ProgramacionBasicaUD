#include <iostream>
using namespace std;

int main() {

    char palabra[100];   // tamaño fijo sin constante
    int longitud = 0;
    bool esPalindromo = true;

    cout << "Ingresa una palabra: ";
    cin >> palabra;      // se almacena en el vector

    // Calcular la longitud manualmente
    while (palabra[longitud] != '\0') {
        longitud++;
    }

    // Comparar caracteres desde los extremos hacia el centro
    for (int i = 0; i < longitud / 2; i++) {
        if (palabra[i] != palabra[longitud - 1 - i]) {
            esPalindromo = false;
            break;
        }
    }

    // Resultado final
    if (esPalindromo) {
        cout << "La palabra SI es un palindromo." << endl;
    } else {
        cout << "La palabra NO es un palindromo." << endl;
    }

    return 0;
}
