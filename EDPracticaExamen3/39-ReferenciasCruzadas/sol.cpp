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

using palabra = string;
using apariciones = set<int>;

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracioÌ�n, y escribiendo la respuesta
bool resuelveCaso() {
	int nlineas;
	cin >> nlineas;
	if(nlineas == 0){
		return false;
	}
	else{
		cin.ignore();
		map<palabra,apariciones> ref;

		for(int i = 0; i < nlineas; i++){
			string linea;
			getline(cin,linea);
			stringstream ss(linea);
			palabra p;
			while(ss >>p){
				transform(p.begin(), p.end(), p.begin(), [](char c) -> char { return tolower(c);});
				if(p.length() > 2){
					if(!ref.count(p)){
						ref.insert({p,{}});
						ref[p].insert(i+1);
					}
					else{
						ref[p].insert(i+1);
					}
				}

			}
		}

		for(auto pair : ref){
			cout << pair.first;
			for(int i : pair.second){
				cout << " " << i;
			}
			cout << endl;
		}

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
