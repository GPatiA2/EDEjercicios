#include <iostream>
#include <iomanip>
#include <fstream>
#include <queue>
#include <cmath>
#include "bintree_eda.h"
using namespace std;

//rel = true si es para menores
//rel = false si es para mayores
bool esBinarioDeBusqueda(bintree<int> const & arb, int elem, bool rel){

	if(arb.empty()){return true;}
	else{
		if(rel && arb.root() > elem){
			return false;
		}
		else if(!rel && arb.root() < elem){
			return false;
		}
		else if(arb.root() == elem){
			return false;
		}

		bool busqI = esBinarioDeBusqueda(arb.left(), arb.root(), true);
		bool busqR = esBinarioDeBusqueda(arb.right(), arb.root(), false);

		return busqI && busqR;
	}
}

void resuelveCaso(){

	bintree<int> arb = leerArbol(-1);
	bool busquedaL ;
	bool busquedaR ;
	if(!arb.empty()){
		busquedaL = esBinarioDeBusqueda(arb.left(), arb.root(), true);
		busquedaR = esBinarioDeBusqueda(arb.right(), arb.root(), false);
	}
	string s = (busquedaL && busquedaR) || arb.empty()? "SI" : "NO";
	cout << s << endl;
}


int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
    #ifndef DOMJUDGE
     std::ifstream in("datos.txt");
     auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
     #endif

    int numcasos;
    cin >> numcasos;
    for(int i = 0; i < numcasos; i++){resuelveCaso();}


    // Para restablecer entrada. Comentar para acepta el reto
     #ifndef DOMJUDGE // para dejar todo como estaba al principio
     std::cin.rdbuf(cinbuf);
     system("PAUSE");
     #endif

    return 0;
}
