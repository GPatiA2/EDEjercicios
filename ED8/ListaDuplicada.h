/*
 *Guillermo Garcia Patiño Lenza
 *A34
 */

#ifndef LISTADUPLICADA_H_
#define LISTADUPLICADA_H_

#include "queue.h"
#include <iostream>
using namespace std;

template <typename T>
class ListaDuplicada : public queue<T>{
	using Nodo = typename queue<T>::Nodo;

public:
	void print (ostream & out = cout) const {
		Nodo * i = this->prim;

		while( i != nullptr){
			out << i->elem << " ";
			i = i->sig;
		}

	}

	void duplica(){
		Nodo * i;
		Nodo * ant;

		ant = this->prim;
		i = this->prim;

//		i = new Nodo(ant->elem, ant->sig);
//		ant->sig = i;
//		i = i->sig;

		while(i != nullptr){
			i = new Nodo(ant->elem, ant->sig);
			if(ant == this->ult){this->ult = i;}
			ant->sig = i;
			i = i->sig;
			ant = i;

		}
		this->nelems *= 2;
	}

};



#endif /* LISTADUPLICADA_H_ */
