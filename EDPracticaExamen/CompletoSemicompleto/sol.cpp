#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree_eda.h"
using namespace std;

struct valores{
	int rama;
	bool valido;
};


valores ramaCorta(bintree<char> const & arb){

	if(arb.empty()){
		return {0,true};
	}
	else{
		valores vI = ramaCorta(arb.left());
		valores vD = ramaCorta(arb.right());
		valores v;
		v.rama = max(vI.rama, vD.rama)+1;
		v.valido = (vI.rama - vD.rama <= 1) && (vI.rama - vD.rama >= 0) && vI.valido && vD.valido;
		return v;
	}
}

void resuelveCaso(){
	bintree<char> arb = leerArbol('.');
	if(arb.empty()){
		cout << "NADA" << endl;
	}
	else{
		valores vI; vI.rama = 0; vI.valido = false;
		valores vD; vD.rama = 0; vD.valido = false;
		if(!arb.left().empty()){
			vI = ramaCorta(arb.left());
		}
		if(!arb.right().empty()){
			vD = ramaCorta(arb.right());
		}

		if(vI.valido && vD.valido){
			if(vI.rama == vD.rama){
				cout << "COMPLETO" << endl;
			}
			else if(vI.rama - vD.rama == 1){
				cout << "SEMICOMPLETO" << endl;
			}
			else{
				cout << "NADA" << endl;
			}
		}
		else{
			cout << "NADA" << endl;
		}
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
