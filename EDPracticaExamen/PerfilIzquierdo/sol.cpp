#include <iostream>
#include <iomanip>
#include <fstream>
#include <queue>
#include "bintree_eda.h"
using namespace std;

template <typename T>
void perfilIzquierdo(bintree<T> const & arb){
	queue<pair<bintree<T>,bool>> pendientes;
	bool marcadoNivel = false;
	pendientes.push({arb,true});
	marcadoNivel = true;
	while(!pendientes.empty()){
		pair<bintree<T>, bool> aux = pendientes.front();
		pendientes.pop();
		if(aux.second){
			cout << aux.first.root() << " ";
			marcadoNivel = false;
		}
		if(!aux.first.left().empty()){
			pendientes.push({aux.first.left(), !marcadoNivel});
			if(!marcadoNivel){ marcadoNivel = true; }
		}
		if(!aux.first.right().empty()){
			pendientes.push({aux.first.right(), !marcadoNivel});
			if(!marcadoNivel){ marcadoNivel = true; }
		}
	}
	cout << endl;
}

void resuelveCaso(){
	bintree<int> arb = leerArbol(-1);
	if(!arb.empty()){ perfilIzquierdo(arb);}
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
