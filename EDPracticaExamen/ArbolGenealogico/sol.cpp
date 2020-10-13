// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree_eda.h"
using namespace std;

struct valores{
	bool genealogico;
	int generaciones;
};

valores genealogico(const bintree<int> & arb){
	if(arb.empty()){
		return{true,0};
	}
	else{
		valores vI = genealogico(arb.left());
		valores vD = genealogico(arb.right());
		valores v;
		v.generaciones = 0;
		v.genealogico = vI.genealogico && vD.genealogico;
		if(!arb.left().empty()){
			v.genealogico = v.genealogico && (arb.root() - arb.left().root() >= 18);
		}
		if(!arb.right().empty()){
			v.genealogico = v.genealogico && (arb.root() - arb.right().root() >= 18);
		}
		if(!arb.left().empty() && !arb.right().empty()){
			v.genealogico = v.genealogico && (arb.left().root() - arb.right().root() >= 2);
		}

		if(v.genealogico){
			v.generaciones = max(vI.generaciones, vD.generaciones)+1;
		}

		if(!arb.right().empty() && arb.left().empty()){v.genealogico = false;}

		return v;
	}
}

void resuelveCaso() {
    // leer los datos de la entrada
	bintree<int> arb = leerArbol(-1);
	valores i = genealogico(arb);
	if(i.genealogico){ cout << "SI " << i.generaciones << endl;}
	else{cout << "NO" << endl;}
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
