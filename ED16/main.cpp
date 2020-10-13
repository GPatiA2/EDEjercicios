

// Nombre y Apellidos

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>

#include "persona.h"  // propios o los de las estructuras de datos de clase
#include "list_removeIF.h"

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {

	// leer los datos de la entrada
	int N, minimo, maximo;
	std::cin >> N >> minimo >> maximo;
	if (N == 0 && minimo == 0 && maximo == 0)
		return false;
	list_remove<persona> lista;
	int edad;
	std::string nombre;
	for (int i = 0; i < N; ++i)
	{
		std::cin >> edad;
		getline(std::cin.ignore(), nombre);
		persona p(edad, nombre);
		lista.push_back(p);
	}


	lista.remove_if([minimo, maximo](persona & p) -> bool{
		return !((p.getEdad() >= minimo) && (p.getEdad() <= maximo));
	});

	for (auto it : lista){
		std::cout << it.getNombre() << "\n";
	}
	// escribir sol
	std::cout << "---\n";
	return true;
}

int main() {
	// ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	while (resuelveCaso());

	// para dejar todo como estaba al principio
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}
