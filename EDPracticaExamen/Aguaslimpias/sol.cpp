#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree_eda.h"
using namespace std;

struct valores{
	int caudal;
	int navegables;
};

valores caudal(bintree<int> const & arb){


		if (arb.left().empty() && arb.right().empty()) {
			return {1,0};
		}
		else{
			valores v;
			valores vI; vI.navegables = 0; vI.caudal = 0;
			if(!arb.left().empty()){
				vI = caudal(arb.left());
			}

			valores vD; vD.navegables = 0; vD.caudal = 0;
			if(!arb.right().empty()){
				vD = caudal(arb.right());
			}

			v.caudal = vI.caudal+vD.caudal-arb.root();
			if(v.caudal < 0){v.caudal = 0;}
			v.navegables = vD.navegables + vI.navegables;
			if(v.caudal >= 3){v.navegables+=1;}
			return v;
		}


}

void resuelveCaso(){
	bintree<int> arb = leerArbol(-1);
	if(arb.empty()){
		cout << "0" << endl;
	}
	else{
		valores v = caudal(arb);
		if(v.caudal >= 3){
			v.navegables-= 1;
		}
		cout << v.navegables << endl;
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
