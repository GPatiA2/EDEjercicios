// Nombre del alumno Guillermo Garcia PatiÃ±o Lenza
// Usuario del Juez A34


#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree_eda.h"
#include <queue>
#include <cmath>
using namespace std;

// funcioÌ�n que resuelve el problema


typedef struct{
	int valor; //Valor del nodo accesible multiplo de 7 mas cercano a la raiz
	int nivel; //Nivel del nodo accesible multiplo de 7 mas cercano a la raiz
	bool encontrado; //Hay nodo accesible multiplo de 7 o no.
}tsol;

bool primo(int num){
	bool primo = true;
	int i = 2;
	while(i <= num/2 && primo){
		primo = !(num % i == 0);
		i++;
	}
	return primo;
}


tsol resolver(bintree<int> const & datos) {
	tsol sol;
	sol.valor = 0;
	sol.nivel = 0;
	sol.encontrado = false;


	bool pMarcado = false; //Este bool expresa si dentro de un nivel, he metido ya uno en la cola de
	//	siguientes marcado como primero del siguiente nivel

	//En la cola de pendientes voy a ir guardando pares de arboles y raiz
	queue<pair<bintree<int>,bool>> pendientes;

	//Meto la raiz en la cola de pendientes
	if(!datos.empty() && !primo(datos.root())){
		pair<bintree<int>,bool> p;
		p.first = datos;
		p.second = true;
		pMarcado = true;
		pendientes.push(p);
	}
	//Empieza el bucle de busqueda
	while(!pendientes.empty() && !sol.encontrado){
		//Saco el primer elemento pendiente
		pair<bintree<int>,bool> p = pendientes.front();
		int elem = p.first.root();
		bintree<int> act = p.first;
		pendientes.pop();

		//Tratamiento del nodo

			//El segundo valor del par de la cola expresa si este nodo es el primer pendiente de un nuevo nivel
		if(p.second){
			//Si es el primero de un nuevo nivel, sumo 1 a los niveles
			sol.nivel++;
			//Y reinicio, pues estoy en un nuevo nivel, y aun no he marcado al primero
			pMarcado = false;
		}

		//Compruebo si el elemento en el que estoy es valido
		if(elem % 7 == 0){
			sol.encontrado = true;
			sol.valor = elem;
		}

		//Meto los dos hijos en pendientes, primero el izquierdo y luego el derecho
		// 	Solo los meto en la cola de pendientes si no son primos
		//  Porque si son primos, voy a mirar por unos niveles que no me sirven para nada
		//		ya que el camino hasta el nodo no es valido

		if(!act.left().empty() && !primo(act.left().root())){
			pair<bintree<int>,bool> aux;
			aux.first = act.left();
			//Si estoy metiendo el hijo izquierdo de un nodo que se encuentra en un nivel en el cual
			// aun no he metido el primer elemento del siguiente, lo marco
			if(!pMarcado){
				aux.second = true;
			}
			else{
				aux.second =  false;
			}
			//Si acabo de meter un nodo en pendientes que es el siguiente de un nuevo nivel, pongo el bool pMarcado a true
			if(!pMarcado){
				pMarcado = true;
			}
			pendientes.push(aux);
		}

		//Igual para el hijo derecho
		if(!act.right().empty() && !primo(act.right().root())){
			pair<bintree<int>,bool> aux2;
			aux2.first = act.right();
			if(!pMarcado){
				aux2.second = true;
			}
			else{
				aux2.second = false;
			}
			if(!pMarcado){
				pMarcado = true;
			}
			pendientes.push(aux2);
		}



	}

	return sol;

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracioÌ�n, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
	bintree<int> datos = leerArbol(-1);
	tsol sol;

	sol = resolver(datos);

	if(sol.encontrado){
		cout << sol.valor << " " << sol.nivel;
	}
	else{
		cout << "NO HAY";
	}
	cout << endl;
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


////Si hay dos hijos
//		if(sD.existe && sI.existe){
//			//Si tienen los mismos niveles por debajo
//			if(sD.act == sI.act){
//				sol.act = max(sD.act,sI.act);
//				sol.act += 1;
//				sol.top = max(max(sD.top, sI.top),sol.act);
//			}
//			//Si no tienen los mismos niveles por debajo
//			else{
//				//Reinicio la cuenta a 2 (el nivel en el que estoy mas el de debajo)
//				sol.act = 2;
//				sol.top = max(max(sD.top, sI.top),sol.act);
//			}
//		}
//		//Si no
//		else{
//			//Actualizo el top y reinicio la cuenta
//			sol.top = max(max(sD.top, sI.top),sol.act);
//			sol.act = 1;
//		}
