// Nombre del alumno Guillermo Garcia PatiÃ±o Lenza
// Usuario del Juez A34


#include <iostream>
#include <iomanip>
#include <fstream>

#include "dqueue_merge.h"
using namespace std;


// Resuelve un caso de prueba, leyendo de la entrada la
// configuracioÌ�n, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
	dqueue_merge<int> l1;
	int aux;
	cin >> aux;
	while(aux != 0){
		l1.push_back(aux);
		cin >> aux;
	}
	dqueue_merge<int> l2;
	cin >> aux;
	while(aux != 0){
		l2.push_back(aux);
		cin >> aux;
	}

	l1.merge(l2);
	l1.print();

	cout << endl;



}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
    #ifndef DOMJUDGE
     std::ifstream in("datos.txt");
     auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
     #endif


    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();


    // Para restablecer entrada. Comentar para acepta el reto
     #ifndef DOMJUDGE // para dejar todo como estaba al principio
     std::cin.rdbuf(cinbuf);
     system("PAUSE");
     #endif

    return 0;
}
