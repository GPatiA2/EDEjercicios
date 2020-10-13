/*
 * Accidente.h
 *
 *  Created on: 13 feb. 2020
 *      Author: Guille
 */

#ifndef ACCIDENTE_H_
#define ACCIDENTE_H_

#include <iostream>
#include <iomanip>
using namespace std;

class Accidente{
private:
	int dia, mes, anyo, victimas;

public:
	Accidente(int dia, int mes, int anyo, int victimas) : dia(dia), mes(mes), anyo(anyo), victimas(victimas) {};
	Accidente(){};

	bool operator > (Accidente const & a2) const{
		return victimas > a2.victimas;
	}

	void setDia(int d){dia = d;}
	void setMes(int m){mes = m;}
	void setAnyo(int a){anyo = a;}
	void setVictimas(int v){victimas = v;}

	int getDia() const {return dia;}
	int getMes() const {return mes;}
	int getAnyo()const {return anyo;}
};

inline istream& operator>>(istream & in, Accidente & c){
	int dia;
	in >> dia;
	c.setDia(dia);

	in.ignore();

	int mes;
	in >> mes;
	c.setMes(mes);

	in.ignore();

	int anyo;
	in >> anyo;
	c.setAnyo(anyo);

	int victimas;
	in >> victimas;
	c.setVictimas(victimas);

	return in;
}

inline ostream& operator<< (ostream & out, Accidente const & c){
	out << setw(2) << setfill('0') << c.getDia() << '/' << setw(2) << setfill('0') << c.getMes() << '/' << setfill('0') << setw(4) << c.getAnyo();
	return out;
}

#endif /* ACCIDENTE_H_ */
