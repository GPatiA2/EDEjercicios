// Nombre del alumno Guillermo Garcia Patiño Lenza
// Usuario del Juez A34


#include <iostream>
#include <iomanip>
#include <fstream>
#include <stack>
using namespace std;

// función que resuelve el problema


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    	string texto;
    	getline(cin,texto);
    if (! std::cin){
        return false;
    }
    else{
    	stack<char> st;
//    	cout << texto << endl;
    	for(char c : texto){
    		if (c == '(' || c == '[' || c == '{')
    					st.push(c);
			else if (c == ')') {
				if (!st.empty() && st.top() == '(')
					st.pop();
				else {
					std::cout << "NO\n";
					return true;
				}
			}
			else if (c == ']') {
				if (!st.empty() && st.top() == '[')
					st.pop();
				else {
					std::cout << "NO\n";
					return true;
				}
			}
			else if (c == '}') {
				if (!st.empty() && st.top() == '{')
					st.pop();
				else {
					std::cout << "NO\n";
					return true;
				}
			}
    	}
    	if (st.size() == 0)
			std::cout << "SI\n";
		else
			std::cout << "NO\n";

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




