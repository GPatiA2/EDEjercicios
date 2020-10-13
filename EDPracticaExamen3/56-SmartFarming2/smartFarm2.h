
/*
 * smartFarm2.h
 *
 *  Created on: 1 jul. 2020
 *      Author: Guille
 */

#ifndef SMARTFARM2_H_
#define SMARTFARM2_H_
#include <set>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;

using plaga = string;
using sector = string;

struct comp{
	bool operator() (pair<plaga,int> const & p1, pair<plaga,int> const & p2){
		return p1.first < p2.first;
	}
};

struct infoSector {
	int plantas;
	int afectadas;
	map<plaga, int> plagas;

	bool addAfectadas(int a, plaga const & p){
		afectadas += a;
		bool antes = plagas[p] >= plantas/4;
		plagas[p] += a;
		return !antes && plagas[p] >= plantas/4;
	}

};


class smartFarm2 {
private:
	vector<pair<sector,plaga>> avisos;
	unordered_map<sector,infoSector> sectores;


public:

	smartFarm2(){
		avisos = {};
		sectores = {};
	}

	void alta(sector const & id, int n){
		auto it = sectores.find(id);
		if(it != sectores.end()){
			it->second.plantas += n;
		}
		else{
			infoSector s; s.plantas = n; s.afectadas = 0; s.plagas = {};
			sectores[id] = s;
		}
	}

	void datos(sector const & id, plaga const & p, int n){
		auto it = sectores.find(id);
		if(it != sectores.end()){
			infoSector & info = it->second;
			if(n > info.plantas || n + info.afectadas > info.plantas){
				throw invalid_argument("Numero de plantas incorrecto");
			}
			else{
				bool aviso = info.addAfectadas(n,p);
				if(aviso){avisos.push_back({id,p});}
			}
		}
		else{
			throw invalid_argument("Sector no existente");
		}

	}

	vector<pair<sector,plaga>> fumigar(){

		vector<pair<sector,plaga>> v;
		for(auto p : avisos){
			v.push_back(p);
			auto & info = sectores[p.first];
			int i = info.plagas[p.second];
			info.afectadas -= i;
			info.plagas[p.second] = 0;
		}
		avisos.clear();
		return v;
	}

	vector<pair<plaga,int>> plagas(sector const & id) const {
		auto it = sectores.find(id);
		if(it != sectores.end()){
			vector<pair<plaga,int>> v;
			auto & mPlagas = it->second.plagas;
			for(auto p : mPlagas){
				v.push_back(p);
			}
			return v;
		}
		else{
			throw invalid_argument("Sector no existente");
		}
	}

};



#endif /* SMARTFARM2_H_ */
