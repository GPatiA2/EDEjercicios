#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree_eda.h"
using namespace std;

struct valores{
	int minimo;
	int maximo;

};


valores ramaCorta(bintree<char> const & arb){


}

void resuelveCaso(){
	bintree<char> arb = leerArbol('.');
	if(arb.empty()){
		cout << "NADA" << endl;
	}
	else{

	}
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
