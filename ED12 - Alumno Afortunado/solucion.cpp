// Nombre del alumno Guillermo Garcia Patiño Lenza
// Usuario del Juez A34


#include <iostream>
#include <iomanip>
#include <fstream>
#include "deque_eda.h"
using namespace std;
// funcioÌ�n que resuelve el problema


int resuelve(deque<int> & clase, int salvados){
	while(clase.size() != 1){
		for(int i = 0; i < salvados; i++){
			int aux = clase.back();

			clase.pop_back();
			clase.push_front(aux);
		}


		clase.pop_back();
	}
	return clase.back();
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracioÌ�n, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int alumnos;
    cin >> alumnos;
    int salvados;
    cin >> salvados;
    if (alumnos == 0 && salvados == 0){
        return false;
    }
    else{
    	deque<int> clase;
    	for(int i = 1; i < alumnos+1 ; i++){
    		clase.push_front(i);
    	}
		int sol = resuelve(clase, salvados);
		// escribir sol
		cout << sol << endl;
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
