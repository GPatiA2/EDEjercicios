// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree_eda.h"
using namespace std;

struct valores{
	int hojas;
	int nodos;
	int altura;
};

valores calcular (bintree<char> const & arb){
	valores v; v.hojas = 0; v.nodos = 0; v.altura = 0;
	if(!arb.empty()){
		valores vR = calcular(arb.right());
		valores vI = calcular(arb.left());

		v.nodos = vR.nodos + vI.nodos + 1;
		v.hojas = vR.hojas + vI.hojas;
		v.altura = max(vR.altura, vI.altura) + 1;

		if(arb.left().empty() && arb.right().empty()){
			v.hojas += 1;
		}
	}
	return v;
}

void resuelveCaso() {
    // leer los datos de la entrada
	bintree<char> arb = leerArbol('.');
	valores v = calcular(arb);
	cout << v.nodos << " " << v.hojas << " " << v.altura << endl;
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
