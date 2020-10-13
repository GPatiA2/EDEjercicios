//Guillermo Garcia Patiño Lenza
// A34

#ifndef DEUQE_ENGORDA_H_
#define DEUQE_ENGORDA_H_

#include<iostream>
#include "deque_eda.h"
using namespace std;

template <typename T>
class deque_engorda : public deque<T>{
	using Nodo = typename deque<T>::Nodo;

public:

	void print(ostream & out = cout) const{
		Nodo * aux = this->fantasma->sig;
		while(aux != this->fantasma){
			out << aux->elem << " ";
			aux = aux->sig;
		}
	}


	void engorda(deque_engorda & other){
		Nodo * aux = other.fantasma->sig;
		int i = 0;

		while(aux != other.fantasma){
			aux->ant->sig = aux->sig;
			aux->sig->ant = aux->ant;

			if(i % 2 == 0){ inserta(this->fantasma, aux, this->fantasma->sig);}
			else{ inserta(this->fantasma->ant, aux, this->fantasma);}

			aux = other.fantasma->sig;

			i++;
		}

		other.fantasma->sig = other.fantasma;
		other.fantasma->ant = other.fantasma;
		this->nelems += other.nelems;
		other.nelems = 0;

	}

	void inserta(Nodo * ant , Nodo * act, Nodo * sig){
		sig -> ant = act;
		act -> sig = sig;

		ant -> sig = act;
		act -> ant = ant;
	}

};



#endif /* DEUQE_ENGORDA_H_ */
