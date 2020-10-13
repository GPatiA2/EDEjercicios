
// NOMBRE Y APELLIDOS Guillermo Garcia Pati�o Lenza A34

// COMENTARIO SOBRE LA SOLUCIÓN Y SU COSTE JUSTIFICADO
/**
 * Resuelvo el problema llevando informacion desde abajo hasta arriba del arbol.
 * La informacion que devuelve como resultado la llamada recursiva es un par<bool,int> en el que el
 * 		primer bool representa si ese arbol es zurdo y el int representa el numero de nodos de ese arbol
 * De esta manera, puedo hacer siempre dos llamadas recursivas, una a cada hijo del arbol (exista o no), recibir la informacion
 * 		de los descendientes que tiene a la izquierda, los que tiene a la derecha, y si ambos subarboles son zurdos o no y decidir
 * 		si el arbol para el que estoy calculando es zurdo o no.
 * 		Despues, antes de devolver la informacion de esa llamada recursiva, sumo 1 al numero de nodos del arbol ya que tengo que contar
 * 			la raiz del que acabo de calcular como descendiente del que ha hecho esa llamada recursiva.
 *
 * 	En cuanto al coste, viene representado por la siquiente recurrencia (n, nder, niz son numeros de nodos del arbol, hijo derecho e hijo izquierdo)
 *
 * 		  { cte si n=0 o n=1  (Casos base de hoja y vacio)
 * 	T(n)= {
 * 		  { T(niz) + T(nder) + c en cualquier otro caso (Caso recursivo hace dos llamadas recursivas y operaciones constantes posteriores)
 *
 * 	Donde niz y nder en el caso peor son la pareja (0, n-1) en cualquier orden (el hijo derecho es degenerado y el izquierdo vacio o
 * 	viceversa). Al final, se visita cada nodo del arbol una sola vez y se realizan operaciones constantes en el. Por lo tanto, el
 * 	resultado de la recurrencia es O(n) donde n es el numero de nodos del arbol que paso como parametro para ver si es zurdo o no.
 */

#include <iostream>               
#include <fstream>               
#include <algorithm>
using namespace std;

#include "bintree_eda.h"


// Implementa aquí la función pedida. Puedes definir las funciones
// auxiliares que necesites

pair<bool,int> resolver(bintree<char> const & arb){
	if(arb.empty()){
		//Caso base de arbol vacio, tiene 0 descendientes y es zurdo
		return {true,0};
	}
	else if(arb.left().empty() && arb.right().empty()){
		//Caso base de hoja, tiene 0 descendientes y es zurdo.
		//Se devuelve 1 para que la llamada recursiva que ha hecho esta sepa cuantos descendientes tiene por este lado
		return {true,1};
	}
	else{
		//Caso recursivo (Todas las operaciones menos las llamadas recursivas son de coste constante)
		pair<bool,int> pI = resolver(arb.left()); //T(niz) se calcula para el lado izquierdo

		if(pI.first){ //Si el izquierdo es zurdo
			pair<bool,int> pD = resolver(arb.right()); //T(nder) se calcula para el lado derecho
			if(pD.first){
				int descendientes = pI.second + pD.second; //Calculo el total de descendientes
				if(pI.second > descendientes/2){ //Si mas de la mitad van por la izquierda
					return{true, descendientes+1}; //Devuelvo que es zurdo y que el nodo que ha hecho esta llamada recursiva tiene como
												   // desdencientes por este lado la suma de los descendientes de este nodo por la izquierda
												   // + los descendientes de este nodo por la derecha + el propio nodo
				}
				else{ //Si mas de la mitad de los nodos no estan por la izquierda
					//No es zurdo y no me interesa el numero de descendientes
					return{false,0};
				}
			}
			else{//Si el derecho no es zurdo, no es zurdo este
				return {false, 0};
			}
		}
		else{//Si no es zurdo
			 //No es zurdo y no me interesa el numero de descendientes
			return {false, 0};
		}
	}
}

bool zurdo(bintree<char> const & arb){
	pair<bool,int> p = resolver(arb);
	return p.first;
}


void resuelveCaso() {
   auto arbol = leerArbol('.');
   if (zurdo(arbol))
      cout << "SI\n";
   else
      cout << "NO\n";
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
   // system("PAUSE");
#endif
   return 0;
}
