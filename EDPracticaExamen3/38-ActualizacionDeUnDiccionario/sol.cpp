// Nombre del alumno
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <map>
#include <vector>
#include <string>
using namespace std;

using clave = string;
using valor = int;


map<clave,valor> leerMapa(){
	map<clave,valor> m;
	string linea;
	getline(cin, linea);
	stringstream ss(linea);

	clave c;
	valor v;
	while(ss >> c){
		ss >> v;
		cout << "CLAVE = " << c << " VALOR = " << v << endl;
		m.insert(pair<clave,valor>(c,v));
	}

	return m;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracioÌ�n, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
	map<clave,valor> m1 = leerMapa();
	map<clave,valor> m2 = leerMapa();

	auto it1 = m1.begin();
	auto it2 = m2.begin();

	vector<string> add;
	vector<string> sub;
	vector<string> change;

	while(it1 != m1.end() && it2 != m2.end()){

		if(it1->first == it2->first){
			if(it1->second != it2->second){
				change.push_back(it2->first);
			}
			it1++;
			it2++;
		}
		else if(it1->first > it2->first){
			add.push_back(it2->first);
			it2++;
		}
		else if(it1->first < it2->first){
			sub.push_back(it1->first);
			it1++;
		}
	}

	while(it1 != m1.end()){
		sub.push_back(it1->first);
		it1++;
	}

	while(it2 != m2.end()){
		add.push_back(it2->first);
		it2++;
	}

//	if((add.empty() && sub.empty() && change.empty())){
//		cout << "Sin cambios" << endl;
//	}
//	else{
//		if(!add.empty()){
			cout << "+";
			for(string s : add){
				cout << " " << s;
			}
			cout << endl;
//		}
//		if(!sub.empty()){
			cout << "-";
			for(string s : sub){
				cout << " " << s;
			}
			cout << endl;
//		}
//		if(!change.empty()){
			cout << "*";
			for(string s : change){
				cout << " " << s;
			}
			cout << endl;
//		}
//	}
	cout << "---" << endl;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
    #ifndef DOMJUDGE
     std::ifstream in("datos.txt");
     auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
     #endif


    int numCasos;
    std::cin >> numCasos;
    cin.ignore();
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();


    // Para restablecer entrada. Comentar para acepta el reto
     #ifndef DOMJUDGE // para dejar todo como estaba al principio
     std::cin.rdbuf(cinbuf);
     system("PAUSE");
     #endif

    return 0;
}
