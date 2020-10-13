#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree_eda.h"
using namespace std;

template<typename T>
T sacaMin(bintree<T> const & arb){
	T val = arb.root();
	T minIzq;
	if(!arb.left().empty()){
		minIzq = sacaMin(arb.left());
		val = min(val,minIzq);
	}
	T minDer;
	if(!arb.right().empty()){
		minDer = sacaMin(arb.right());
		val = min(val,minDer);
	}
	return val;
}

bool resuelveCaso(){
	string aux = "#";
	char c;
	cin >> c;
	if(!cin){
		return false;
	}
	else{
		if(c == 'N'){
			bintree<int> arb = leerArbol(-1);
			int m = sacaMin(arb);
			cout << m << endl;
		}
		else if(c == 'P'){
			bintree<string> arb = leerArbol(aux);
			string m = sacaMin(arb);
			cout << m << endl;
		}
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


    while(resuelveCaso());


    // Para restablecer entrada. Comentar para acepta el reto
     #ifndef DOMJUDGE // para dejar todo como estaba al principio
     std::cin.rdbuf(cinbuf);
     system("PAUSE");
     #endif

    return 0;
}
