
// Juan Antonio Escobar de los Angeles

// Primero guardamos el contenido en una cola doble teniendo en cuenta si el num de caracteres es par o impar
//para dar la vuelta al resultado o no, y despues se apilan las consonantes para desapilar cuando se encuentre una vocal o al final
// invirtiendo el orden de las vocales en O(n) siendo n el numero de caracteres

#include <iostream>
#include <fstream>
#include <string>
#include <stack> // propios o los de las estructuras de datos de clase
#include <deque>
using namespace std;

bool es_vocal(char c){
	return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
}

void volcar_pila(stack<char> & pila, std::string & resul) {
	while (!pila.empty()) {
		resul.push_back(pila.top());
		pila.pop();
	}
}
// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {

	// leer los datos de la entrada
	std::string cadena;
	getline(std::cin, cadena);
	if (!std::cin)  // fin de la entrada
		return false;

	deque<char> X;
	int cont = 0;
	if (cadena.size() % 2 != 0){
		for (int i = cadena.size(); i > 0; --i){
			if (cont % 2 == 0) X.push_front(cadena.at(i - 1));
			else X.push_back(cadena.at(i - 1));
			++cont;
		}

	}
	else{
		for (int i = cadena.size(); i > 0; --i){
			if (cont % 2 == 0) X.push_back(cadena.at(i - 1));
			else X.push_front(cadena.at(i - 1));
			++cont;
		}
	}

	stack<char> pila_consonantes;
	std::string resul;
	while(!X.empty()) {
		if (es_vocal(X.front())) {
			volcar_pila(pila_consonantes, resul);
			resul.push_back(X.front());
		}
		else{
			pila_consonantes.push(X.front());
		}
		X.pop_front();
	}
	volcar_pila(pila_consonantes, resul);
	// escribir sol
	std::cout << resul << "\n";
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
