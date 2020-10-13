// Nombre del alumno Guillermo Garcia Patiño Lenza
// Usuario del Juez A34


#include <iostream>
#include <fstream>
#include <string>
#include "autoescuela.h"
using namespace std;

bool resuelveCaso() {

	autoescuela a;
	std::string operacion, nombre, profe;
	int puntos;

	std::cin >> operacion;
	if (!std::cin) return false;

	while (operacion != "FIN") {
		try {
			if (operacion == "alta") {
				cin >> nombre;
				cin >> profe;
				a.alta(nombre, profe);
			}
			else if (operacion == "es_alumno") {
				cin >> nombre;
				cin >> profe;
				bool b = a.es_alumno(nombre,profe);
				cout << nombre << " ";
				if(!b){cout << "no "; }
				cout<< "es alumno de " << profe << endl;
			}
			else if (operacion == "puntuacion") {
				cin >> nombre;
				int p = a.puntuacion(nombre);
				cout << "Puntuacion de " << nombre << ": " << p << endl;
			}
			else if (operacion == "actualizar") {
				cin >> nombre;
				cin >> puntos;
				a.actualizar(nombre,puntos);
			}
			else if (operacion == "aprobar"){
				cin >> nombre;
				a.aprobar(nombre);
			}
			else if (operacion == "examen"){
				cin >> nombre;
				cin >> puntos;
				vector<string> ex = a.examen(nombre,puntos);
				cout << "Alumnos de " << nombre << " a examen:" << endl;
				for(string s : ex){
					cout << s << endl;
				}
			}
		}
		catch (std::domain_error & e) {
			std::cout << "ERROR" << "\n";
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
