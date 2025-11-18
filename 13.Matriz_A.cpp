#include <iostream>
using namespace std;

int main(){
    int tamano_filas;
    int tamano_columnas;
    cout << "Ingresa el tamano de filas de la matriz: ";
    cin >> tamano_filas;
    cout << "Ingresa el tamano de columnas de la matriz: ";
    cin >> tamano_columnas;

    int matrizA[tamano_filas][tamano_columnas];

    for(int i = 0; i < tamano_filas; ++i){
        for(int j = 0; j < tamano_columnas; ++j){
            cout << "Ingresa el elemento [" << i + 1 << "][" << j + 1 << "]: ";
            cin >> matrizA[i][j];
        }
    }

    //Mostramos el vector
    cout << "El vector ingresado es: [";
    cout << endl;
    for(int i = 0; i < tamano_filas; ++i){
        for(int j = 0; j < tamano_columnas; ++j){
            cout << matrizA[i][j] << " "; 
        }
        cout << endl;
    }
    cout << "]" << endl;

    return 0;
}