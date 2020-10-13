/*
 * bintree_contar.h
 *
 *  Created on: 10 mar. 2020
 *      Author: Guille
 */

#ifndef BINTREE_CONTAR_H_
#define BINTREE_CONTAR_H_

#include "bintree_eda.h"
using namespace std;

template <typename T>
class bintree_contar : public bintree<T>{
	using Link = typename bintree<T>::Link;


public:

	typedef struct{
		int altura;
		int hojas;
		int nodos;
	}tsol;



	void getParams(){
		tsol aux = calcular(*this);
		cout << aux.nodos << " " << aux.hojas << " " << aux.altura << endl;
	}

	tsol calcular(bintree<T> & este){
		tsol devolver;
		devolver.altura = 0;
		devolver.nodos = 0;
		devolver.hojas = 0;
		bintree<T> izq = este.left();
		bintree<T> der = este.right();

		if(!izq.empty()){
			tsol sol_izq = calcular(izq);
			devolver.nodos = sol_izq.nodos;
			devolver.hojas = sol_izq.hojas;
			devolver.altura = max(devolver.altura, sol_izq.altura)+1;
		}
		if(!der.empty()){
			tsol sol_der = calcular(der);
			devolver.nodos += sol_der.nodos;
			devolver.hojas += sol_der.hojas;
			devolver.altura = max(devolver.altura, sol_der.altura)+1;
		}
		if(der.empty() && izq.empty()){
			devolver.nodos = 1;
			devolver.hojas = 1;
			devolver.altura = 0;
		}

		return devolver;
	}


};




#endif /* BINTREE_CONTAR_H_ */
