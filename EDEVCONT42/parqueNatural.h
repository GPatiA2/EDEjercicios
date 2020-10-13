/*
 * parqueNatural.h
 *
 * Guillermo Garcia Patiño Lenza
 */

#ifndef PARQUENATURAL_H_
#define PARQUENATURAL_H_
#include <map>
#include <unordered_map>
#include <set>
#include <vector>
#include <list>
#include <string>
using namespace std;


using ecosistema = string;
using especie = string;
using cantidad = int;

class parqueNatural {

private:

	unordered_map<ecosistema, pair<unordered_map<especie, cantidad>, list<especie>>> ecosistemas;
	map<especie, cantidad> totales;

	//Uso un mapa de ecosistemas en el que guardo la cantidad de cada especie que hay en el ecosistema (unordered_map<especie,cantidad>)
	//y en el orden en el que se insertaron (list<especie>) para poder acceder en tiempo cte a toda la informacion

	//Ademas, uso un mapa ordenado especie-cantidad para llevar cuantos ejemplares hay de una especie en el parque, y mantener
	// las especies ordenadas alfabeticamente

public:

	parqueNatural(){
		unordered_map<ecosistema, pair<unordered_map<especie, cantidad>, list<especie>>> ecosistemas;
		map<especie, cantidad> totales;
	}

	void an_ecosistema(ecosistema const & e){ //El coste de esta funcion es O(n) donde n es la cantidad de posiciones iniciales
											  // del mapa ecosistemas
		if(!ecosistemas.count(e)){
			ecosistemas.insert({e,{{},{}}});
		}
		else{
			throw domain_error("EEcosistemaDuplicado");
		}
	}

	void an_ejemplares(ecosistema const & eco, especie const& esp, cantidad const & n){
		/*
		 * El coste de este metodo es constante, ya que solo incluye busquedas en mapas sin orden y asignaciones
		 * y todas esas operaciones son de coste constante.
		 */
		auto it = ecosistemas.find(eco);
		if(it != ecosistemas.end()){
			//Si la especie no esta aun en el parque la inserto
			if(!totales.count(esp)){
				totales[esp] = 0;
			}
			//saco referencias
			auto & mapaEspecies = it->second.first;
			auto & listaEspecies = it->second.second;

			//Si la especie no esta en el ecosistema, la isnerto
			if(!mapaEspecies.count(esp)){
				mapaEspecies[esp] = 0;
				listaEspecies.push_front(esp);
			}
			//Sumo los ejemplares
			mapaEspecies[esp] += n;
			totales[esp] += n;
		}
		else{
			throw domain_error("EEcosistemaNoExiste");
		}
	}

	list<especie> lista_especies_ecosistema(ecosistema const & eco, int const & n) const {
		/*
		 * El coste de esta operacion es lineal de O(n) donde n es el parametro que se pasa al metodo para indicar cuantas
		 * especies se quieren en la lista. Esto es porque tengo que insertar en la lista que voy a devolver tantos elementos
		 * como quiero que haya. (podria devolver una referencia constante a la lista y luego fuera mostrar los elementos
		 * que yo quisiera y tendria menos coste)
		 */
		auto it = ecosistemas.find(eco);
		if(it != ecosistemas.end()){

			auto & listaEspecies = it->second.second;
			list<especie> aux;
			int i = 0;
			auto itRecorrer = listaEspecies.cbegin();
			while(i < n && itRecorrer != listaEspecies.cend()){
				aux.push_back(*itRecorrer);
				i++;
				itRecorrer++;
			}

			return aux;
		}
		else{
			throw domain_error("EEcosistemaNoExiste");
		}
	}

	cantidad numero_ejemplares_en_ecosistema(ecosistema const & eco, especie const & esp) const {
		/**
		 * Esta operacion tiene coste constante, ya que solo incluye busquedas en mapas sin orden, y esas operaciones
		 * son de coste constante
		 */
		auto it = ecosistemas.find(eco);
		if(it != ecosistemas.end()){
			auto & mapaEspecies = it->second.first;
			auto itEsp = mapaEspecies.find(esp);
			if(itEsp == mapaEspecies.end()){
				return 0;
			}
			else{
				return itEsp->second;
			}
		}
		else{
			throw domain_error("EEcosistemaNoExiste");
		}
	}

	list<especie> lista_especies_parque() const{
		/**
		 * Esta operacion tiene coste O(n) donde n es el numero de especies que hay en el parque.
		 * Esto se debe a que tengo que insertar una por una las especies en la lista que voy a devolver
		 */
		list<especie> aux;
		auto it = totales.cbegin();
		while(it != totales.end()){
			aux.push_back(it->first);
			it++;
		}
		return aux;
	}

	cantidad numero_ejemplares_en_parque(especie const & e){
		/**
		 * Esta operacion tiene coste constante, ya que solo hay que buscar en un mapa no ordenado.
		 */
		auto it = totales.find(e);
		if(it != totales.end()){
			return it->second;
		}
		else{
			return 0;
		}

	}

};



#endif /* PARQUENATURAL_H_ */
