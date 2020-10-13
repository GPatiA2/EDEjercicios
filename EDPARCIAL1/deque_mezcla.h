/*
 * deque_mezcla.h
 *
 *  Created on: 4 jun. 2020
 *      Author: Guille
 */

#ifndef DEQUE_MEZCLA_H_
#define DEQUE_MEZCLA_H_
#include "deque_eda.h"
using namespace std;

template <typename T>
class deque_mezcla : public deque<T>{
	using Nodo = typename deque<T>::Nodo;
public:

	void entremezclar(deque<T> & other){
		Nodo * primT = this->fantasma->sig;
		Nodo * primO = other.fantasma->sig;

		Nodo * auxT;
		Nodo * auxO;

		while(primT != this->fantasma && primO != other.fantasma){
			auxT = primT->sig;
			auxO = primO->sig;

			primO->sig->ant = primO->ant;
			primO->ant->sig = primO->sig;
			insert(primT, primO, primT->sig);

			primT = auxT;
			primO = auxO;
		}

		if(primO != other.fantasma){
			insert(primT, primO, primT->sig);
		}

		other.fantasma->sig = other->fantasma;
		other.fantasma->ant = other->fantasma;

	}

	void print(){
		Nodo * aux = this->fantasma->sig;
		while(aux != this->fantasma){
			cout << *aux << " ";
			aux = aux ->sig;
		}
	}

private:

	void insert(Nodo * ant, Nodo * ins, Nodo * sig){
		ant->sig = ins;
		ins->ant = ant;

		sig->ant = ins;
		ins->sig = sig;
	}

};



#endif /* DEQUE_MEZCLA_H_ */
