// Nombre del alumno
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <unordered_map>
using namespace std;

using dia = int;
using capitulo = int;

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
	int tamanio;
	cin >> tamanio;
	int maxDias = 0;
	int ini = 0;
	capitulo c;
	unordered_map<capitulo, dia> programacion;
	for(int i = 0; i < tamanio; i++){
		cin >> c;
		if(!programacion.count(c)){
			maxDias = max(maxDias, i-ini);
			programacion[c] = i;
		}
		else{
			maxDias = max(maxDias, i-ini);
			ini = programacion[c]+1;
			programacion[c] = i;
		}
	}
	cout << max(maxDias, tamanio-ini) << endl;

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
     system("PAUSE");
     #endif

    return 0;
}
