/*
 *Guillermo Garcia Patiño Lenza
 *A34
 */

#ifndef DEQUE_INVERSA_H_
#define DEQUE_INVERSA_H_

#include <iostream>
#include "deque_eda.h"
using namespace std;

template <typename T>
class deque_inversa : public deque<T>{
	using Nodo = typename deque<T>::Nodo;

public:

	void print(ostream & out = cout) const {
		Nodo * aux = this->fantasma->sig;
		while(aux != this->fantasma){
			out << aux->elem << " ";
			aux = aux->sig;
		}
	}

	void invierte(){
		/* Para invertir la lista enlazada doble, simplemente basta con intercambiar los punteros a anterior con los que
				 * apuntan a siguiente
				*/
		Nodo * act = this->fantasma;
		Nodo * next = act->sig;
		Nodo * aux;
		aux = act->ant;
		act->ant = act->sig;
		act->sig = aux;

		act = next;
		next = act->sig;

		while (act != this->fantasma)
		{
			aux = act->ant;
			act->ant = act->sig;
			act->sig = aux;

			act = next;
			next = act->sig;


		}

	}

	void swap(Nodo * n1, Nodo * n2){
		Nodo * n1ant = n1->ant;
		Nodo * n1sig = n1->sig;

		Nodo * n2ant = n2->ant;
		Nodo * n2sig = n2->sig;

		n1ant->sig = n2;
		n2ant->sig = n1;

		n1sig->ant = n2;
		n2sig->ant = n1;

		n1->sig = n2sig;
		n1->ant = n2ant;

		n2->ant = n1ant;
		n2->sig = n1sig;

	}

};



#endif /* DEQUE_INVERSA1_H_ */
