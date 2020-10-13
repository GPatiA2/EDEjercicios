// Nombre del alumno Guillermo Garcia Patiño Lenza
// Usuario del Juez A34


#include <iostream>
#include <iomanip>
#include <fstream>
#include "hashmap_eda2.h"
using namespace std;




// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
	int claves;
	cin >> claves;
    if (claves == 0)
        return false;
    else{
    	unordered_map2<int,int> mapa;
    	int c;
    	for(int i = 0; i < claves; i++){
    		cin >> c;
    		mapa[c] = 0;
    	}

    	auto it = mapa.begin();
    	while(it != mapa.end()){
    		if(it->clave % 2 != 0){
				++it;
    		}
    		else{
    			it = mapa.erase(it);
    		}
    	}

    	for(auto it = mapa.begin(); it != mapa.end(); ++it){

    	}
    	if(it == mapa.end()){
    		cout << "TODO BIEN" << endl;
    	}
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
