// Nombre del alumno Guillermo Garcia Patiño Lenza
// Usuario del Juez A34


#include <iostream>
#include <fstream>
#include <string>
#include "carnet_puntos.h"


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
		}
		catch (std::domain_error & e) {
			std::cout << "ERROR: " << e.what() << "\n";
		}
		std::cin >> operacion;
	}

	std::cout << "---\n";

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
