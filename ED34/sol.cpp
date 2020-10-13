// Nombre del alumno Guillermo Garcia PatiÃ±o Lenza
// Usuario del Juez A34


#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int resuelve(){
	int r;
	cin >> r;
	if(r == 0){
		return 1;
	}
	else{
		int alturaMax = 0;
		for(int i = 0; i < r; i++){
			alturaMax = max(alturaMax, resuelve());
		}
		return alturaMax +1;
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracioÌ�n, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada

	cout << resuelve() << endl;

	return true;

}


int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
    #ifndef DOMJUDGE
     std::ifstream in("datos.txt");
     auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
     #endif

    int numCasos;
    cin >> numCasos;
    for(int i = 0; i < numCasos; i++){
    	resuelveCaso();
    }



    // Para restablecer entrada. Comentar para acepta el reto
     #ifndef DOMJUDGE // para dejar todo como estaba al principio
     std::cin.rdbuf(cinbuf);
     system("PAUSE");
     #endif

    return 0;
}
