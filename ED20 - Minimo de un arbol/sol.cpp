// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree_min.h"
using namespace std;


// función que resuelve el problema

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
	char type;
	cin >> type;
    if (! std::cin){
    	return false;
    }
    else{

    	if(type == 'N'){
    		bintree_min<int> arb = leerArbol_min(-1);

    		int min = arb.getMin();
    		cout << min << endl;

    	}
    	else if(type == 'P'){
    		string vacio = "#";
    		bintree_min<string> arb;
    		arb = leerArbol_min(vacio);

    		string min = arb.getMin();
    		cout << min << endl;
    	}
		return true;
    }

    // escribir sol



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


