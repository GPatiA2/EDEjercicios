// Nombre del alumno Guillermo Garcia Patiño Lenza
// Usuario del Juez A34


#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "libreria.h"
using namespace std;

bool resuelveCaso() {

	int nInst;
	cin >> nInst;
	cin.ignore();
	if(!cin){return false;}
	string op;
	libreria l;
	for(int i = 0; i < nInst; i++){
		cin >> op;
		if(op == "nuevoLibro"){
			int ej ; cin >> ej;
			cin.ignore();
			string t; getline(cin,t);
			l.nuevoLibro(ej,t);
		}
		if(op == "comprar"){
			string t;
			cin.ignore();
			getline(cin,t);
			try{
				l.comprar(t,i);
			}
			catch (out_of_range & oof){
				cout << oof.what() << endl;
			}
			catch (invalid_argument & ia){
				cout << ia.what() << endl;
			}
		}
		if(op == "estaLibro"){
			cin.ignore();
			string t; getline(cin,t);
			if(l.estaLibro(t)){
				cout << "El libro " << t << " esta en el sistema" << endl;;
			}
			else{
				cout << "No existe el libro " << t << " en el sistema" << endl;
			}
		}
		if(op == "numEjemplares"){
			cin.ignore();
			string t; getline(cin,t);
			try{
				int n = l.numEjemplares(t);
				cout << "Existen " << n << " ejemplares del libro " << t << endl;
			}
			catch (invalid_argument & ia) {
				cout << "No existe el libro " << t << " en el sistema" << endl;
			}

		}
		if(op == "top10"){
			cout << "TOP10" << endl;
			vector<vInfo> v;
			l.top10(v);
			for(vInfo vi: v){
				cout << "    " << vi.titulo << endl;
			}
		}
		if(op == "elimLibro"){
			cin.ignore();
			string t; getline(cin,t);
			l.elimLibro(t);
		}
	}

	cout << "---" << endl;



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
