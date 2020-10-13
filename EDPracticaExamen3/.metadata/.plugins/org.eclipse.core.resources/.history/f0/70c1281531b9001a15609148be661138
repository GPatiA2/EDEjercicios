// Nombre del alumno
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <map>
#include <set>
#include <algorithm>
#include <string>
using namespace std;

using pelicula = string;
using actor = string;
using tiempo = int;

struct actInfo{
	int tiempoTotal;
	string nombre;

	actInfo(string n){
		nombre = n;
		tiempoTotal = 0;
	}

	bool operator >(actInfo const& other){
		return tiempoTotal > other.tiempoTotal || (tiempoTotal == other.tiempoTotal && nombre > other.nombre);
	}

	bool operator ==(actInfo const& other){
		return nombre = other.nombre;
	}
};

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracioÌ�n, y escribiendo la respuesta
bool resuelveCaso() {
	int numpelis;
	cin >> numpelis;
	if(numpelis == 0){
		return false;
	}
	else{
		map<pelicula, map<actor, tiempo>> prog;
		set<actInfo> totales;
		for(int i = 0; i < numpelis; i++){
			string pelicula;
			int numActores;
			cin >> pelicula;
			cin >> numActores;
			for(int i = 0; i< numActores; i++){
				string actor;
				cin >> actor;
				int tiempo;
				cin >> tiempo;
				prog[pelicula][actor] = tiempo;
			}
		}
		int emisiones;
		cin >> emisiones;
		string peli;
		for(int i = 0; i < emisiones; i++){
			cin >> peli;
			for(auto it: prog[peli]){
				if(!totales.count(it.first)){
					totales.insert({it.first});
				}
				auto it2 = totales.find({it.first});
				it2->tiempoTotal += it.second;
			}
		}
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
