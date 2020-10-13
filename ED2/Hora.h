/*
 * Hora.h
 *
 *  Created on: 1 feb. 2020
 *      Author: Guille
 */

#ifndef HORA_H_
#define HORA_H_

#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdexcept>
using namespace std;

class Hora{
private:
	int hora;
	int minuto;
	int segundo;


public:
	Hora(){}
	Hora(Hora const & h){
		hora = h.getH();
		minuto = h.getM();
		segundo = h.getS();
	}
	Hora(int h, int m, int s){
		if(h < 24 && h >= 0 && m <= 59 && m >= 0 && s >= 0 && s <= 59){
			hora = h;
			minuto = m;
			segundo = s;
		}
		else{

			throw std::invalid_argument("ERROR");
		}
	}

	Hora(int s){
		if(s < 0 || s > 86400){
			throw std::invalid_argument("ERROR");
		}
		else{
			hora = s/3600;
			minuto = (s%3600)/60;
			segundo = ((s%3600)%60);
		}
	}

	int toSecs() const {
		return hora*3600+minuto*60+segundo;
	}
	void setH(int h){
		if (h < 24 && h >= 0) {

			hora = h;
		}
		else{
			throw std::invalid_argument("ERROR");
		}
	}

	void setM(int m){
		if (m < 60 && m >= 0) {

			minuto = m;
		}
		else{
			throw std::invalid_argument("ERROR");
		}
	}

	void setS(int s){
		if (s < 60 && s >= 0) {

			segundo = s;
		}
		else{
			throw std::invalid_argument("ERROR");
		}
	}


	~Hora(){}

	bool operator <(Hora & h) {
		return (toSecs() < h.toSecs());

	}

	int getS() const {return segundo;}
	int getM() const {return minuto;}
	int getH() const {return hora;}

	Hora operator-(Hora const & h){
		int H,M,S;

		int auxL = toSecs();
		int auxR = h.toSecs();
		int aux = auxL - auxR;
		H = aux/3600;
		M = (aux%3600)/60;
		S = ((aux%3600)%60);
		return Hora(H,M,S);
	}

	Hora operator+(Hora const & h){
		int H,M,S;
		int auxL = toSecs();
		int auxR = h.toSecs();
		int aux = auxL + auxR;
		H = aux/3600;
		M = (aux%3600)/60;
		S = ((aux%3600)%60);
		if(H > 23){
			throw std::invalid_argument("ERROR");
		}
		return Hora(H,M,S);
	}

};

inline std::istream& operator>> (std::istream & in, Hora & h){
	int H, M, S;
	in >> H;
	in.ignore();
	in >> M;
	in.ignore();
	in >> S;
	h.setH(H);
	h.setM(M);
	h.setS(S);
	return in;
}

inline std::ostream& operator<< (std::ostream & out, Hora const & h){
	out << std::setfill('0') << std::setw(2) << h.getH();
	out << ":";
	out << std::setfill('0') << std::setw(2) << h.getM();
	out << ":";
	out << std::setfill('0') << std::setw(2) << h.getS();
	return out;
}




#endif /* HORA_H_ */
