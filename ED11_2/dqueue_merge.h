/*
 * dqueue_insert.h
 *
 *  Created on: 24 feb. 2020
 *      Author: Guille
 */

#ifndef DQUEUE_MERGE_H_
#define DQUEUE_MERGE_H_

#include "deque_eda.h"
#include <iostream>
using namespace std;


template <typename T>
class dqueue_merge : public deque<T> {
	using Nodo = typename deque<T>::Nodo;

public:
	void print(ostream & out = cout) const{
		if(!this->empty()){
			Nodo * aux = this->fantasma->sig;
			while(aux != this->fantasma){
				cout << aux->elem << " ";
				aux = aux->sig;
			}
		}
	}


	void merge(dqueue_merge & other){

		if(this->empty()){

			this->fantasma->sig = other.fantasma->sig;
			this->fantasma->ant = other.fantasma->ant;
			other.fantasma->sig->ant = this->fantasma;
			other.fantasma->ant->sig = this->fantasma;
		}
		else if(other.empty()){}
		else{
			Nodo * act1 = this->fantasma->sig;
			Nodo * act2 = other.fantasma->sig;

			if(act2->elem <= act1->elem){
				other.fantasma->sig = act2->sig;
				act2->sig->ant = other.fantasma;

				this->fantasma->sig = act2;
				act2->ant = this->fantasma;
				act2->sig = act1;
				act1->ant = act2;

			}

			act1 = this->fantasma->sig;
			act2 = other.fantasma->sig;
			Nodo * aux2 = act2;

			while(act2 != other.fantasma && act1 != this->fantasma){
				aux2 = act2->sig;
				if(act2->elem >= act1->elem && act1->sig->elem >= act2->elem){
					//Desacoplo el nodo act2 de la lista other
					act2->ant->sig = act2->sig;
					act2->sig->ant = act2->ant;

					//Inserto el nodo act2 en la lista this
					inserta_Nodo(act2, act1, act1->sig);

					//Avanzo act1 y act2
					act2 = aux2;
				}
				//Si no inserto entre act1 y act1->sig, avanzo act1 hasta encontrar un elemento menor que act2
				act1 = act1->sig;
			}
			if(act1 == this->fantasma){
				//Si he acabado con la lista this y todavia me quedan elementos de other sin insertar, es porque van
				// 	al final de la lista this
				this->fantasma->ant->sig = other.fantasma->sig;
				other.fantasma->sig->ant = this->fantasma->ant;

				other.fantasma->ant->sig = this->fantasma;
				this->fantasma->ant = other.fantasma->ant;
			}
			//Si he acabado de mirar la lista other y aun me quedan elementos de la lista other quiere decir
			// 	que los que me quedan de other son menores que todos los de la lista this. No deberia pasar puesto
			//	que me aseguro de que antes de empezar el merge, todos los elementos de la lista other que son menores
			//	que el primero de la lista this se insertan al principio
		}

		//Dejo la lista other vacia
		other.fantasma->sig = other.fantasma;
		other.fantasma->ant = other.fantasma;
		this->nelems += other.nelems;
		other.nelems = 0;
	}

	void inserta_Nodo(Nodo * in, Nodo * ant, Nodo * sig){
		in->ant = ant;
		ant->sig = in;
		sig->ant = in;
		in->sig = sig;
	}

};


#endif /* DQUEUE_MERGE_H_ */


