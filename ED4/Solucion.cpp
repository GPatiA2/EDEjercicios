// Nombre del alumno Guillermo Garcia Patiño Lenza
// Usuario del Juez A34


#include <iostream>
#include <iomanip>
#include <fstream>
#include "polinomio.h"
using namespace std;


// función que resuelve el problema


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
//	cout << p << endl;
	try{
		Polinomio p;
		cin >> p;
		if (! std::cin){
			return false;
		}
		else{
			int numvalores;
			cin >> numvalores;
			vector<int> evaluar(numvalores);
			for(unsigned int i = 0; i < evaluar.size(); i++){
				cin >> evaluar[i];
			}
			for(unsigned int i = 0; i < evaluar.size(); i++){
				cout << p.evaluarPol(evaluar[i]) << " ";
			}
			cout << endl;
			return true;
		}
	}
	catch(invalid_argument & ia){
		return false;
	}
}


int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
    #ifndef DOMJUDGE
     std::ifstream in("datos.txt");
     auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
     #endif


    while (resuelveCaso())
        ;


    // Para restablecer entrada. Comentar para acepta el reto
     #ifndef DOMJUDGE // para dejar todo como estaba al principio
     std::cin.rdbuf(cinbuf);
     system("PAUSE");
     #endif

    return 0;
}
