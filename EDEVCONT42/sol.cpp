// Nombre del alumno Guillermo Garcia Patiño Lenza
// Usuario del Juez A34


#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include "parqueNatural.h"
using namespace std;

bool resuelveCaso() {


	string operacion;
	std::cin >> operacion;
	if (!std::cin) return false;
	parqueNatural p;
	while (cin) {
		try {
			if (operacion == "an_ecosistema") {
				string ecosistema;
				cin >> ecosistema;
				p.an_ecosistema(ecosistema);
			}
			else if (operacion == "an_ejemplares") {
				string ecosistema; cin >> ecosistema;
				string especie; cin >> especie;
				int cantidad; cin >> cantidad;
				p.an_ejemplares(ecosistema, especie, cantidad);
			}
			else if (operacion == "lista_especies_ecosistema") {
				string ecosistema; cin >> ecosistema;
				int cantidad; cin >> cantidad;
				list<string> l = p.lista_especies_ecosistema(ecosistema, cantidad);
				cout << "Las ultimas " << cantidad << " especies del ecosistema " << ecosistema << endl;
				for(string s : l){
					cout << s << " ";
				}
				cout << endl;
			}
			else if (operacion == "numero_ejemplares_en_ecosistema") {
				string ecosistema; cin >> ecosistema;
				string especie; cin >> especie;
				int cantidad = p.numero_ejemplares_en_ecosistema(ecosistema, especie);
				cout << "En el ecosistema " << ecosistema << " hay " << cantidad << " de " << especie << endl;
			}
			else if (operacion == "lista_especies_parque") {
				list<string> esp = p.lista_especies_parque();
				cout << "En el parque hay " << endl;
				for(string s : esp){
					cout << s << " ";
				}
				cout << endl;
			}
			else if (operacion == "numero_ejemplares_en_parque") {
				string especie; cin >> especie;
				int cantidad = p.numero_ejemplares_en_parque(especie);
				cout << "En el parque hay " << cantidad << " de " << especie << endl;
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
