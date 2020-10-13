// Nombre del alumno Guillermo Garcia Patiño Lenza
// Usuario del Juez A34


#include <iostream>
#include <fstream>
#include <string>
#include "ipud.h"
using namespace std;

bool resuelveCaso() {


	string operacion;
	std::cin >> operacion;
	if (!std::cin) return false;
	ipud i;
	while (operacion != "FIN") {
//		cout << operacion << endl;
		try {
			if (operacion == "addSong") {
				string titulo; cin >> titulo;
				string artista; cin >> artista;
				int duracion; cin >> duracion;
				i.addSong(titulo, artista, duracion);
			}
			else if (operacion == "addToPlaylist") {
				string titulo; cin >> titulo;
				i.addToPlayList(titulo);
			}
			else if (operacion == "play") {
				string s = i.play();
				if(s == "No hay canciones en la lista"){
					cout << s << endl;
				}
				else{
					cout << "Sonando " << s << endl;
				}
			}
			else if (operacion == "totalTime") {
				int t = i.totalTime();
				cout << "Tiempo total " << t << endl;
			}
			else if (operacion == "deleteSong"){
				string titulo; cin >> titulo;
				i.deleteSong(titulo);
			}
			else if (operacion == "recent"){
				int num; cin >> num;
				vector<string> canciones = i.recent(num);
				if (!canciones.empty()) {
					cout << "Las " << min(num, i.getSize()) << " mas recientes" << endl;
					for(string s : canciones){
						cout << "    " << s << endl;
					}
				}
				else{
					cout << "No hay canciones recientes" << endl;
				}
			}
			else if (operacion == "current"){
				string s = i.current();
			}
		}
		catch (std::domain_error & e) {
			std::cout << "ERROR " << e.what() <<"\n";
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
