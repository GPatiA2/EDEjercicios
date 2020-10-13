
/*
 * libreria.h
 *
 *  Created on: 29 jun. 2020
 *      Author: Guille
 */

#ifndef LIBRERIA_H_
#define LIBRERIA_H_

#include <vector>
#include <unordered_map>
#include <algorithm>
#include <set>
using namespace std;

using libro = string;
using ventas = int;


struct vInfo{
	string titulo;
	int ultVenta;
	int vendidos;

	vInfo(int uv, int v, string t){
		ultVenta = uv;
		vendidos = v;
		titulo = t;
	}

	vInfo(){
		ultVenta = 0;
		vendidos = 0;
	}

	bool operator> (vInfo const & v2) const{
		return vendidos > v2.vendidos || (vendidos == v2.vendidos && ultVenta > v2.ultVenta);
	}

	bool operator< (vInfo const & v2) const{
		return vendidos < v2.vendidos || (vendidos == v2.vendidos && ultVenta < v2.ultVenta);
	}
};

struct lInfo{
	int cant;
	set<vInfo>::const_iterator loc;
	lInfo(int e, set<vInfo>::iterator l){
		cant = e;
		loc = l;
	}
};

class libreria {
private:

	unordered_map<libro, lInfo> stock;
	set<vInfo, greater<vInfo>> vendidos;

public:

	libreria(){
		stock = {};
		vendidos = {};
	}

	void nuevoLibro(int const & ej, libro const & x){
		auto it1 = stock.find(x);
		if(it1 != stock.end()){
			it1->second.cant += ej;
		}
		else{
			lInfo li(ej, vendidos.end());
			stock.insert({x,li});
		}
	}

	void comprar(libro const & x, int i){
		auto it = stock.find(x);
		if(it == stock.end()){
			throw invalid_argument("Libro no existente");
		}
		else{
			if(it->second.cant < 1){
				throw out_of_range("No hay ejemplares");
			}
			else{
				it->second.cant -= 1;
				if(it->second.loc == vendidos.end()){
					vInfo vi(i,1,x);
					auto it2 = vendidos.insert(vi);
					it->second.loc = it2.first;
				}
				else{
					auto it2 = it->second.loc;
					int c = it->second.loc->vendidos;
					vendidos.erase(it2);
					it->second.loc = vendidos.insert({i,c+1,x}).first;
				}
			}
		}
	}

	bool estaLibro(libro const & x) const{
		return stock.count(x);
	}

	void elimLibro(libro const & x){
		auto it = stock.find(x);
		if(it != stock.end()){
			if(it->second.loc != vendidos.end()){
				vendidos.erase(it->second.loc);
			}
			stock.erase(it);
		}

	}

	int numEjemplares(libro const& x)const{
		auto it = stock.find(x);
		if(it != stock.end()){
			return it->second.cant;
		}
		else{
			throw invalid_argument("Libro no existente");
		}
	}

	void top10(vector<vInfo> & top){
		int i = 0;
		auto it = vendidos.begin();
		while(i < 10 && it != vendidos.end()){
			top.push_back(*it);
			i++;
			it++;
		}

	}

};

#endif /* LIBRERIA_H_ */
