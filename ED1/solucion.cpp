/*
 * solucion.cpp
 *
 *  Created on: 31 ene. 2020
 *      Author: Guillermo Garcia Patiño Lenza
 */

// Nombre del alumno Guillermo Garcia Patiño Lenza
// Usuario del Juez A34


#include <iostream>
#include <iomanip>
#include <fstream>
#include "Hora.h"
using namespace std;

// función que resuelve el problema
void resolver(Hora horario[], Hora & consulta, int trenes) {
	int j = 0;
	bool salida = false;
	while(j < trenes && !salida){
		if(consulta <= horario[j]){
			cout << horario[j] << endl;
			salida = true;
		}
		j++;
	}
	if(!salida){
		cout << "NO" << endl;
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
	int trenes;
	int horas;
	cin >> trenes;
	cin >> horas;
	if (trenes == 0 && horas == 0){
		return false;
	}
	else{
		Hora horario[trenes];
//		cout << " LOS DOS PRIMEROS " << endl;
//		system("PAUSE");
		for(int i = 0; i < trenes; i++){
			cin >> horario[i];
		}
//		cout << " LOS HORARIOS " << endl;
//		system("PAUSE");
		for(int i = 0; i < horas; i++){
			try {
				Hora horaLeida;
				cin >> horaLeida;
				resolver(horario, horaLeida, trenes);
			}
			catch (invalid_argument & ia){
				cout << ia.what() << endl;
			}
		}
		cout << "---" << endl;
		return true;
	}
}

int main() {
//     Para la entrada por fichero.
//     Comentar para acepta el reto
    #ifndef DOMJUDGE
     std::ifstream in("datos.txt");
     auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
     #endif


    while (resuelveCaso())
        ;


//    // Para restablecer entrada. Comentar para acepta el reto
     #ifndef DOMJUDGE // para dejar todo como estaba al principio
     std::cin.rdbuf(cinbuf);
     system("PAUSE");
     #endif

    return 0;
}



