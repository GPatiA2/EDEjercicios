// Nombre del alumno Guillermo Garcia Patiño Lenza
// Usuario del Juez A34


#include <iostream>
#include <iomanip>
#include <fstream>
#include "deque_inserta.h"
using namespace std;


// función que resuelve el problema

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
	int t1;
	cin >> t1;
    if (! std::cin){
        return false;
    }
    else{
    	int aux;
    	deque_inserta<int> dqi;
    	for(int i = 0; i < t1; i++){
    		cin >> aux;
    		dqi.push_back(aux);
    	}

    	int t2; cin >> t2;
    	int pos; cin >> pos;

    	deque_inserta<int> dq2;
    	for(int i = 0; i < t2; i++){
    		cin >> aux;
    		dq2.push_back(aux);
    	}

//    	dqi.print();
//    	cout << endl;
//    	dq2.print();
//    	cout << endl;

    	dqi.insert_in_pos(dq2, pos);

    	dqi.print();
    	cout << endl;
		return true;
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
