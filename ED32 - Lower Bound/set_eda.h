//
//  set_eda.h
//
//  Implementación de conjuntos utilizando árboles de búsqueda
//
//  Estructuras de Datos y Algoritmos
//  Facultad de Informática
//  Universidad Complutense de Madrid
//
//  Copyright (c) 2016-2018 Alberto Verdejo
//

#ifndef set_eda_h
#define set_eda_h

#include <algorithm>
#include <functional>
#include <stack>
#include <stdexcept>
using namespace std;
template <class T, class Comparator = std::less<T>>
class set {
   using set_t = set<T, Comparator>;

   /*
    Nodo que almacena internamente el elemento (de tipo T),
    y punteros al hijo izquierdo y derecho, que pueden ser
    nullptr si el hijo es vacío.
    */
   struct TreeNode;
   using Link = TreeNode *;
   struct TreeNode {
      T elem;
      Link iz, dr;
      TreeNode(T const& e, Link i = nullptr, Link d = nullptr) :
      elem(e), iz(i), dr(d) {}
   };

   // puntero a la raíz de la estructura jerárquica de nodos
   Link raiz;

   // número de elementos (cardinal del conjunto)
   size_t nelems;

   // objeto función que compara elementos (orden total estricto)
   Comparator menor;

public:

   // constructor (conjunto vacío)
   set(Comparator c = Comparator()) : raiz(nullptr), nelems(0), menor(c) {}

   // constructor por copia
   set(set_t const& other) {
      copia(other);
   }

   pair<bool,T> lower_bound(T const & e) const{
   		return resolver(e, this->raiz);
   	}

   // operador de asignación
   set_t & operator=(set_t const& that) {
      if (this != &that) {
         libera(raiz);
         copia(that);
      }
      return *this;
   }

   ~set() {
      libera(raiz);
   };

   bool insert(T const& e) {
      return inserta(e, raiz);
   }

   bool empty() const {
      return raiz == nullptr;
   }

   size_t size() const {
      return nelems;
   }

   size_t count(T const& e) const  {
      return pertenece(e, raiz) ? 1 : 0;
   }

   bool erase(T const& e) {
      return borra(e, raiz);
   }

protected:

   void copia(set_t const& other) {
      raiz = copia(other.raiz);
      nelems = other.nelems;
      menor = other.menor;
   }

   static Link copia(Link a) {
      if (a == nullptr) return nullptr;
      else return new TreeNode(a->elem, copia(a->iz), copia(a->dr));
   }

   static void libera(Link a) {
      if (a != nullptr){
         libera(a->iz);
         libera(a->dr);
         delete a;
      }
   }

   bool pertenece(T const& e, Link a) const {
      if (a == nullptr) {
         return false;
      }
      else if (menor(e, a->elem)) {
         return pertenece(e, a->iz);
      }
      else if (menor(a->elem, e)) {
         return pertenece(e, a->dr);
      }
      else { // e == a->elem
         return true;
      }
   }

   bool inserta(T const& e, Link & a) {
      if (a == nullptr) {
         a = new TreeNode(e);
         ++nelems;
         return true;
      }
      else if (menor(e, a->elem)) {
         return inserta(e, a->iz);
      }
      else if (menor(a->elem, e)) {
         return inserta(e, a->dr);
      }
      else // el elemento e ya está en el árbol
         return false;
   }

   bool borra(T const& e, Link & a)  {
      if (a == nullptr)
         return false;
      else {
         if (menor(e, a->elem)) {
            return borra(e, a->iz);
         }
         else if (menor(a->elem, e)) {
            return borra(e, a->dr);
         }
         else { // e == a->elem
            if (a->iz == nullptr || a->dr == nullptr) {
               Link aux = a;
               a = (a->iz == nullptr) ? a->dr : a->iz;
               --nelems;
               delete aux;
            }
            else { // tiene dos hijos
               subirMenorHD(a);
               --nelems;
            }
            return true;
         }
      }
   }

   static void subirMenorHD(Link & a) {
      Link b = a->dr, padre = nullptr;
      while (b->iz != nullptr) {
         padre = b;
         b = b->iz;
      }
      if (padre != nullptr) {
         padre->iz = b->dr;
         b->dr = a->dr;
      }
      b->iz = a->iz;
      delete a;
      a = b;
   }

public:
   // iterador que recorre los elementos del conjunto de menor a mayor
   class const_iterator {
   public:
      T const& operator*() const {
         if (act == nullptr)
            throw std::out_of_range("No hay elemento a consultar");
         return act->elem;
      }

      T const* operator->() const {
         return &operator*();
      }

      const_iterator & operator++() {  // ++ prefijo
         next();
         return *this;
      }

      bool operator==(const_iterator const& that) const {
         return act == that.act;
      }

      bool operator!=(const_iterator const& that) const {
         return !(this->operator==(that));
      }

   protected:
      friend class set;
      Link act;
      std::stack<Link> ancestros;  // antecesores no visitados

      // construye el iterador al primero
      const_iterator(Link raiz) { act = first(raiz); }

      // construye el iterador al último
      const_iterator() : act(nullptr) {}

      Link first(Link ptr) {
         if (ptr == nullptr) {
            return nullptr;
         } else { // buscamos el nodo más a la izquierda
            while (ptr->iz != nullptr) {
               ancestros.push(ptr);
               ptr = ptr->iz;
            }
            return ptr;
         }
      }

      void next() {
         if (act == nullptr) {
            throw std::out_of_range("El iterador no puede avanzar");
         } else if (act->dr != nullptr) { // primero del hijo derecho
            act = first(act->dr);
         } else if (ancestros.empty()) { // hemos llegado al final
            act = nullptr;
         } else { // podemos retroceder
            act = ancestros.top();
            ancestros.pop();
         }
      }
   };

   const_iterator begin() const {
      return const_iterator(raiz);
   }

   const_iterator end() const {
      return const_iterator();
   }

private:

   pair<bool,T> resolver(T const & e, Link l) const{
   		if(l == nullptr){
   			return pair<bool,T>(false, 0);
   		}
   		if(l->elem < e){
   			return resolver(e, l->dr);
   		}
   		else if(l->elem > e){
			T val = l->elem;
   			pair<bool,T> aux = resolver(e, l->iz);
   			if(!aux.first){
   				return pair<bool,T>(true, val);
   			}
   			else{
   				return aux;
   			}
   		}
   		else{
			T val = l->elem;
   			return pair<bool,T>(true, val);
   		}
   }

};


#endif // set_eda_h

//
//cout << " ESTOY EN " << val << " MIRANDO " << e << endl;
//   			//Si el valor que voy buscando es mayor que el de la raiz
//   			if(e > val){
//
//   				//Para encontrar el menor valor mayor que el que voy buscando tengo que bajar por la derecha
//   				if(l->dr != nullptr){
//   					if(e >= l->dr->elem){
//   						cout << "SIGO MIRANDO POR LA DERECHA" << endl;
//						return resolver(e, l->dr);
//   					}
//   					else{
//   						cout << "ME PARO EN ESTE" << endl;
//   						return pair<bool,T>(true, l->dr->elem);
//   					}
//   				}
//   				else{
//   					//Si no hay valor por la derecha que sea mas grande que el que voy buscando y el valor en el que
//   					//	me encuentro es menor, no va a haber ningun valor mas grande que el valor en el que estoy.
//   					//	Asi que devuelvo falso
//   					cout << "YA NO VOY A ENCONTRARLO" << endl;
//   					return pair<bool,T>(false, val);
//   				}
//   			}
//   			//Si el valor que voy buscando es menor que el de la raiz
//			else if(e < val){
//				//Para encontrar el menor valor mayor que el que voy buscando tengo que bajar por la izquierda
//				if(l->iz != nullptr){
//					if(l->iz->elem >= e){
//						cout << "SIGO MIRANDO POR LA IZQUIERDA" << endl;
//						//Si el elemento por el que bajo, que es menor que en el que estoy ahora sigue siendo mas
//						//	grande o igual al que busco, sigo bajando
//						return resolver(e, l->iz);
//					}
//					else{
//						cout << "ME PARO EN ESTE" << endl;
//						//Si el siguiente valor por la izquierda ya es mas pequeño, paro de bajar y este es el primero
//						//	mas grande
//						return pair<bool,T>(true, val);
//					}
//
//				}
//				else{
//					//Si no hay valor izquierdo que sea mas grande que el que voy buscando, no lo habra debajo
//					return pair<bool,T>(true, val);
//				}
//			}
//   			//Si el elemento que estoy buscando es el que estoy mirando, devuelvo true y el lower bound es el mismo
//			else{
//				cout << "ENCONTRADO" << endl;
//				return pair<bool,T>(true, e);
//			}
//   		}

// TODO SEGUNDO INTENTO
//
//if(l->iz == nullptr && l->dr == nullptr){
//   			if(val >= e){
//   				//Si la hoja es mayor o igual que lo que busco, he encontrado el valor que busco
//				return pair<bool,T>(true, val);
//   			}
//   			else{
//   				return pair<bool,T>(false,e);
//   			}
//   		}
//   		else{
//   			//Booleano que indica si ya he encontrado algun valor mayor que el que busco
//   			mayor = mayor || e < val;
//   			if(e > val){
//   				//Si este elemento es mayor que el que busco
//   				if(mayor){
//   					//Y he encontrado antes un valor mayor
//   					if(l->iz != nullptr){
//   						//Bajo por la izquierda
//   						return resolver(e, l->iz, mayor);
//   					}
//   					else{
//   						//Si no hay izquierda, es que este es el valor que busco
//   						return pair<bool,T>(true, val);
//   					}
//   				}
//   				else{
//   					//Y no he encontrado antes un valor mayor
//   					if(l->dr != nullptr){
//   						//Voy a bajar por la derecha para encontrar un valor mayor
//   						return resolver(e, l->dr, mayor);
//   					}
//   					else{
//   						//Si no hay derecha, no voy a encontrar un valor mayor
//   						return pair<bool,T>(false,e);
//   					}
//   				}
//   			}
//   			else if(e < val){
//   				//Si este elemento es menor que el que busco
//   				if(l->iz != nullptr){
//   					//Y si el siguiente elemento es mas pequeño que el que busco
//   					if(e > l->iz->elem){
//   						//Ya he encontrado el elemento que busco
//   	   					return pair<bool,T>(true, val);
//   					}
//   					else{
//   						//Si no, puedo seguir bajando por la izquierda hasta llegar al limite
//   						return resolver(e, l->iz, mayor);
//   					}
//   				}
//   				else{
//   					//Si el valor es igual que el que busco, lo he encontrado
//   					return pair<bool,T>(true, val);
//   				}
//   			}
//   			else{
//   				return pair<bool,T>(true, val);
//   			}
//
//
//
//   		}
