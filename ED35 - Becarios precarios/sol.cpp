// Nombre del alumno Guillermo Garcia PatiÃ±o Lenza
// Usuario del Juez A34


#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int resuelve(int jefes, int niv){
	int r;
	cin >> r;
	if(r == 0){
		//Si es becario y tiene mas niveles por encima que los jefes, devuelvo 1
		if(niv >= jefes){
			return 1;
		}
		else{
			return 0;
		}
	}
	else{
		int becariosPrecarios = 0;
		for(int i = 0; i < r; i++){
			becariosPrecarios += resuelve(jefes, niv+1);
		}
		//Los becariosPrecarios de un nodo son la suma de los becariosPrecarios de cada hijo
		return becariosPrecarios;
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracioÌ�n, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
	int jefes;
	cin >> jefes;
	if(!cin){
		return false;
	}
	else{
		cout << resuelve(jefes, 0) << endl;
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
