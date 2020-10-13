/// Nombre del alumno Guillermo Garcia Patiño Lenza
// Usuario del Juez A34


#include <iostream>
#include <iomanip>
#include <fstream>
#include <queue>
#include "bintree_eda.h"
using namespace std;

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta

/*
 *	Recorro el arbol por anchura, y cada vez que saco de los pendientes el primero del nuevo nivel
 *		lo muestro por pantalla
 *	Para saber si se trata del primero de ese nivel, miro en un bool que almaceno en pendientes junto con
 *		el arbol que estoy mirando
 */
void resuelveCaso() {
    // leer los datos de la entrada
	bintree<int> arb = leerArbol(-1);
	bool marcado = false;
	if(!arb.empty()){
		queue<pair<bool, bintree<int>>> pendientes;
		pendientes.push(pair<bool, bintree<int>>(true, arb));
		marcado = true;
		while(!pendientes.empty()){
			pair<bool, bintree<int>> aux = pendientes.front();
			pendientes.pop();
			if(aux.first){
				marcado = false;
				cout << aux.second.root() << " " ;
			}
			if(!aux.second.left().empty()){
				if(!marcado){
					pendientes.push(pair<bool, bintree<int>>(true, aux.second.left()));
					marcado = true;
				}
				else{
					pendientes.push(pair<bool, bintree<int>>(false, aux.second.left()));
				}
			}
			if(!aux.second.right().empty()){
				if(!marcado){
					pendientes.push(pair<bool,bintree<int>>(true, aux.second.right()));
					marcado = true;
				}
				else{
					pendientes.push(pair<bool, bintree<int>>(false, aux.second.right()));
				}
			}
		}
		cout << endl;
	}





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
