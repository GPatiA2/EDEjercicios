// Nombre del alumno Guillermo Garcia Patiño Lenza
// Usuario del Juez A34


#include <iostream>
#include <fstream>
#include <string>
#include "smartFarm2.h"
using namespace std;

bool resuelveCaso() {


	string operacion;
	std::cin >> operacion;
	if (!std::cin) return false;
	smartFarm2 sf;
	while (operacion != "FIN") {
		try {
			if (operacion == "alta") {
				string sector; cin >> sector;
				int p; cin >> p;
				sf.alta(sector, p);
			}
			else if (operacion == "datos") {
				string sector; cin >> sector;
				string plaga; cin >> plaga;
				int cant; cin >> cant;
				sf.datos(sector,plaga,cant);
			}
			else if (operacion == "fumigar") {
				vector<pair<string,string>> v = sf.fumigar();
				for(pair<string,string> p : v){
					cout << "Fumigar la plaga " << p.second << " del sector : " << p.first << endl;
				}
			}
			else if (operacion == "plagas") {
				string sector; cin >> sector;
				vector<pair<string,int>> v = sf.plagas(sector);
				cout << "Plagas del sector " << sector << " :";
				for(pair<string,int> p : v){
					cout << " " << p.first << " " << p.second;
				}
				cout << endl;
			}
		}
		catch (std::invalid_argument & e) {
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
