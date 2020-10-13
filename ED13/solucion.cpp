// Nombre del alumno Guillermo Garcia Patiño Lenza
// Usuario del Juez A34


#include <iostream>
#include <iomanip>
#include <fstream>
#include "queue_eda.h"
#include <stack>
using namespace std;

// función que resuelve el problema
void resolver(queue<int> & orig) {
	stack<int> negativos; //Uso una pila para los negativos porque el cuanto mayor valor absoulto de un negativo
						  //Menor es el numero en valor absoluto
	queue<int> positivos;//Uso una cola para los positivos porque el orden de la cola original se conserva para ellos
	while(!orig.empty()){
		int a = orig.front();
		if(a >= 0){
			positivos.push(a);
		}
		else{
			negativos.push(a);
		}
		orig.pop();
	}
	while(!negativos.empty()){
		int a = negativos.top();
		orig.push(a);
		negativos.pop();
	}
	while(!positivos.empty()){
		int a = positivos.front();
		orig.push(a);
		positivos.pop();
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
	int tamanio;
	cin >> tamanio;
    if (tamanio == 0){
        return false;
    }
    else{
    	queue<int> original;
    	int aux;
    	for(int i = 0; i< tamanio; i++){
    		cin >> aux;
    		original.push(aux);
    	}

		resolver(original);

		while(!original.empty()){
			cout << original.front() << " ";
			original.pop();
		}
		cout << endl;
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



