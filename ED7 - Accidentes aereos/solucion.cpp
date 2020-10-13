// Nombre del alumno Guillermo Garcia Patiño Lenza
// Usuario del Juez A34


#include <iostream>
#include <iomanip>
#include <fstream>
#include <stack>
#include "Accidente.h"
using namespace std;

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
	int numAccidentes;
	cin >> numAccidentes;
    if (! std::cin){
        return false;
	}
    else{
    	stack<Accidente> st;
    	for(int i = 0; i < numAccidentes; i++){
    		Accidente a;
    		cin >> a;
    		bool encontrado = false;
    		while(st.size() > 0 && !encontrado){
    			if(st.top() > a){ cout << st.top() << '\n'; encontrado = true;}
    			else{st.pop();}
    		}
    		st.push(a);
    		if(!encontrado){cout << "NO HAY" << '\n';}
    	}
    	cout << "---" << '\n';



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
