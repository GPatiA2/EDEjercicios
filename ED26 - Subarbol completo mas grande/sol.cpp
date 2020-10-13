// Nombre del alumno Guillermo Garcia PatiÃ±o Lenza
// Usuario del Juez A34


#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree_eda.h"
using namespace std;

// funcioÌ�n que resuelve el problema


typedef struct{
	int act;
	int top;
	bool existe;
}tsol;

template <typename T>
tsol resolver(bintree<T> const & datos) {

	tsol sol; sol.act = 0; sol.top = 0; sol.existe = false;

	//Si estoy en una hoja
	if(datos.left().empty() && datos.right().empty()){
		sol.existe = true; //El nodo existe
		sol.act = 1;	   //Llevo un nivel
		sol.top = 1;
	}
	else{
		//Si no es hoja
		sol.existe = true; //El nodo existe

		//Inicializo valores para cada uno de los lados
		tsol sI; sI.act = 0; sI.top = 0; sI.existe = false;
		tsol sD; sD.act = 0; sD.top = 0; sD.existe = false;

		//Si existen los hijos derecho e izquierdo, calculo sus valores
		if(!datos.left().empty()){
			sI = resolver(datos.left());
		}
		if(!datos.right().empty()){
			sD = resolver(datos.right());
		}

		//Llevo de arbol completo la rama mas corta de las dos mas el nodo en el que estoy
		sol.act = min(sI.act, sD.act)+1;

		//El maximo es el maximo entre los 3
		sol.top = max(max(sD.top, sI.top),sol.act);


	}

	return sol;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracioÌ�n, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
	bintree<char> datos = leerArbol('.');
	tsol sol;

	if(!datos.empty()){
		sol = resolver(datos);
		if(sol.act > sol.top){
			sol.top = sol.act;
		}
	}
	else{
		sol.top = 0;
	}
	cout << sol.top << endl;
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
