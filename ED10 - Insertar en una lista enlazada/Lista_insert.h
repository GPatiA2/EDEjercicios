/*
 * Guillermo Garcia Patiño Lenza
 * A34
 */

#ifndef LISTA_INSERT_H_
#define LISTA_INSERT_H_

#include "queue_eda.h"
#include <stdexcept>
#include <iostream>
using namespace std;

template <typename T>
class Lista_insert : public queue<T>{
	using Nodo = typename queue<T>::Nodo;

public:

	void print(ostream & out = cout){
		Nodo * aux = this->prim;
		while(aux != nullptr){
			out << aux->elem << " ";
			aux = aux->sig;
		}
	}

	void insert_in_pos(int pos, Lista_insert & other){

		//Inserto
		if(pos == 0){

			//Si la posicion en la que tengo que insertar es la 0
			//  El primero de la nueva lista es el primero de la lista que inserto
			//	El ultimo de la lista que inserto tiene como siguiente al primero de la lista original
			other.ult->sig = this->prim;
			this->prim = other.prim;
		}
		else if(pos == this->nelems){

			//Si la posicion en la que inserto es la ultima
			//	El ultimo de la lista original tiene como siguiente al primero de la lista que inserto
			//	El ultimo de la nueva lista es el ultimo de la lista que inserto
			this->ult->sig = other.prim;
			other.ult = nullptr;
		}
		else{
			//Si no inserto ni en la primera ni en la ultima

			//Declaro dos punteros a nodos auxiliares
			Nodo * aux = this->prim;			//Apunta al nodo anterior a la posicion donde inserto
			Nodo * sigaux =  this->prim->sig;	//Apunta al nodo siguiente a la posicion donde inserto


			//Pongo aux al nodo anterior a la posicion donde inserto y sigaux al siguiente
			for(int i = 0; i < pos-1; i++){
				aux = sigaux;
				sigaux = sigaux->sig;
			}



			//Engancho la lista que tengo que insertar entre las dos posiciones
			aux->sig = other.prim;
			other.ult->sig = sigaux;
		}


		//Vacio la lista que acabo de insertar
		other.prim = nullptr;
		other.ult = nullptr;

		this->nelems += other.nelems;
	}

};


#endif /* LISTA_INSERT_H_ */


//if(pos == 0){
//			aux = this->prim;
//			sigaux = this->prim;
//		}
//		else{
//			aux = this->prim;
//			int i = 0;
//			while(i < pos-1) {
//				aux = aux->sig;
//				i++;
//			}
//			sigaux = aux->sig;
//		}
//		cout << "Inserto entre " << aux->elem << " - " << sigaux->elem <<endl;
//
//		//Comienzo a insertar
//		Nodo * insertando;
//		while(other.prim != nullptr){
//			insertando = other.prim;
//			other.prim = other.prim->sig;
//
//		}
