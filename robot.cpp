#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

/*
 
  cargarArchivo()
  Lee todos los datos del archivo robot.txt y los almacena en
  variables.
  Devuelve true si la ejcucion de la funcion fue correcta, false si hubo un error.
 
*/
bool cargarArchivo(int matriz[100][100], int &m, int &n,
                   int &i1, int &j1, int &i2, int &j2,
                   char &orientacion, char ordenes[], int &numOrdenes) {

    ifstream fin("/home/jc-aguilar/Documentos/programacionBasica/proyecto_Final/robot.txt");
    if (!fin) {
        cout << "Error: No se pudo abrir robot.txt\n";
        return false;
    }

    // Leer dimensiones del recinto
    fin >> m >> n;

    // Leer la matriz de minas (0 = seguro, 1 = mina)
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            fin >> matriz[i][j];
        }
    }

    // Posición inicial
    fin >> i1 >> j1;

    // Posición destino
    fin >> i2 >> j2;

    // orientacionentación inicial (N, E, S, O)
    fin >> orientacion;

    // Cantidad de órdenes
    fin >> numOrdenes;

    // Leer las órdenes una por una
    for (int k = 0; k < numOrdenes; k++) {
        fin >> ordenes[k];
    }

    fin.close();
    return true;
}

/*

  convertirOrientacion()
  Convierte la letra N,E,S,O a un número para facilitar la logica de un reloj:
     N = 0
     E = 1
     S = 2
     O = 3

*/
int convertirOrientacion(char c) {
    if (c == 'N') return 0;
    if (c == 'E') return 1;
    if (c == 'S') return 2;
    return 3; // O
}

/*
 
  girarIzquierda()
  Recibe un puntero a la variable "direccion".
  La dirección cambia como un reloj al revés:
     N → O
     O → S
     S → E
     E → N
 
*/
void girarIzquierda(int *direccion) {
    *direccion = (*direccion + 3) % 4;  // sumar -1 mod 4
}

/*
 
  girarDerecha()
  Recibe un puntero y mueve la direccion como un reloj normal:
     N → E
     E → S
     S → O
     O → N

*/
void girarDerecha(int *direccion) {
    *direccion = (*direccion + 1) % 4; // sumar +1 mod 4
}

/*

  FUNCIÓN: avanzar()
  Usando la direccion, calcula la siguiente casilla.
  usamos como punteros a f y c para modificar sus valores

*/
void avanzar(int *r, int *c, int direccion) {

    // Norte → fila - 1
    if (direccion == 0) (*r)--;

    // Este → columna + 1
    else if (direccion == 1) (*c)++;

    // Sur → fila + 1
    else if (direccion == 2) (*r)++;

    // Oeste → columna - 1
    else (*c)--;
}

/*

  dentro()
  Verifica si una casilla está dentro del recinto.
  evitamos que el robot se salga de los limites

*/
bool dentro(int f, int c, int m, int n) {
    return (f >= 0 && f < m && c >= 0 && c < n);
}


/*

    imprimirEstado()
    Muestra el recorrido actual del robot en la consola.

*/
void imprimirEstado(int matriz[][100], int m, int n, int f, int c, int direccion, bool visitado[][100]) {

    // marcar casilla visitada
    visitado[f][c] = true;

    cout << "\nActualizacion de Estado\n";

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {

            if (i == f && j == c) { 
                // robot en esta casilla
                if (direccion == 0) cout << " ^ ";
                else if (direccion == 1) cout << " > ";
                else if (direccion == 2) cout << " v ";
                else cout << " < ";
            }
            else if (matriz[i][j] == 1) {
                cout << " X ";
            }
            else if (visitado[i][j]) {
                cout << " # ";
            }
            else {
                cout << " . ";
            }
        }
        cout << endl;
    }

    cout << "-------------------------------\n";
}




/*

  simularRobot()
  Ejecuta todas las órdenes del robot y determina:
    Llega al destino (devuelve true)
    Muere o se sale (devuelve false

*/
bool simularRobot(int matriz[][100], int m, int n,
                  int i1, int j1, int i2, int j2,
                  char orientacion, char ordenes[], int numOrdenes) {

    bool visitado[100][100] = {false};

    // Convertimos a índices 
    int f = i1 - 1;
    int c = j1 - 1;

    int destF = i2 - 1;
    int destC = j2 - 1;

    int direccion = convertirOrientacion(orientacion);

    if (matriz[f][c] == 1) return false;

    // Imprimir estado inicial
    imprimirEstado(matriz, m, n, f, c, direccion, visitado);

    // Procesamos cada orden
    for (int k = 0; k < numOrdenes; k++) {

        char cmd = ordenes[k];
        cout << "\nOrden " << k+1 << " - " << cmd << endl;

        if (cmd == 'I') {
            girarIzquierda(&direccion);
        }
        else if (cmd == 'D') {
            girarDerecha(&direccion);
        }
        else if (cmd == 'A') {

            int nf = f;
            int nc = c;

            avanzar(&nf, &nc, direccion);

            if (!dentro(nf, nc, m, n)) {
                cout << "Salio de la cuadricula\n";
                return false;
            }

            if (matriz[nf][nc] == 1) {
                cout << "Piso una mina.\n";
                return false;
            }

            f = nf;
            c = nc;
        }

        // Imprimir estado después de cada orden
        imprimirEstado(matriz, m, n, f, c, direccion, visitado);
    }

    return (f == destF && c == destC);
}


int main() {

    int matriz[100][100];  // Matriz del recinto
    int m, n;            // Tamaño del recinto
    int i1, j1;          // Inicio
    int i2, j2;          // Destino
    char orientacion;            // orientacion inicial
    char ordenes[39];     // ordenes del robot
    int numOrdenes;       // Cantidad de órdenes

    // Leer archivo
    if (!cargarArchivo(matriz, m, n, i1, j1, i2, j2, orientacion, ordenes, numOrdenes)) {
        return 1;
    }

    // Ejecutar simulación
    bool resultado = simularRobot(matriz, m, n, i1, j1, i2, j2, orientacion, ordenes, numOrdenes);

    // Guardar la respuesta en robot_out.txt
    ofstream fout("/home/jc-aguilar/Documentos/programacionBasica/proyecto_Final/robot_out.txt");
    if (!fout) {
        cout << "Error: No se pudo crear robot_out.txt\n";
        return 1;
    }

    fout << (resultado ? 'C' : 'E') << endl; // <- Operador ternario
    fout.close();

    cout << "Simulacion completada. Resultado: " << (resultado ? 'C' : 'E') << "\n";

    return 0;
}
