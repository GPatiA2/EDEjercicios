// Nombre del alumno Guillermo Garcia Patiño Lenza
// Usuario del Juez A34


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
#include "pelicula.h"
using namespace std;

// función que resuelve el problema


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
	int pelis;
	cin >> pelis;
    if (pelis == 0)
        return false;
    else{
    	vector<Pelicula> peliculas(pelis);
    	for(unsigned int i = 0; i < peliculas.size(); i++){
    		cin >> peliculas[i];
    	}
    	sort(peliculas.begin(), peliculas.begin()+peliculas.size());
    	// escribir sol
    	for(unsigned int i = 0; i < peliculas.size(); i++){
    		cout << peliculas[i] << endl;
    	}
    	cout << "---" << endl;
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
