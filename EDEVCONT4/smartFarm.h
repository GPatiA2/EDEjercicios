/*
 * clase.h
 *
 *  Created on: 28 may. 2020
 *      Author: Guille
 */

#ifndef SMARTFARM_H_
#define SMARTFARM_H_

#include <string>
#include <vector>
#include <list>
#include <map>
#include <unordered_map>
#include <set>
using namespace std;


using sector = string;
using plaga = string;

class smartFarm {


private:

	unordered_map<sector, set<plaga>> sectores;
	//Uso el unordered_map porque no me piden orden entre los sectores y el set porque me piden orden alfabetico de plagas

	unordered_map<plaga, vector<sector>> sectoresCadaPlaga;
	//Uso el unordered map porque no me piden orden entre las plagas y la list porque quiero mantener el orden en el que
	//	llegan los avisos

public:

	smartFarm(){
		unordered_map<sector, set<plaga>> sectores;
		unordered_map<plaga, vector<sector>> sectoresCadaPlaga;
	}

	void alta(sector const & id){
		if(!sectores.count(id)){
			sectores[id];
		}
	}

	void datos(sector const & id, plaga const & p){
		if(sectores.count(id)){
			if(!sectores.at(id).count(p)){
				if(!sectoresCadaPlaga.count(p)){
					sectoresCadaPlaga.insert({p,{}});
				}
				sectores[id].insert(p);
				sectoresCadaPlaga[p].push_back(id);
			}
			else{
				throw domain_error("Plaga repetida");
			}
		}
		else{
			throw domain_error("Sector no existente");
		}
	}

	vector<sector> const fumigar(plaga const & p){
		if(sectoresCadaPlaga.count(p)){
			vector<sector> v;
			vector<plaga> & aux = sectoresCadaPlaga.find(p)->second;
			for(sector s: aux){
				v.push_back(s);
				sectores[s].erase(p);
			}
			sectoresCadaPlaga.erase(p);
			return v;
		}
		else{
			throw domain_error("Plaga no existente");
		}
	}

	vector<plaga> plagas(sector const& s){
		if(sectores.count(s)){
			vector<sector> v;
			for(plaga p: sectores.at(s)){
				v.push_back(p);
			}
			return v;
		}
		else{
			throw domain_error("Sector no existente");
		}
	}

};


#endif /* SMARTFARM_H_ */
