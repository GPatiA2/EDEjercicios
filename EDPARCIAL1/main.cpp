
// NOMBRES Y APELLIDOS: Guillermo Garcia Pati�o Lenza A34

// COMENTARIO SOBRE LA SOLUCIÓN Y SU COSTE JUSTIFICADO
/*
 * Este problema se parece mucho al merge entre listas enlazadas dobles.
 * Usare un bucle que recorre ambas listas a la vez, en el que inserto un nodo de other delante de cada uno de this.
 *
 * El coste del problema es O(n) donde n es el numero de nodos que tiene la cola this, ya que por cada nodo de this,
 * 		tengo que insertar un nodo de los de other delante del de this.
 * (Todas las instrucciones de dentro del bucle son de coste constante, incluidas las de la funcion insert ,
 * 		asi que el coste del bucle es O(cte*n) = O(n) donde n es el numero de nodos de la cola this.
 * 		Fuera del bucle todas las instrucciones son tambien de coste cte,asi que el coste total del problema
 * 		es O(n) donde n es el numero de nodos de la cola this.)
 *
 */

#include <iostream>                              
#include <fstream>               
#include <algorithm>
using namespace std;

#include "deque_eda.h"

class EntremezclarListas : public deque<int> {
public:
   // imprime la lista
   void print(std::ostream& o = std::cout) const {
	   Nodo * aux = this->fantasma->sig;
		while(aux != this->fantasma){
			o << aux->elem << " ";
			aux = aux ->sig;
		}
   }

   // modifica this para entremezclar sus elementos con los de other
   void entremezclar(EntremezclarListas & other) {
	   //Saco punteros a los primeros elementos
	   	   	   //primero this
	   Nodo * primT = this->fantasma->sig;
	   	   	   //primero other
	   Nodo * primO = other.fantasma->sig;

		Nodo * auxT;
		Nodo * auxO;

		while(primT != this->fantasma && primO != other.fantasma){
			//Me guardo en los auxiliares los siguientes nodos en las listas
			auxT = primT->sig;
			auxO = primO->sig;

			//Extraigo de la cola other el nodo que voy a insertar
			//Lo tengo guardado en primO
			primO->sig->ant = primO->ant;
			primO->ant->sig = primO->sig;

			//Inserto primO entre primT y su siguiente
			insert(primT, primO, primT->sig);

			//Restauro primT y primO a los siguientes nodos
			primT = auxT;
			primO = auxO;
		}

		//Si me quedan elementos por insertar de other, los inserto al final de this
		//Para ello engancho el primer nodo que me queda en other como siguiente al ultimo de this
		// Y engancho el ultimo nodo de la cola other como anterior del fantasma de this.
		if(primO != other.fantasma){
			primO->ant = this->fantasma->ant;
			this->fantasma->ant->sig = primO;

			this->fantasma->ant = other.fantasma->ant;
			other.fantasma->ant->sig = this->fantasma;
		}

		//Me aseguro de que other queda completamente vacia
		other.fantasma->sig = other.fantasma;
		other.fantasma->ant = other.fantasma;

		//Actualizo el recuento de nodos de ambas listas
		this->nelems += other.nelems;
		other.nelems = 0;
   }
   
private:

   //Inserta un nodo ins entre ant y sig.
   //Para que funcione bien, la cola de la que procede ins no debe tener ningun puntero apuntando a ins.
   void insert(Nodo * ant, Nodo * ins, Nodo * sig){
   		ant->sig = ins;
   		ins->ant = ant;

   		sig->ant = ins;
   		ins->sig = sig;
   	}
};


/////////////////////////////////////////////////////////
// de aquí hacia abajo NO se puede modificar nada

inline std::ostream& operator<<(std::ostream & o, EntremezclarListas const& a) {
   a.print(o);
   return o;
}

EntremezclarListas leerLista() {
   EntremezclarListas lista;
   int n, val;
   cin >> n; // tamaño
   while (n--) {
      cin >> val;
      lista.push_back(val);
   }
   return lista;
}

void resuelveCaso() {
   auto lista1 = leerLista();
   auto lista2 = leerLista();
   
   lista1.entremezclar(lista2);
   
   cout << lista1 << '\n';
}


int main() {
   // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
   std::ifstream in("casos.txt");
   auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
   
   int casos;
   cin >> casos;
   for (int i = 0; i < casos; ++i) {
      resuelveCaso();
   }

   // para dejar todo como estaba al principio
#ifndef DOMJUDGE
   std::cin.rdbuf(cinbuf);
 //  system("PAUSE");
#endif
   return 0;
}
