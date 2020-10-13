// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree_eda.h"
using namespace std;

struct valores{
	int ramaCorta;
	int maximo;
};

valores diametro(const bintree<char> & arb){
	if(arb.empty()){
		return {0,0};
	}
	else{
		valores vI = diametro(arb.left());
		valores vD = diametro(arb.right());
		//Tengo que llevar la rama mas larga que sale de este nodo para hacer el diametro.
		//	Si llevo la corta, en el nodo compararia el camino que une las dos ramas mas cortas, y no tendría el diametro
		//	ya que yo quiero el camino que une las ramas largas
		return {max(vI.ramaCorta, vD.ramaCorta)+1 , max(max(vI.maximo, vD.maximo), vI.ramaCorta+vD.ramaCorta+1)};
	}
}

void resuelveCaso() {
    // leer los datos de la entrada
	bintree<char> arb = leerArbol('.');
	valores i = diametro(arb);
	cout << i.maximo << endl;
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
