// Nombre del alumno Guillermo Garcia Patiño Lenza
// Usuario del Juez A34


#include <iostream>
#include <iomanip>
#include <fstream>
#include <unordered_map>
#include <vector>
using namespace std;

using numero = int;
using repeticiones = int;
typedef struct{
	repeticiones r;
	int ap;
}tval;

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracioÌ�n, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int numeros;
    cin >> numeros;
    if (! std::cin){
        return false;
    }
    else{
    	unordered_map<numero,tval> map;
    	int cant = 0; //cantidad de numeros diferentes que hay en la lista de datos
    	int leido;
    	for(int i = 0; i < numeros; i++){
    		cin >> leido;
    		if(!map.count(leido)){ //coste cte
    			map[leido].r = 1;  //coste cte
    			map[leido].ap = cant; //coste cte
    			cant++;
    		}
    		else{
    			map[leido].r++; //coste cte
    		}
    	}
    	pair<numero,repeticiones> salida[cant];
    	for(auto p : map){ //O(cant)
    		salida[p.second.ap] = {p.first, p.second.r};
    	}
    	for(int i = 0; i < cant; i++){
    		cout << salida[i].first << " " << salida[i].second << endl;
    	}
    	cout << "---" << endl;
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
