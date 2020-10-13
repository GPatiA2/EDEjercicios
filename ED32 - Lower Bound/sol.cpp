// Nombre del alumno Guillermo Garcia PatiÃ±o Lenza
// Usuario del Juez A34


#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include "set_eda.h"
using namespace std;


// Resuelve un caso de prueba, leyendo de la entrada la
// configuracioÌ�n, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
	int tam;
	cin >> tam;
	if(tam == 0){
		return false;
	}
	else{
		set<int> orig;
		int num;
		for(int i = 0; i < tam; i++){
			cin >> num;
			orig.insert(num);
		}

		cin >> tam;

		for(int i = 0; i < tam; i++){
			cin >> num;
			pair<bool, int> p = orig.lower_bound(num);
			if(p.first){
				cout << p.second << endl;
			}
			else{
				cout << "NO HAY" << endl;
			}
		}
		cout << "---"  << endl;
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

     while(resuelveCaso()){}

    // Para restablecer entrada. Comentar para acepta el reto
     #ifndef DOMJUDGE // para dejar todo como estaba al principio
     std::cin.rdbuf(cinbuf);
     system("PAUSE");
     #endif

    return 0;
}
