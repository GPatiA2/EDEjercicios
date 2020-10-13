// Nombre del alumno Guillermo Garcia PatiÃ±o Lenza
// Usuario del Juez A34


#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree_eda.h"
using namespace std;

// funcioÌ�n que resuelve el problema


typedef struct{
	bool correcto; //Si el arbol al que corresponde este valor es correcto o no
	int edad;		//La edad del nodo en el que me encuentro
	int generaciones; //La altura de este nodo
}tsol;
template <typename T>

tsol resolver(bintree<T> const & datos) {

	tsol sol; sol.correcto = true; sol.generaciones = 0;

	if(datos.empty()){
		//Si estoy en un arbol vacio, no hago nada ya que me sirven como solucion los valores a los que inicializo
	}
	else if(datos.left().empty() && datos.right().empty()){
		//Si estoy en una hoja
		sol.correcto = true;	//El arbol es correcto ya que no hay hijos
		sol.generaciones = 1;	//Solo tiene una generacion (1 nivel, el de la raiz)
		sol.edad = datos.root(); //Asigno la edad de este hijo
	}
	else{
		sol.edad = datos.root();

		//Inicializo sDer a estos valores para que, en caso de que no tenga segundo hijo no tenga que hacer comprobaciones
		//	adicionales. Despues resuelvo el arbol cuya raiz es el hijo derecho (segundo hijo)
		tsol sDer; sDer.correcto = true; sDer.edad = 0; sDer.generaciones = 0;
		if(!datos.right().empty()){ sDer = resolver(datos.right());}

		//Lo misimo para el lado izquierdo
		//En este caso, supongo que la inicializacion de la solucion del arbol cuya raiz es el hijo izquierdo (primer hijo)
		//	es algo irrelevante, ya que si no tiene primer hijo, tampoco tendra segundo y me encontraria en el caso base.
		tsol sIzq; sIzq.correcto = true; sIzq.edad = 0; sIzq.generaciones = 0;
		if(!datos.left().empty()){ sIzq = resolver(datos.left());}

		//Condiciones para que el arbol sea correcto
		if(sDer.generaciones == 0 && sIzq.generaciones != 0){
			//Solo un hijo izquierdo
			sol.correcto = sDer.correcto && sIzq.correcto && sol.edad - sIzq.edad >= 18;

		}
		else if(sDer.generaciones != 0 && sIzq.generaciones == 0){
			//Solo un hijo derecho
//			sol.correcto = sDer.correcto && sIzq.correcto && sol.edad - sDer.edad >= 18;
			sol.correcto = false;

		}
		else if(sDer.generaciones != 0 && sIzq.generaciones != 0){
			//Dos hijos
			sol.correcto = sDer.correcto && sIzq.correcto && sol.edad - sDer.edad >= 18 && sol.edad - sIzq.edad >= 18 &&
							sIzq.edad - sDer.edad >= 2;

		}

		//Calculo de la altura del arbol
		sol.generaciones = max(sDer.generaciones, sIzq.generaciones)+1;
	}

	return sol;



}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracioÌ�n, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
	bintree<int> datos = leerArbol(-1);
    tsol sol = resolver(datos);
    // escribir sol
    if(sol.correcto){
    	cout << "SI " << sol.generaciones;
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
