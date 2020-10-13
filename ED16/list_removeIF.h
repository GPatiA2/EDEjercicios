/*
 * list_removeIF.h
 *
 *  Created on: 9 mar. 2020
 *      Author: Guille
 */

#ifndef LIST_REMOVEIF_H_
#define LIST_REMOVEIF_H_

#include "list_eda.h"

template <typename T>
class list_remove : public list<T>{

public:

	template<typename Predicate>
	void remove_if(Predicate pred){
		auto act = this->begin();
		while(act != this->end()){
			if(pred(*act)){
				act = this->erase(act);
			}
			else{
				act++;
			}
		}
	}

};



#endif /* LIST_REMOVEIF_H_ */
