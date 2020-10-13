// Nombre del alumno Guillermo Garcia Patiño Lenza
// Usuario del Juez A34


#include <iostream>
#include <iomanip>
#include <fstream>
#include "Lista_insert.h"
using namespace std;


// función que resuelve el problema
// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
	int tam1;
	cin >> tam1;
    if (! std::cin){
        return false;
    }
    else{
    	//Leo la primera lista
    	int aux;
    	Lista_insert<int> l1;
    	for(int i = 0; i < tam1; i++){
    		cin >> aux;
    		l1.push(aux);
    	}

    	//Leo la posicion y la segunda lista
    	int tam2;
    	cin >> tam2;
    	int pos;
    	cin >> pos;

    	Lista_insert<int> l2;
    	for(int i = 0; i < tam2; i++){
    		cin >> aux;
    		l2.push(aux);
    	}

    	//Inserto la segunda lista en la posicion indicada de la primera
    	l1.insert_in_pos(pos,l2);
    	l1.print();
    	cout << endl;
		return true;
    }

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
