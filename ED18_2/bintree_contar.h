/*
 * bintree_contar.h
 *
 *  Created on: 11 mar. 2020
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
	bintree_contar(){}
	bintree_contar(bintree_contar<T> const & l, T const & e, bintree_contar<T> const & r): bintree<T>(l, e, r){}

	int getAltura() const{
		return altura(this->raiz);
	}

	int getNodos() const{
		return cuentaNodos(this->raiz);
	}

	int getHojas() const{
		return cuentaHojas(this->raiz);
	}

private:

	int cuentaNodos(Link l) const {
		if(l == nullptr){
			return 0;
		}
		else{
			int ltree = cuentaNodos(l->left);
			int rtree = cuentaNodos(l->right);
			return ltree+rtree+1;
		}
	}

	int cuentaHojas(Link l) const {
		if(l == nullptr){
			return 0;
		}
		else{
			if(l->left == nullptr && l->right == nullptr){
				return 1;
			}
			else{
				int ltree = cuentaHojas(l->left);
				int rtree = cuentaHojas(l->right);
				return ltree+rtree;
			}
		}
	}

	int altura(Link l) const {
		if(l == nullptr){
			return 0;
		}
		else{
			int ltree = altura(l->left);
			int rtree = altura(l->right);
			int h = 1 + max(ltree, rtree);
			return h;
		}
	}

};



// lee un árbol binario de la entrada estándar
template <typename T>
inline bintree_contar<T> leerArbol_contar(T vacio) {
   T raiz;
   std::cin >> raiz;
   if (raiz == vacio) { // es un árbol vacío
      return {};
   } else { // leer recursivamente los hijos
      auto iz = leerArbol_contar(vacio);
      auto dr = leerArbol_contar(vacio);
      return {iz, raiz, dr};
   }
}






#endif /* BINTREE_CONTAR_H_ */
