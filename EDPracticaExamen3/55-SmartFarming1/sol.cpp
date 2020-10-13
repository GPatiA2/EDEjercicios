// Nombre del alumno Guillermo Garcia Patiño Lenza
// Usuario del Juez A34


#include <iostream>
#include <fstream>
#include <string>
#include "smartFarm.h"
using namespace std;

bool resuelveCaso() {


	string operacion;
	std::cin >> operacion;
	if (!std::cin) return false;
	smartFarm sf;
	while (operacion != "FIN") {
		try {
			if (operacion == "alta") {
				string sector; cin >> sector;
				sf.alta(sector);
			}
			else if (operacion == "datos") {
				string sector; cin >> sector;
				string plaga ; cin >> plaga;
				sf.datos(sector, plaga);
			}
			else if (operacion == "fumigar") {
				string plaga; cin >> plaga;
				vector<string> p = sf.fumigar(plaga);
				cout << "Fumigar la plaga " << plaga << " en los sectores :";
				for(string s : p){
					cout << " " << s;
				}
				cout << endl;
			}
			else if (operacion == "plagas") {
				string sector; cin >> sector;
				vector<string> s = sf.plagas(sector);
				cout << "Plagas del sector " << sector << " :";
				for(string p : s){
					cout << " " << p;
				}
				cout << endl;
			}
		}
		catch (std::domain_error & e) {
			std::cout << "ERROR: " << e.what()  << "\n";
		}
		std::cin >> operacion;
	}

	cout << "---" << endl;;

	return true;
}

int main() {

	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif

	while (resuelveCaso());

	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	//system("PAUSE");
#endif

}
