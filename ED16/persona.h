/*
 * persona.h
 *
 *  Created on: 9 mar. 2020
 *      Author: Guille
 */

#ifndef PERSONA_H_
#define PERSONA_H_
#include <iostream>
using namespace std;


class persona {
private:
	int edad;
	string nombre;

public:
	persona(){}
	persona(int e, string s) : edad(e), nombre(s){}

	int getEdad() const {return edad;}
	string getNombre() const {return nombre;}
};




#endif /* PERSONA_H_ */
