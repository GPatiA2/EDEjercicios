/*
 * bintree_min.h
 *
 *  Created on: 11 mar. 2020
 *      Author: Guille
 */

#ifndef BINTREE_DIAM_H_
#define BINTREE_DIAM_H_

#include "bintree_eda.h"
using namespace std;
template <typename T>


class bintree_per : public bintree<T> {
	using Link = typename bintree<T>::Link;

public:

	bintree_per(){}
	bintree_per(bintree_per<T> const & ltree , T const & elem, bintree_per<T> const & rtree) : bintree<T>(ltree, elem, rtree) {}

	int getDiametro() const {
		int act = 0;
		return calcDiam(this->raiz, act);
	}

private:
	//Esta funcion lleva en act la altura del arbol que estoy mirando
	// 	y devuelve la longitud del camino mas largo que hay en la zona del arbol que ya ha mirado
	int calcDiam(Link l, int & act) const {
		if(l == nullptr){
			//Si estoy en un arbol vacio, la longitud del camino / diametro es 0.
			act = 0;
			return 0;
		}
		else{
			//Si no, voy a calcular los caminos mas largos de los arboles derecho e izquierdo
			//	a la vez que calculo su altura
			int altDer = 0;
			int altIzq = 0;
			int ltree = calcDiam(l->left, altIzq);
			int rtree = calcDiam(l->right, altDer);

			//Entonces, la altura de lo que llevo mirado es el maximo entre la altura del
			//	izquierdo y la del derecho, +1 contando el nodo en el que estoy
			act = max(altIzq, altDer)+1;

			//Sabiendo las alturas de los arboles izquierdo y derecho, se que el camino mas largo es
			//	el maximo entre: el camino mas largo del arbol izquierdo, el camino mas largo del arbol derecho
			//	o la suma de las alturas mas 1.
			return max(max(ltree,rtree), altDer+altIzq+1);
		}
	}

};

// lee un árbol binario de la entrada estándar
template <typename T>
inline bintree_per<T> leerArbol_per(T vacio) {
   T raiz;
   cin >> raiz;
   if (raiz == vacio) { // es un árbol vacío
      return {};
   } else { // leer recursivamente los hijos
      auto iz = leerArbol_per(vacio);
      auto dr = leerArbol_per(vacio);
      return {iz, raiz, dr};
   }
}




#endif /* BINTREE_DIAM_H_ */
