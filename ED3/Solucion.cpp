// Nombre del alumno Guillermo Garcia Patiño Lenza
// Usuario del Juez A34


#include <iostream>
#include <iomanip>
#include <fstream>

#include "complejo.h"
using namespace std;

template <typename T>
bool resolver(const Complejo<T> & c, int veces){
	bool pertenece = true;
	Complejo<T> aux(0,0);

	for(int i = 0; i < veces; i++){
		pertenece = pertenece && aux.valido();
		aux = (aux*aux);
		aux = aux + c;
	}
	pertenece = pertenece && aux.valido();
	return pertenece;
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta

void resuelveCaso() {
    // leer los datos de la entrada
	Complejo<float> c;
	int veces;
	cin >> c;
	cin >> veces;
	bool sol = false;
	Complejo<float> Zn(0,0);
	sol = resolver(c, veces);
    // escribir sol
	if(sol){cout << "SI\n" ;}
	else{cout << "NO\n" ;}

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
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();


    // Para restablecer entrada. Comentar para acepta el reto
     #ifndef DOMJUDGE // para dejar todo como estaba al principio
     std::cin.rdbuf(cinbuf);
     //system("PAUSE");
     #endif

    return 0;
}
