// Nombre del alumno Guillermo Garcia Patiño Lenza
// Usuario del Juez A34


#include <iostream>
#include <iomanip>
#include <fstream>
#include <map>
#include <vector>
using namespace std;


// funcioÌ�n que resuelve el problema
using alumno = string;
using puntos = int;

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracioÌ�n, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int ejercicios;
    cin >> ejercicios;
    if (ejercicios == 0){
        return false;
    }
    else{
    	string aux;
		map<alumno,puntos> correccion;
		for(int i = 0; i < ejercicios; i++){
			alumno a;
			string ej;

			getline(cin, a);
			getline(cin, a);
			cin >> ej;

			if(ej == "CORRECTO"){
				++correccion[a];
			}
			else if(ej == "INCORRECTO"){
				--correccion[a];
			}

		}
		for(auto const& e : correccion){
			if(e.second != 0)cout << e.first << ", " << e.second << endl;
		}
		cout << "---" << endl;
    }
    
    
    // escribir sol
    
    
    return true;
    
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
