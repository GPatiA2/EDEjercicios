/*
 * carnet_puntos.h
 *
 *  Created on: 21 may. 2020
 *      Author: Guille
 */

#ifndef CARNET_PUNTOS_H_
#define CARNET_PUNTOS_H_
#include <unordered_map>
#include <stdexcept>
#include <list>
#include <vector>
using namespace std;


using dni = string;
using puntos = int;

class carnet_puntos{

private:
	unordered_map<dni,pair<puntos, list<dni>::iterator>> conductores;
	unordered_map<puntos, list<dni>> puntuaciones;


public:

	carnet_puntos(){}

	void nuevo(dni const d){
		if(!conductores.count(d)){
			auto nit = puntuaciones[15].insert(puntuaciones[15].cbegin(),d);
			conductores[d] = {15,nit};
		}
		else{
			throw domain_error ("Conductor duplicado");
		}
	}

	void quitar(dni const& d, puntos const& p){
		auto it = conductores.find(d);
		if(it != conductores.end()){
			if (!(it->second.first >= 15 && p <= 0) || (it->second.first <= 0 && p >= 0)) {
				//Borro al conductor de la lista de puntos que tenia antes
				auto & puntIt = it->second.second;
				puntuaciones[it->second.first].erase(puntIt);

				//Le resto los puntos al conductor
				puntos & puntosCond = it->second.first;
				puntosCond = puntosCond- p;
				if(puntosCond <= 0){ puntosCond = 0; }

				//Pongo este if para que el metodo me valga para quitar y recuperar
				if(puntosCond >= 15){ puntosCond = 15;}

				//Meto al conductor al final de la lista de los puntos que tiene ahora
				auto nposInsert = puntuaciones[puntosCond].insert(puntuaciones[puntosCond].cbegin(), d);

				//Guardo en el mapa de conductores la nueva ubicacion del conductor en la tabla puntuaciones
				it->second.second = nposInsert;
			}
		}
		else{
			throw domain_error ("Conductor inexistente");
		}
	}

	void recuperar(dni const & d, puntos const & p){
		//Uso la funcion quitar con valores negativos en los puntos y asi recupero
		quitar(d, -p);
	}

	puntos consultar(dni const d) const {
		auto it = conductores.find(d);
		if(it != conductores.end()){
			return conductores.at(d).first;
		}
		else{
			throw domain_error ("Conductor inexistente");
		}
	}

	int cuantos_con_puntos(puntos const p) const {
		if(p >= 0 && p <= 15){
			int cuantos = 0;
			if(puntuaciones.count(p)){
				cuantos = puntuaciones.at(p).size();
			}
			return cuantos;
		}
		else{
			throw domain_error("Puntos no validos");
		}
	}

	list<dni> lista_por_puntos(puntos const & p){
		if(p >= 0 && p <= 15){
			if(puntuaciones.count(p)){
				return puntuaciones[p];
			}
			else{
				list<dni> aux;
				return aux;
			}
		}
		else{
			throw domain_error("Puntos no validos");
		}
	}


};

#endif /* CARNET_PUNTOS_H_ */
