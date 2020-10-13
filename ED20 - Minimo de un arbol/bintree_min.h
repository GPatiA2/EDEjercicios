/*
 * bintree_min.h
 *
 *  Created on: 11 mar. 2020
 *      Author: Guille
 */

#ifndef BINTREE_MIN_H_
#define BINTREE_MIN_H_

#include "bintree_eda.h"
using namespace std;
template <typename T>


class bintree_min : public bintree<T> {
	using Link = typename bintree<T>::Link;

public:

	bintree_min(){}
	bintree_min(bintree_min<T> const & ltree , T const & elem, bintree_min<T> const & rtree) : bintree<T>(ltree, elem, rtree) {}

	T getMin() const {
		return calcMin(this->raiz);
	}

private:

	T calcMin(Link l) const {
		if(l->left == nullptr && l->right == nullptr){
			return l->elem;
		}
		else if(l->left == nullptr && l->right != nullptr){
			T aux = calcMin(l->right);
			if(aux < l->elem){return aux;}
			else{return l->elem;}
		}
		else if(l->left != nullptr && l->right == nullptr){
			T aux = calcMin(l->left);
			if(aux < l->elem){return aux;}
			else{return l->elem;}
		}
		else{
			T aux = calcMin(l->left);
			T aux2 = calcMin(l->right);
			if(aux2 < aux){aux = aux2;}
			if(aux < l->elem){return aux;}
			else{return l->elem;}
		}
	}

};

// lee un árbol binario de la entrada estándar
template <typename T>
inline bintree_min<T> leerArbol_min(T vacio) {
   T raiz;
   cin >> raiz;
   if (raiz == vacio) { // es un árbol vacío
      return {};
   } else { // leer recursivamente los hijos
      auto iz = leerArbol_min(vacio);
      auto dr = leerArbol_min(vacio);
      return {iz, raiz, dr};
   }
}




#endif /* BINTREE_MIN_H_ */
