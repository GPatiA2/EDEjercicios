/*
 * queue_invertir.h
 *
 *  Created on: 1 jun. 2020
 *      Author: Guille
 */

#ifndef QUEUE_INVERTIR_H_
#define QUEUE_INVERTIR_H_
#include "queue_eda.h"
#include <iostream>
using namespace std;

template <typename T>
class queue_invertir : public queue<T> {
	using Nodo = typename queue<T>::Nodo;

public:

	void invierte(){
		if(this->nelems > 1){
			Nodo * act = this->prim;
			Nodo * sig = this->prim->sig;
			this->prim = sig;
			act->sig = sig->sig;
			sig->sig = act;
			if(this->nelems > 2){
				Nodo * ant = act;
				act = act->sig;
				sig = act->sig;
				while(act != this->ult && sig != this->ult){

					act->sig = sig->sig;
					sig->sig = act;
					ant->sig = sig;

					ant = act;
					act = act->sig;
					sig = act->sig;
				}
				if(act != this->ult){
					act->sig = sig->sig;
					sig->sig = act;
					ant->sig = sig;
				}
			}
			else{
				this->ult = act;
			}
		}
	}

	void muestra() const {
		Nodo * aux = this->prim;
		while(aux != nullptr){
			cout << aux->elem << " ";
			aux = aux->sig;
		}
	}

};


#endif /* QUEUE_INVERTIR_H_ */
