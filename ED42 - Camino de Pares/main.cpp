
// Guillermo Garcia Patiño Lenza
// A34

#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

#include "bintree_eda.h"

//El problema se resuelve parecido al del diametro y al del subarbol competo mas grande de un arbol
//	Pero en este solo hay que contar si el camino es todo de numeros pares, y hay que tener en cuenta el camino mas largo
// 		en vez del corto


typedef struct{
	int act; //Indica la rama mas larga de pares hasta el momento
	int top; //Indica el camino mas largo hasta el momento
}tsol;

tsol resolver(bintree<int> const & arbol){

	tsol sol; sol.act = 0; sol.top = 0;

	//Caso Base
	if(arbol.left().empty() && arbol.right().empty()){
		if(arbol.root() % 2 == 0){
			return {1,1};
		}
		else{
			return {0,0};
		}
	}
	//Caso recursivo
	else{
		tsol sI; sI.act = 0; sI.top = 0;
		tsol sD; sD.act = 0; sD.top = 0;

		//Resuelvo para ambos lados del arbol
		if(!arbol.left().empty()){
			sI = resolver(arbol.left());
		}
		if(!arbol.right().empty()){
			sD = resolver(arbol.right());
		}

		//Si este nodo no contiene un par
		if(arbol.root() % 2 != 0){
			//Reinicio la cuenta del camino mas largo de pares
			sol.act = 0;
			//El camino mas largo es el maximo entre el camnio mas largo de la derecha y el de la izquierda
			sol.top = max(sI.top, sD.top);
		}
		else{
			//El camino mas largo es el maximo entre el de la izquierda y el de la derecha  + este nodo que es par
			sol.act = max(sD.act, sI.act)+1;

			int aux;
			//Calculo el camino mas largo como la suma del camino derecho + el camino del izquierdo + el nodo que los une
			aux = sD.act + sI.act + 1;

			//Hago el maximo entre ellos
			sol.top = max(max(sD.top, sI.top), aux);
		}
	}

	return sol;
}


int caminoPares(bintree<int> arbol) {
	if(!arbol.empty()){
		tsol s = resolver(arbol);
		return s.top;
	}
	else{
		return 0;
	}
}


void resuelveCaso() {
   bintree<int> arbol = leerArbol(-1);
   cout << caminoPares(arbol) << '\n';
}


int main() {
   // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
   std::ifstream in("casos.txt");
   auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
   
   int numCasos;
   cin >> numCasos;
   for (int i = 0; i < numCasos; ++i) {
      resuelveCaso();
   }

   // para dejar todo como estaba al principio
#ifndef DOMJUDGE
   std::cin.rdbuf(cinbuf);
   system("PAUSE");
#endif
   return 0;
}


