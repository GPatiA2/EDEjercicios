// Nombre del alumno Guillermo Garcia Patiño Lenza
// Usuario del Juez A34


#include <iostream>
#include <iomanip>
#include <fstream>
#include "deuqe_engorda.h"
using namespace std;

// funcioÌ�n que resuelve el problema


// Resuelve un caso de prueba, leyendo de la entrada la
// configuracioÌ�n, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int t1;
    cin >> t1;
    deque_engorda<int> dq1;
    int aux;
    for(int i = 0; i < t1; i++){
    	cin >> aux;
    	dq1.push_back(aux);
    }
    cin >> t1;

    deque_engorda<int> dq2;
    for(int i = 0; i < t1; i++){
    	cin >> aux;
    	dq2.push_back(aux);
    }


    dq1.engorda(dq2);
    dq1.print();
    cout << endl;
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
