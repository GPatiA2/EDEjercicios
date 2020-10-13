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
using namespace std;


using dni = string;
using puntos = int;

class carnet_puntos{

private:
	unordered_map<dni,puntos> conductores;
	unordered_map<puntos, int> puntuaciones;

public:

	carnet_puntos(){
		unordered_map<dni,puntos> conductores;
		unordered_map<puntos, int> puntuaciones;
	}

	void nuevo(dni const d){
		if(conductores.count(d)){
			throw domain_error("Conductor duplicado");
		}
		else{
			conductores.insert({d,15});
			puntuaciones[15]++;
		}
	}

	void quitar(dni const d, puntos const p){

		if(conductores.count(d)){
			if(conductores.at(d) == 0){}
			else if(conductores.at(d) < p){
				puntuaciones[conductores[d]]--;
				conductores[d] = 0;
				puntuaciones[0]++;
			}
			else{
				puntuaciones[conductores[d]]--;
				conductores[d] -= p;
				puntuaciones[conductores[d]]++;
			}
		}
		else{
			throw domain_error("Conductor inexistente");
		}
	}

	puntos consultar(dni const d) const {
		auto it = conductores.find(d);
		if(it != conductores.end()){
			return it->second;
		}
		else{
			throw domain_error("Conductor inexistente");
		}
	}

	int cuantos_con_puntos(puntos const p) const {
		if(p <= 15 && p >= 0){
			auto it = puntuaciones.find(p);
			if(it != puntuaciones.end()){
				return it->second;
			}
			else{
				return 0;
			}
		}
		else{
			throw domain_error("Puntos no validos");
		}
	}


};

#endif /* CARNET_PUNTOS_H_ */
