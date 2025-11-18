#include <iostream>
using namespace std;

int main(){
    int tamano;
    cout << "Ingresa el tamano del vector: ";
    cin >> tamano;

    int vectorA[tamano];

    for(int i = 0; i < tamano; ++i){
        cout << "Ingresa el elemento " << i + 1 << ": ";
        cin >> vectorA[i];
    }

    //Mostramos el vector
    cout << "El vector ingresado es: [";
    for(int i = 0; i < tamano; ++i){
        cout << vectorA[i] << " ";
    }
    cout << "]" << endl;

    //Ordenamos el vector usando el algoritmo de burbuja
    for(int i = 0; i < tamano - 1; ++i){ 
        for(int j = 0; j < tamano - i - 1; ++j){
            if(vectorA[j] > vectorA[j + 1]){
                //Intercambiamos los elementos
                int temp = vectorA[j];
                vectorA[j] = vectorA[j + 1];
                vectorA[j + 1] = temp;
            }
        }
    }

    //Mostramos el vector ordenado de menor a mayor
    cout << "El vector ordenado de menor a mayor es: [";
    for(int i = 0; i < tamano; ++i){
        cout << vectorA[i] << " ";
    }
    cout << "]" << endl;

    //Mostramos el vector ordenado de mayor a menor
    cout << "El vector ordenado de mayor a menor es: [";
    for(int i = tamano - 1; i >= 0; --i){
        cout << vectorA[i] << " ";
    }
    cout << "]" << endl;

    return 0;
}