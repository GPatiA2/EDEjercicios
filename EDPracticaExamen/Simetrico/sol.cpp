#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree_eda.h"
using namespace std;


bool simetrico(bintree<char> const & l, bintree<char> const & r){

		if (!l.empty() && !r.empty()) {
			bool simFuera = false;
			bool simDentro = false;

			if(l.left().empty() && r.right().empty()){
				simFuera = true;
			}
			else if(!l.left().empty() && !r.right().empty()){
				simFuera = simetrico(l.left(), r.right());
			}

			if(l.right().empty() && r.left().empty()){
				simDentro = true;
			}
			else if(!l.right().empty() && !r.left().empty()){
				simDentro = simetrico(l.right(), r.left());
			}

			return simFuera && simDentro;
		}
		else if(l.empty() && r.empty()){
			return true;
		}
		else{
			return false;
		}
}

void resuelveCaso(){
	bintree<char> arb = leerArbol('.');
	if(arb.empty()){
		cout << "SI" << endl;
	}
	else{
		bool b = simetrico(arb.left(), arb.right());
		if(b){
			cout << "SI" << endl;
		}
		else{
			cout << "NO" << endl;
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
