// Nombre del alumno
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <map>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;


// Resuelve un caso de prueba, leyendo de la entrada la
// configuracioÌ�n, y escribiendo la respuesta
bool resuelveCaso() {
	int tamanio;
	cin >> tamanio;
	if(!cin){
		return false;
	}
	else{
		vector<map<int,int>::iterator> valores;
		map<int, int> repeticiones;
		int valor;
		for(int i = 0; i < tamanio; i++){
			cin >> valor;
			if(!repeticiones.count(valor)){
				repeticiones[valor] = 1;
				auto it = repeticiones.find(valor);
				valores.push_back(it);
			}
			else{
				repeticiones[valor]++;
			}
		}
		for(auto it : valores){
			cout << it->first << " " << it->second << endl;
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


     while(resuelveCaso()){}

    // Para restablecer entrada. Comentar para acepta el reto
     #ifndef DOMJUDGE // para dejar todo como estaba al principio
     std::cin.rdbuf(cinbuf);
     system("PAUSE");
     #endif

    return 0;
}
