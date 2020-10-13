// Nombre del alumno Guillermo Garcia PatiÃ±o Lenza
// Usuario del Juez A34


#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree_eda.h"
#include <queue>
#include <cmath>
using namespace std;

// funcioÌ�n que resuelve el problema


typedef struct{
	bool busqueda;
	int min;
	int max;
}tsol;


tsol resolver(bintree<int> const & datos) {
	tsol valido;
	if(datos.left().empty() && datos.right().empty()){
		//Si es un arbol de solo raiz, es de busqueda y el minimo y el maximo son el valor de la raiz
		valido.busqueda = true;
		valido.min = datos.root();
		valido.max = datos.root();
		return valido;
	}
	else{
		tsol sIzq, sDer;

		valido.busqueda = true;
		valido.min = datos.root();
		valido.max = datos.root();

		if(!datos.left().empty()){
			//Miro si el hijo izquierdo es de busqueda
			sIzq = resolver(datos.left());
			valido.busqueda = valido.busqueda && sIzq.busqueda && sIzq.max < datos.root();
			//Actualizo minimos y maximos
			valido.min = min(sIzq.min, datos.root());
			valido.max = max(sIzq.max,datos.root());
		}
		//Igual para el derecho
		if(!datos.right().empty()){
			sDer = resolver(datos.right());
			valido.busqueda = valido.busqueda && sDer.busqueda && datos.root() < sDer.min;

			valido.min = min(valido.min, min(sDer.min, datos.root()));
			valido.max = max(valido.max, max(sDer.max, datos.root()));
		}



		return valido;
	}



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
		sol.busqueda = true;
	}

	if(sol.busqueda){
		cout <<  "SI" ;
	}
	else{
		cout << "NO";
	}
	cout << endl;
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


////Si hay dos hijos
//		if(sD.existe && sI.existe){
//			//Si tienen los mismos niveles por debajo
//			if(sD.act == sI.act){
//				sol.act = max(sD.act,sI.act);
//				sol.act += 1;
//				sol.top = max(max(sD.top, sI.top),sol.act);
//			}
//			//Si no tienen los mismos niveles por debajo
//			else{
//				//Reinicio la cuenta a 2 (el nivel en el que estoy mas el de debajo)
//				sol.act = 2;
//				sol.top = max(max(sD.top, sI.top),sol.act);
//			}
//		}
//		//Si no
//		else{
//			//Actualizo el top y reinicio la cuenta
//			sol.top = max(max(sD.top, sI.top),sol.act);
//			sol.act = 1;
//		}
