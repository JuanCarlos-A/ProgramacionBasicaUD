#include <iostream>
using namespace std;

int main(){
	int A[10];
	int numero = 0;
	
	for (int i = 0; i < 10; i++){
		cout << "Ingresa el valor del arreglo en la posicion " << i+1 << ": ";
		cin >> numero;
		A[i] = numero;
	}
	
	
	// Primer tipo
	for (int i = 0; i < 10; i++){
		cout << "-" << A[i] << "- "; 
	}
	
	//Segundo tipo
	
	
}
