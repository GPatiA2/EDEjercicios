/*
 * set_ext.h
 *
 *  Created on: 2 abr. 2020
 *      Author: Guille
 */

#ifndef SET_EXT_H_
#define SET_EXT_H_
#include "set_eda.h"
using namespace std;

template<typename T>
class set_ext : public set<T> {
	using Link = typename set<T>::Link;

public:
	set_ext(){}

	pair<bool,T> lower_bound(T const & e) const{
		auto it = this->begin();
		int res = e;
		while(it != this->end){

		}
	}

private:

	pair<bool,T> resolver(T const & e, Link l) const{
		T val = l->elem;
		if(e > val){
			if(l->right != nullptr){
				return resolver(e, l->right);
			}
			else{
				return pair<bool,T>(true, val);
			}
		}
		else if(e < val){
			if(l->left != nullptr){
				return resolver(e, l->left);
			}
			else{
				return pair<bool,T>(false, e);
			}
		}
		else{
			return pair<bool,T>(true, e);
		}
	}

};

//auto it = this->begin();
//		auto end = this->end();
//		pair<bool,T>
//		while(it != end){
//			T value;
//			value = *it;
//			if(value >= e){
//
//			}
//		}



#endif /* SET_EXT_H_ */
