/*
 * bintree_frt.h
 *
 *  Created on: 11 mar. 2020
 *      Author: Guille
 */

#ifndef BINTREE_FRT_H_
#define BINTREE_FRT_H_

#include "bintree_eda.h"
#include <vector>
using namespace std;

template <typename T>

class bintree_frt : public bintree<T> {
	using Link = typename bintree<T>::Link;

public:

	bintree_frt(){}
	bintree_frt(bintree_frt<T> const & lt, T const & r, bintree_frt<T> const & rt) : bintree<T>(lt,r,rt) {}

	vector<T> frontera() const {
		vector<T> frontera;
		calcFrontera(this->raiz, frontera);
		return frontera;
	}

private:

	void calcFrontera(Link l, vector<T> & frontera) const {
		if(l == nullptr){
			//No hago nada y vuelvo
		}
		else{
			if(l->left == nullptr && l->right == nullptr){
				//Meto en el vector frontera el elemento por el final
				frontera.push_back(l->elem);
			}
			else{
				calcFrontera(l->left, frontera);
				calcFrontera(l->right,frontera);
			}
		}

	}
};

// lee un árbol binario de la entrada estándar
template <typename T>
inline bintree_frt<T> leerArbol_frontera(T vacio) {
   T raiz;
   std::cin >> raiz;
   if (raiz == vacio) { // es un árbol vacío
      return {};
   } else { // leer recursivamente los hijos
      auto iz = leerArbol_frontera(vacio);
      auto dr = leerArbol_frontera(vacio);
      return {iz, raiz, dr};
   }
}



#endif /* BINTREE_FRT_H_ */
