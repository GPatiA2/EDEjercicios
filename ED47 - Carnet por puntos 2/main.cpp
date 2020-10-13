// Nombre del alumno Guillermo Garcia Patiño Lenza
// Usuario del Juez A34


#include <iostream>
#include <fstream>
#include <string>
#include "carnet_puntos.h"
using namespace std;

bool resuelveCaso() {


	carnet_puntos carnet;
	std::string operacion, dni;
	int puntos;

	std::cin >> operacion;
	if (!std::cin) return false;

	while (operacion != "FIN") {
		try {
			if (operacion == "nuevo") {
				std::cin >> dni;
				carnet.nuevo(dni);
			}
			else if (operacion == "cuantos_con_puntos") {
				std::cin >> puntos;
				int sol = carnet.cuantos_con_puntos(puntos);
				std::cout << "Con " << puntos << " puntos hay " << sol << "\n";
			}
			else if (operacion == "quitar") {
				std::cin >> dni >> puntos;
				carnet.quitar(dni, puntos);
			}
			else if (operacion == "consultar") {
				std::cin >> dni;
				int sol = carnet.consultar(dni);
				std::cout << "Puntos de " << dni << ": " << sol << "\n";
			}
			else if (operacion == "recuperar"){
				cin >> dni;
				cin >> puntos;
				carnet.recuperar(dni, puntos);
			}
			else if (operacion == "lista_por_puntos"){
				cin >> puntos;
				const list<string> v = carnet.lista_por_puntos(puntos);
				cout << "Tienen " << puntos << " puntos:";

					for(string s : v){
						cout << " " << s;
					}

				cout << endl;
			}
		}
		catch (std::domain_error & e) {
			std::cout << "ERROR: " << e.what() << "\n";
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
