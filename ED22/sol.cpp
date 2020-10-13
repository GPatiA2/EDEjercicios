// Nombre del alumno Guillermo Garcia Patiño Lenza
// Usuario del Juez A34


#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree_eda.h"
using namespace std;

// función que resuelve el problema

// Esta funcion calcula el maximo de equipos que tiene que rescatar a medida que baja por el arbol como
// 		si fuera un problema de vuelta atras ,y el numero de equipos a medida que sube.
typedef struct{
	int eq;
	int escaladores;
}tsol;
template <typename T>
// Act representa el numero de escaladores que hay en el camino mirado hasta el momento
// Top representa el numero maximo de escaladores que hay en un camino desde la raiz hasta las hojas de la montaña
// La funcion devuelve el numero de equipos que tiene que enviar para ese arbol
tsol resolver(bintree<T> const & datos) {
	tsol equipos;  equipos.eq = 0; equipos.escaladores = 0;

	// Si el arbol no esta vacio, cuento los escaladores para el camino que estoy bajando

	// Si estoy en una hoja
	if(datos.left().empty() && datos.right().empty()){
		// Si hay escaladores en la hoja, mando un equipo, y si no, no hago nada
		if(datos.root() != 0){
			equipos.eq = 1;
		}
		else{
			equipos.eq = 0;
		}

		//Sumo los escaladores de la raiz
		equipos.escaladores += datos.root();

	}
	// Si estoy en un nodo intermedio
	else{

		// Voy a ver cuantos equipos tengo que mandar para el nodo izquierdo
		tsol eqL;  eqL.eq = 0;  eqL.escaladores = 0;
		if(!datos.left().empty()){
			// Sigo bajando el camino contando escaladores con los valores que llevo acumulados
			eqL = resolver(datos.left());
		}

		// Lo mismo para el camino derecho
		tsol eqR;  eqR.eq = 0;  eqR.escaladores = 0;
		if(!datos.right().empty()){
			eqR = resolver(datos.right());
		}

		//Si he mandado equipos para izquierda y derecha, entonces no me hace falta mandar un nuevo equipo
		//	me basta con los que tengo
		if(eqL.eq != 0 && eqR.eq != 0 && datos.root() != 0){
			equipos.eq = eqL.eq+eqR.eq;
		}
		//Si no me hace falta mandar equipo para la izquierda o la derecha, entonces para este grupo tampoco
		//	, me basta con los equipos que haya mandado para uno de los lados
		else if((eqL.eq != 0 || eqR.eq != 0) && datos.root() != 0){
			if(eqL.eq != 0){equipos.eq = eqL.eq;}
			else if(eqR.eq != 0){equipos.eq = eqR.eq;}
		}
		//Si no he mandado equipo para la izquierda o la derecha, tengo que enviar un equipo para este grupo
		else if(eqR.eq == 0 && eqL.eq == 0 && datos.root() != 0){
			equipos.eq = 1;
		}
		else{
			//Si en este nodo no hay nadie que rescatar, me basta con los equipos que habia mandado para la
			//	izquierda y para la derecha
			equipos.eq = eqL.eq + eqR.eq;
		}

		// El maximo numero de escaladores desde donde estoy hasta una hoja se calcula sumando a los escaladores
		//		del camino donde más escaladores hay, los escaladores del nodo en el que estoy
		equipos.escaladores = max(eqL.escaladores, eqR.escaladores) + datos.root();
	}

	return equipos;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
	bintree<int> datos = leerArbol(-1);
    tsol sol = resolver(datos);
    // escribir sol
    cout << sol.eq << " "<< sol.escaladores <<endl;

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
