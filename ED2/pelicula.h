/*
 * pelicula.h
 *
 *  Created on: 1 feb. 2020
 *      Author: Guille
 */

#ifndef PELICULA_H_
#define PELICULA_H_

#include "Hora.h"
#include <iostream>
using namespace std;

class Pelicula{

private:

	Hora inicio;
	Hora duracion;
	Hora final;
	string titulo;

public:
	Pelicula(){}

	Pelicula(Hora inicio, Hora duracion, string nombre){
		this->inicio = inicio;
		this->duracion = duracion;
		this->final = inicio+duracion;
		this->titulo = nombre;
	}

	Pelicula(int h1, int h2, int m1, int m2, int s1, int s2, string nombre){
		int hora1 = h1;
		int hora2 = h2;
		int minuto1 = m1;
		int minuto2 = m2;
		int segundo1 = s1;
		int segundo2 = s2;
		inicio = Hora(hora1,minuto1,segundo1);
		duracion = Hora(hora2,minuto2,segundo2);
		int aux1 = inicio.toSecs();
		int aux2= duracion.toSecs();
		int secsF = aux1 + aux2;
		final = Hora(secsF);
		titulo = nombre;
	}


	bool operator<(Pelicula & p){
		Hora h1 = getFin();
		Hora h2 = p.getFin();
		if(h1 < h2){
			return true;
		}
		else{
			if(h1.getH() == h2.getH() && h1.getM() == h2.getM() && h1.getS() == h2.getS()){
				return titulo < p.getT();
			}
			else{
				return false;
			}
		}

	}

	void setIni(Hora & ini) {
		inicio = ini;
	}

	void setDur(Hora & dur) {
		duracion = dur;
	}

	void setTit(string tit){
		titulo = tit;
	}

	void setFin(int secs){
		int hora, minuto, segundo;
		if(secs < 0 || secs > 86400){
					throw std::invalid_argument("ERROR");
		}
		else{
			hora = secs/3600;
			minuto = (secs%3600)/60;
			segundo = ((secs%3600)%60);
			final.setH(hora);
			final.setM(minuto);
			final.setS(segundo);
		}
	}

	Hora getIni() const{return inicio;}
	Hora getDur() const{return duracion;}
	string getT() const{return titulo;}
	Hora getFin() const{return final;}

};

inline std::istream& operator>> (std::istream & in, Pelicula & p){
	Hora inicio, duracion;
	string titulo;
	in >> inicio;
	in >> duracion;
	getline(in, titulo);
	p.setIni(inicio);
	p.setDur(duracion);
	p.setTit(titulo);
	int a1 = inicio.toSecs();
	int a2 = duracion.toSecs();
	p.setFin(a1+a2);
	return in;
}

inline std::ostream& operator<< (std::ostream & out, Pelicula const & p){
	out << p.getFin();
	out << " ";
	out << p.getT();
	return out;
}

#endif /* PELICULA_H_ */
