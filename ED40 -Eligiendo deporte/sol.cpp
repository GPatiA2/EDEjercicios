// Nombre del alumno Guillermo Garcia Patiño Lenza
// Usuario del Juez A34


#include <iostream>
#include <iomanip>
#include <fstream>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
// funcioÌ�n que resuelve el problema

using deporte = string;
using alumno = string;
using miembros = int;

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracioÌ�n, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    string leido;
    cin >> leido;
    if (! std::cin){
        return false;
    }
    else{

    	map<alumno, deporte> alumnos; //Tabla que contiene a cada alumno, y el deporte en el que esta registrado
    	map<deporte, miembros> deportes; //Tabla que contiene los deportes y el numero de apuntados

    	deporte hoja = "";

    	while(leido != "_FIN_"){
    		//Si lo que he leido esta en mayuscula, es un deporte
			if(isupper(leido.at(0))){
				//Lo registro en la tabla de deportes con 0 miembros
				deportes[leido] = 0;
				//Guardo el deporte que estoy leyendo
				hoja = leido;
			}
			else{
				//Si se trata de un alumno que puede estar en algun deporte
				if(!alumnos.count(leido) && alumnos[leido] != "no"){
					//Que no esta registrado en mas de un deporte
					alumnos[leido] = hoja;
					deportes[hoja]++;
				}
				//Si el alumno esta en algun deporte diferente al que estoy ahora anotando
				else if(alumnos.count(leido) == 1 && alumnos[leido] != hoja && alumnos[leido] != "no"){
					//Registrado ya en un deporte
					deportes[alumnos[leido]]--;
					//Le resto uno a ese deporte
					alumnos[leido] = "no";
					//Y marco que ese alumno ya no puede estar en ningun deporte
				}
			}
			cin >> leido;
    	}
    	//Saco los pares a un vector
    	vector<pair<deporte,miembros>> v;
    	for(auto p : deportes){
    		v.push_back(p);
    	}

    	//Ordeno los pares
    	sort(v.begin(), v.end(), [](pair<deporte,miembros> p1, pair<deporte,miembros> p2)-> bool { return (p1.second > p2.second) || (p1.second == p2.second && p1.first < p2.first);});
    	for(auto d : v){
    		cout << d.first << " " << d.second << endl;
    	}
    	cout << "---" << endl;
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
    
    
    while (resuelveCaso())
        ;

    
    // Para restablecer entrada. Comentar para acepta el reto
     #ifndef DOMJUDGE // para dejar todo como estaba al principio
     std::cin.rdbuf(cinbuf);
     system("PAUSE");
     #endif
    
    return 0;
}
