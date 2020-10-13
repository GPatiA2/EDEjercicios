/*
 * Guillermo Garcia Patiño Lenza
 * A34
 */

#ifndef FECHA_H_
#define FECHA_H_
#include <string>
using namespace std;

class fecha {
private:
	string hora;
	int dia;

public:

	fecha() : hora(""), dia(0){}
	fecha(int d, string h): hora(h), dia(d){}

	int getDia() const {
		return dia;
	}

	string getHora() const {
		return hora;
	}

	bool operator== (fecha const& other) const{
		return this->dia == other.dia && this->hora == other.hora;
	}

	bool operator < (fecha const & other) const{
		return (dia < other.dia) || (dia == other.dia && hora < other.hora);
	}

	bool operator!=  (fecha const& other) const{
		return !(*this == other);
	}
};


#endif /* FECHA_H_ */
