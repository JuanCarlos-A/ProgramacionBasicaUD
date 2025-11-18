#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int N;
    cout << "Ingrese la cantidad total de individuos de la muestra: ";
    cin >> N;

    if (N <= 0) {
        cout << "Error: debe ingresar un numero entero positivo." << endl;
        return 0;
    }

    double* hemoglobina = new double[N];
    double* susceptibles = new double[N];
    int cont_susceptibles = 0;

    for (int i = 0; i < N; i++) {
        cout << "Ingrese el indice de hemoglobina del individuo " << i + 1 << ": ";
        cin >> hemoglobina[i];

        if (hemoglobina[i] >= 80 && hemoglobina[i] <= 100) {
            susceptibles[cont_susceptibles] = hemoglobina[i];
            cont_susceptibles++;
        }
    }

    if (cont_susceptibles == 0) {
        cout << "\nNo hay individuos con indices de hemoglobina entre 80 y 100." << endl;
        delete[] hemoglobina;
        delete[] susceptibles;
        return 0;
    }

    double suma = 0;
    for (int i = 0; i < cont_susceptibles; i++) {
        suma += susceptibles[i];
    }
    double media = suma / cont_susceptibles;

    double suma_cuadrados = 0;
    for (int i = 0; i < cont_susceptibles; i++) {
        double diff = susceptibles[i] - media;
        suma_cuadrados += diff * diff;
    }
    double varianza = suma_cuadrados / cont_susceptibles;

    double desviacion = sqrt(varianza);

    cout << "\n--- RESULTADOS ---" << endl;
    cout << "Individuos susceptibles: ";
    for (int i = 0; i < cont_susceptibles; i++) {
        cout << susceptibles[i] << " ";
    }
    cout << endl;
    cout << "Media aritmetica: " << media << endl;
    cout << "Desviacion tipica: " << desviacion << endl;

    delete[] hemoglobina;
    delete[] susceptibles;

    return 0;
}
