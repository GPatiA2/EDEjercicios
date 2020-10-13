/*
 * Guillermo Garcia Patiño Lenza
 * A34
 */

#ifndef QUEUE_INSERT_H_
#define QUEUE_INSERT_H_

#include <iostream>
#include "queue_eda.h"
using namespace std;

template <typename T>
class queue_insert : public queue<T>{
	using Nodo = typename queue<T>::Nodo;

public:

	void print(ostream & out = cout ) const {
		Nodo * aux = this->prim;
		while(aux != nullptr){
			out << aux->elem << " ";
			aux = aux->sig;
		}

	}


	void merge (queue_insert<T> & other){


		Nodo * r1 = this->prim;
		Nodo * r2 = other.prim;
		Nodo * s1  =  r1;
		Nodo * next2;

		bool pre = false;

		if(this->empty()){
			this->prim = other.prim;
			this->ult = other.ult;
		}
		else if(other.empty()){}
		else{

			if(r2->elem <= r1->elem){
				other.prim = r2->sig;
				r2->sig = this->prim;
				this->prim = r2;
				r2 = other.prim;
				r1 = this->prim;
			}

			next2 = r2->sig;


			while (r2 != nullptr){ // Mientras no me acabe la segunda lista
				if (r1 == nullptr){ //Si me he acabado la primera
					//Engancho lo que me queda de la segunda
					s1->sig = r2;
					this->ult = other.ult;
					this->ult->sig = nullptr;
					r2 = nullptr;
				}
				else if (r1->elem <= r2->elem){ //Si me quedan elementos de la primera lista
												//Y si el elemento de la segunda es mas grande que el de la primera

					s1 = r1;					//Avanzo el r1
					r1 = r1->sig;
				}
				else{							//Si me quedan elementos de la primera lista
												//Y el elemento de la segunda es mas pequeño que el de la primera

					s1->sig = r2;				//Inserto el elemento de la segunda detras del de la primera
					next2 = r2->sig;
					r2->sig = r1;
					s1 = s1->sig;

					r2 = next2;
				}
			}

		}

		this->nelems += other.nelems;

		other.prim = nullptr;
		other.ult = nullptr;
		other.nelems = 0;

	}



};



#endif /* QUEUE_INSERT_H_ */

//
//
//
//while(r1 != nullptr && r2 != nullptr){
//		cout << "R1 ESTA EN " << r1->elem << " Y R2 ESTA EN " << r2->elem << endl;
//		if(r1->elem > r2->elem){
//			r1 = r1->sig;
//		}
//		else{
//			//Inserta delante
//			s1 = r1->sig;
//			s2 = r2->sig;
//
//			r2->sig = r1->sig;
//			r1->sig = r2;
//
//			r2 = s2;
//			r1 = s1;
//		}
//		print();
//		cout << endl;
//	}
//	if(r2 != nullptr){
//		cout <<"SE ME HA ACABADO EL R1" << endl;
//		cout << "TENGO R2 EN " << r2->elem << " Y S1 EN " << s1->elem << endl;
//		s1->sig->sig = r2;
//			s1 = r1->sig;
//			s2 = r2->sig;
//
//			r2->sig = r1->sig;
//			r1->sig = r2;
//
//			r2 = s2;
//			r1 = s1;
//	}
//	while(r1 != nullptr){
//		cout <<"SE ME HA ACABADO EL R1" << endl;
//		r1 = r1->sig;
//	}
