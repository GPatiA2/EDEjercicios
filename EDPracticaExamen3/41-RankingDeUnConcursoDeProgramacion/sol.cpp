// Nombre del alumno
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <unordered_map>
#include <set>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

struct teamInfo{
	int tiempoTotal;
	int correctos;

	teamInfo(){
		tiempoTotal = 0;
		correctos = 0;
	}

	bool operator>(teamInfo const& other){
		return correctos > other.correctos || (correctos == other.correctos && tiempoTotal < other.tiempoTotal);
	}
};


struct problemaInfo{
	int intentos;
	bool estado;
};

using equipo = string;
using problema = string;

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracioÌ�n, y escribiendo la respuesta
void resuelveCaso() {
	unordered_map<equipo, unordered_map<problema, problemaInfo>> envios;
	unordered_map<equipo, teamInfo> resultados;

	string t;
	string p;
	int tiempo;
	string result;
	bool correcto;
	cin >> t;
	while(t != "FIN"){
		cin >> p;
		cin >> tiempo;
		cin >> result;
		correcto = (result == "AC")? true : false;

		if(!envios.count(t)){
			envios[t] = {};
		}
		if(!envios[t].count(p)){
			envios[t][p] = {};
		}
		if(!resultados.count(t)){
			resultados[t] = {};
		}

		if(correcto && envios[t][p].estado == false){
			resultados[t].correctos += 1;
			resultados[t].tiempoTotal += tiempo + (envios[t][p].intentos*20);
			envios[t][p].estado = true;
		}
		else if(!correcto && envios[t][p].estado == false){
			envios[t][p].intentos += 1;
		}

		cin >> t;
	}

	vector<pair<equipo,teamInfo>> r;
	for(auto p : resultados){
		r.push_back(p);
	}

	sort(r.begin(), r.end(), [](pair<equipo,teamInfo> p1, pair<equipo,teamInfo> p2) {
		return p1.second.correctos > p2.second.correctos || (p1.second.correctos == p2.second.correctos && p1.second.tiempoTotal < p2.second.tiempoTotal);
	});

	for(auto p: r){
		cout << p.first << " " << p.second.correctos << " " << p.second.tiempoTotal << endl;
	}
	cout << "---" << endl;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
    #ifndef DOMJUDGE
     std::ifstream in("datos.txt");
     auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
     #endif


     int numcasos;
     cin >> numcasos;
     for(int i = 0; i < numcasos; i++){resuelveCaso();}

    // Para restablecer entrada. Comentar para acepta el reto
     #ifndef DOMJUDGE // para dejar todo como estaba al principio
     std::cin.rdbuf(cinbuf);
     system("PAUSE");
     #endif

    return 0;
}
