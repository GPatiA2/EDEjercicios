// Nombre del alumno Guillermo Garcia Patiño Lenza
// Usuario del Juez A34


#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree_eda.h"
using namespace std;


// funcioÌ�n que resuelve el problema
template <typename T>
T getMin(bintree<T> const & arb){
	if(arb.left().empty() && arb.right().empty()){
		// Si estoy en una hoja, el minimo de lo que llevo visto de momento es el elemento de la hoja
		return arb.root();
	}
	else{
		T lmin;
		T rmin;

		bool lempty = arb.left().empty();
		bool rempty = arb.right().empty();

		if(!lempty){lmin = getMin(arb.left());}
		if(!rempty){rmin = getMin(arb.right());}


		//Si el izquierdo esta vacio, el minimo se calcula entre el minimo del derecho y la raiz del arbol
		if(lempty){return min(rmin, arb.root());}
		//Si el derecho esta vacio, el minimo se calcula entre el minimo del izquierdo y la raiz del arbol
		else if (rempty){ return min(lmin, arb.root());}
		//Si ninguno de los dos esta vacio, el minimo se calcula entre el minimo del izquierdo, el minimio del derecho,
		// y la raiz del arbol.
		else{ return min(min(lmin,rmin),arb.root());}

	}


}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuracioÌ�n, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
	char type;
	cin >> type;
    if (! std::cin){
    	return false;
    }
    else{

    	if(type == 'N'){
    		bintree<int> arb = leerArbol(-1);

    		int min = getMin(arb);
    		cout << min << endl;

    	}
    	else if(type == 'P'){
    		string vacio = "#";
    		bintree<string> arb;
    		arb = leerArbol(vacio);

    		string min = getMin(arb);
    		cout << min << endl;
    	}
		return true;
    }

    // escribir sol



}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
    #ifndef DOMJUDGE
     std::ifstream in("datos.txt");
     auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
     #endif


    while (resuelveCaso())
        ;


    // Para restablecer entrada. Comentar para acepta el reto
     #ifndef DOMJUDGE // para dejar todo como estaba al principio
     std::cin.rdbuf(cinbuf);
     system("PAUSE");
     #endif

    return 0;
}


