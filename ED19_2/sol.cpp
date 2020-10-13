// Nombre del alumno Guillermo Garcia PatiÃ±o Lenza
// Usuario del Juez A34


#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree_eda.h"

using namespace std;

// funcioÌ�n que resuelve el problema
// Resuelve un caso de prueba, leyendo de la entrada la
// configuracioÌ�n, y escribiendo la respuesta
template <typename T>
void frontera(bintree<T> const & arb){
	if(arb.empty()){
		//No hago nada y vuelvo
	}
	else{
		if(arb.left().empty() && arb.right().empty()){
			//Meto en el vector frontera el elemento por el final
			cout << arb.root() << " ";
		}
		else{
			frontera(arb.left());
			frontera(arb.right());
		}
	}
}


void resuelveCaso() {
    // leer los datos de la entrada
	bintree<int> arb;
	arb = leerArbol(-1);

	frontera(arb);
	cout << endl;

    // escribir sol


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
