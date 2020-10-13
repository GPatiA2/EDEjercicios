// Nombre del alumno Guillermo Garcia PatiÃ±o Lenza
// Usuario del Juez A34


#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree_eda.h"
using namespace std;


// funcioÌ�n que resuelve el problema

template <typename T>
int getDiametro(bintree<T> const & arb, int & act){
	if(arb.empty()){
		//Si estoy en un arbol vacio, la longitud del camino / diametro es 0.
		act = 0;
		return 0;
	}
	else{
		//Si no, voy a calcular los caminos mas largos de los arboles derecho e izquierdo
		//	a la vez que calculo su altura
		int altDer = 0;
		int altIzq = 0;
		int ltree = getDiametro(arb.left(), altIzq);
		int rtree = getDiametro(arb.right(), altDer);

		//Entonces, la altura de lo que llevo mirado es el maximo entre la altura del
		//	izquierdo y la del derecho, +1 contando el nodo en el que estoy
		act = max(altIzq, altDer)+1;

		//Sabiendo las alturas de los arboles izquierdo y derecho, se que el camino mas largo es
		//	el maximo entre: el camino mas largo del arbol izquierdo, el camino mas largo del arbol derecho
		//	o la suma de las alturas mas 1.
		return max(max(ltree,rtree), altDer+altIzq+1);
	}
}



// Resuelve un caso de prueba, leyendo de la entrada la
// configuracioÌ�n, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
	bintree<char> arb;
	arb = leerArbol('.');
	int act = 0;
	cout << getDiametro(arb,act) << endl;

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
