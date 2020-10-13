// Nombre del alumno Guillermo Garcia PatiÃ±o Lenza
// Usuario del Juez A34


#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree_eda.h"
using namespace std;

// funcioÌ�n que resuelve el problema


typedef struct{
	bool simetrico;
	bool tieneDer;
	bool tieneIzq;
}tsol;
template <typename T>

//Para ver si es simetrico, tengo que ver si el hijo izquierdo del hijo izquierdo es igual al hijo derecho del hijo derecho
//	y si el hijo derecho del hijo izquierdo es igual al hijo izquierdo del hijo derecho

bool simetricos(bintree<T> const & l, bintree<T> const & r) {

	bool iguales;

	tsol der, izq;
	//Miro a ver si existen los nodos izquierdo y derecho de cada uno de los dos nodos
	der.tieneDer = !r.right().empty();
	der.tieneIzq = !r.left().empty();
	izq.tieneDer = !l.right().empty();
	izq.tieneIzq = !l.left().empty();

	bool ig1;	//Hijo derecho del hijo derecho es igual que hijo izquierdo del hijo izquierdo
	bool ig2; 	//Hijo izquierdo del hijo derecho es igual que hijo derecho del hijo izquierdo
	ig1 = false;
	ig2 = false;

	//Si existen o no existen ambos de una pareja
	if(der.tieneDer && izq.tieneIzq){
		//Si existen, que sean simetricos entre ellos
		ig1 = simetricos(l.left(),r.right());
	}
	else if(!der.tieneDer && !izq.tieneIzq){
		//Si no, esta pareja es simetrica
		ig1 = true;
	}

	//Igual para la otra pareja
	if(der.tieneIzq && izq.tieneDer){
		ig2 = simetricos(l.right(), r.left());
	}
	else if(!der.tieneIzq && !izq.tieneDer){
		ig2 = true;
	}

	iguales = ig1 && ig2;

	return iguales;



}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracioÌ�n, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
	bintree<char> datos = leerArbol('.');

	bool sol = false;

	if(!datos.left().empty() && !datos.right().empty()){
		sol = simetricos(datos.left(), datos.right());
	}
	else if(datos.left().empty() && datos.right().empty()){
		sol = true;
	}

    // escribir sol
    if(sol){
    	cout << "SI ";
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
