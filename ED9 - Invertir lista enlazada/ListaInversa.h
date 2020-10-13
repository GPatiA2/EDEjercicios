/*
 *Guillermo Garcia Patiño Lenza
 *A34
 */

#ifndef LISTAINVERSA_H_
#define LISTAINVERSA_H_

#include "queue.h"
#include <stack>
#include <iostream>
using namespace std;

template <typename T>
class ListaInversa : public queue<T>{
	using Nodo = typename queue<T>::Nodo;

public:
	void print (ostream & out = cout) const {
		Nodo * i = this->prim;

		while( i != nullptr){
			out << i->elem << " ";
			i = i->sig;
		}

	}

	void invierte(){
		if(!this->empty() && this->nelems > 1){
			Nodo * aux = this->prim;
			Nodo * ultaux = this->ult;
			Nodo * ultinsertado = nullptr;

			//Primero pongo el primer nodo como el último

			this->prim = this->prim->sig;
			this->ult->sig = aux;
			aux->sig = nullptr;
			this->ult = aux;
			ultinsertado = aux;

			aux = this->prim;

			//Voy a ir insertando entre el ultimo y el que acabo de insertar
			//  en orden de izquierda a derecha hasta llegar al elemento que era el ultimo originalmente

			while(aux != ultaux){
				this->prim = this->prim->sig; //Avanzo el primero
				ultaux->sig = aux;			  //El siguiente del ultimo original es el que estoy insertando
				aux->sig = ultinsertado;	  //El siguiente del que estoy insertando es el ultimo que inserté
				ultinsertado = aux;			  //Actualizo el ultimo que inserté
				aux = this->prim;			  //Voy a insertar ahora el que queda primero
			}
		}

	}

};



#endif /* LISTAINVERSA_H_ */

//
//stack<Nodo *> st;
//		Nodo * aux = this->prim;
//		while(aux != nullptr){
//			st.push(aux);
//			aux = aux->sig;
//		}
//
//		this->prim = st.top();
//		this->ult = st.top();
//		this->ult->sig = nullptr;
//		while(!st.empty()){
//			this->ult->sig = st.top();
//			st.pop();
//			this->ult = this->ult->sig;
//			this->ult->sig = nullptr;
//
//		}
