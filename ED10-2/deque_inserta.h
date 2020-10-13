/*
 * deque_inserta.h
 *
 *  Created on: 22 feb. 2020
 *      Author: Guille
 */

#ifndef DEQUE_INSERTA_H_
#define DEQUE_INSERTA_H_

#include "deque.h"
using namespace std;

template <typename T>
class deque_inserta : public deque<T>{
	using Nodo = typename deque<T>::Nodo;

public:
	void print(ostream & out = cout) const{
		Nodo * aux = this->fantasma->sig;
		while(aux != this->fantasma){
			out << aux->elem << " ";
			aux = aux->sig;
		}
	}

	void insert_in_pos(deque_inserta<int> & other, int pos){

		//Seguramente pueda hacerlo todo en de una sola manera cambiando el puntero aux segun toque
		if(pos == 0){
			//Si la posicion es 0 engancho la lista que inserto detras del nodo fantasma
			other.fantasma->ant->sig = this->fantasma->sig;
			this->fantasma->sig = other.fantasma->sig;
			this->fantasma->sig->ant = this->fantasma;
			other.fantasma->ant->sig->ant = other.fantasma->ant;
		}
		else if(pos == this->nelems){
			//Si inserto en la ultima posicion engancho la lista que inserto al final de la otra
			this->fantasma->ant->sig = other.fantasma->sig;
			other.fantasma->sig->ant = this->fantasma->ant;
			other.fantasma->ant->sig = this->fantasma;
			this->fantasma->ant = other.fantasma->ant;
		}
		else{
			//Si no, busco donde tengo que enganchar la lista y conecto los nodos.
			int insert = 0;
			Nodo * aux = this->fantasma->sig;
			while(insert < pos-1){
				aux = aux->sig;
				insert++;
			}

			other.fantasma->ant->sig = aux->sig;
			aux->sig = other.fantasma->sig;
			aux->sig->ant = aux;
			other.fantasma->ant->sig->ant = other.fantasma->ant;
		}
		//Al final, dejo la lista que inserto vacia
		other.fantasma->sig = other.fantasma;
		other.fantasma->ant = other.fantasma;
		//Sumo al numero de elementos
		this->nelems += other.nelems;
	}

};



#endif /* DEQUE_INSERTA_H_ */
