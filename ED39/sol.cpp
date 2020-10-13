// Nombre del alumno Guillermo Garcia Patiño Lenza
// Usuario del Juez A34


#include <iostream>
#include <iomanip>
#include <fstream>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;





using palabra = string;
using apariciones = set<int>;

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
	int lineas;
	cin >> lineas;
    cin.ignore();
	if (lineas == 0){
        return false;
    }
    else{
    	map<palabra, apariciones> ref;
    	for(int i = 0; i < lineas; i++){
    		string l;
    		getline(cin,l);
    		stringstream ss(l);
    		string p;
    		while(ss >> p){
    			//Pongo en minuscula todos los caracteres de la palabra p
    			//Entiendo que los corchetes '[]' de la lambda funcion indican que se recibe un array de chars
    			transform(p.begin(), p.end(), p.begin(), [](char c) -> char { return tolower(c);});

    			//Si la palabra no esta ya en el diccionario, añado un par clave-valor donde la clave es la palabra
    			//	y el valor es un conjunto que contiene la linea en la que aparece
    			if(!ref.count(p)){
    				apariciones a;
    				a.insert(i+1);
    				ref.insert(pair<palabra,apariciones>(p ,a));
    			}
    			//Si la palabra esta en el diccionario, obtengo el conjunto al que esta asociada, e inserto en ese conjunto
    			//	la linea en la que aparece
    			else{
    				auto e = ref.find(p);
    				e->second.insert(i+1);
    			}
    		}

    	}
    	for(auto par: ref){
    		//Voy recorriendo el diccionario
    		if(par.first.length() > 2){
    			//Para cada palabra de mas de dos letras, escribo la palabra
				cout << par.first << " ";
				//Y a continuacion, las lineas en las que aparece
				for(int e: par.second){
					cout << e << " ";
				}
				cout << endl;
    		}
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
