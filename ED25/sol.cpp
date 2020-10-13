// Nombre del alumno Guillermo Garcia PatiÃ±o Lenza
// Usuario del Juez A34


#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree_eda.h"
using namespace std;

// funcioÌ�n que resuelve el problema


typedef struct{
	int caudal;
	int cant;
	bool navegable;
}tsol;

//Calculo el caudal como la suma de los caudales de los dos afluentes
//Calculo los navegables como la suma de los navegables de los dos afluentes
//	Si el afluente que sale del embalse es navegable, sumo 1 al total de navegables

template <typename T>
tsol resolver(bintree<T> const & datos) {

	tsol sol; sol.caudal = 0; sol.cant = 0;

	if(datos.left().empty() && datos.right().empty()){
		sol.caudal = 1;
		sol.cant = 0;
		sol.navegable = false;
//		cout << "HOJA" << endl;
	}
	else{

		tsol sD; sD.caudal = 0; sD.cant = 0; sD.navegable = false;
		tsol sI; sI.caudal = 0; sI.cant = 0; sI.navegable = false;

		if(!datos.left().empty()){
			sD = resolver(datos.left());
		}
		if(!datos.right().empty()){
			sI = resolver(datos.right());
		}

		sol.caudal = sD.caudal + sI.caudal - datos.root();
		if(sol.caudal < 0){
			sol.caudal = 0;
		}
		sol.navegable = (sol.caudal >= 3);
		sol.cant = sD.cant + sI.cant;

		if(sD.navegable){
			sol.cant += 1;
		}
		if(sI.navegable){
			sol.cant += 1;
		}

	}

	return sol;

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracioÌ�n, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
	bintree<int> datos = leerArbol(-1);
	tsol sol;

	if(!datos.empty()){
		sol = resolver(datos);
	}
	else{
		sol.cant = 0;
	}
	cout << sol.cant << endl;
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
