/*
 * ipud.h
 *
 *  Created on: 27 may. 2020
 *      Author: Guille
 */

#ifndef IPUD_H_
#define IPUD_H_
#include <unordered_map>
#include <list>
#include <vector>
#include <string>
using namespace std;

using duracion = int;
using cancion = string;
using artista = string;

struct tCancion{
	duracion d;
	artista a;
	list<cancion>::iterator enReproducidas;
	list<cancion>::iterator enPlaylist;

	bool p;
	bool r;

	tCancion(duracion const & du, artista const & ar){
		d = du;
		a = ar;
		enReproducidas = {};
		enPlaylist = {};
		p = false;
		r = false;
	}

	bool estaEnPlaylist() const {return p;}
	bool estaEnReproducidas() const {return r;}

};


class ipud {

private:

	list<cancion> playlist;
	list<cancion> reproducidas;

	int duracionTotal;

	unordered_map<cancion, tCancion> canciones;

public:

	ipud(){
		list<cancion> playlist;
		list<cancion> reproducidas;
		unordered_map<cancion, tCancion> canciones;
		duracionTotal = 0;
	}

	int getSize()const {
		return reproducidas.size();
	}

	void addSong(cancion const & s, artista const & a, duracion const & d){
		if(!canciones.count(s)){
			tCancion c(d,a);
			canciones.insert({s,c});
		}
		else{
			throw domain_error("addSong");
		}
	}

	void addToPlayList(cancion const & s){
		if(canciones.count(s)){
			//Consigo un iterador a la cancion en el mapa
			auto itC = canciones.find(s);
			//Si no se encuentra en la lista
			if(!itC->second.estaEnPlaylist()){
				//Se inserta por detras a la lista
				auto itList = playlist.insert(playlist.cend(), s);
				//Se suma a la duracion total de la playlist la duracion de la cancion
				duracionTotal += itC->second.d;
				//Me guardo en la informacion de la cancion su posicion en la playlist
				itC->second.enPlaylist = itList;

				itC->second.p = true;
			}
		}
		else{
			throw domain_error("addToPlayList");
		}
	}

	cancion current() const{
		if(!canciones.empty()){
			if(!playlist.empty()){
				return *playlist.cbegin();
			}
			else{
				throw domain_error("current");
			}
		}
		else{
			throw domain_error("current");
		}
	}

	cancion play(){
		if(!playlist.empty()){
			//Consigo un iterador a la primera cancion
			cancion c = *playlist.begin();
			//Pongo el iterador de esa cancion en la playlist a null
			canciones.at(c).p = false;
			//Saco la primera cancion de la playlist
			playlist.pop_front();
			//Si la cancion esta en reproducidas, la elimino
			if(canciones.at(c).estaEnReproducidas()){
				reproducidas.erase(canciones.at(c).enReproducidas);
			}
			//Inserto la cancion al final en la lista de reproducidas
			auto itRep = reproducidas.insert(reproducidas.end(), c);
			//Guardo ese iterador en la informacion de esa cancion
			canciones.at(c).enReproducidas = itRep;
			canciones.at(c).r = true;
			//Resto la duracion de la cancion que sale de la playlist a la duracion de la playlist
			duracionTotal -= canciones.at(c).d;
			return c;
		}
		else{
			return "No hay canciones en la lista";
		}
	}

	duracion totalTime() const { return duracionTotal;}

	vector<cancion> recent(int const & n){
		auto itRec = reproducidas.rbegin();
		int i = 0;
		vector<cancion> v;
		while(itRec != reproducidas.rend() && i < n){
			v.push_back(*itRec);
			i++;
			itRec++;
		}
		return v;
	}

	void deleteSong(cancion const & s){

		if (canciones.count(s)) {
			if(canciones.at(s).estaEnPlaylist()){
				duracionTotal -= canciones.at(s).d;
				playlist.remove(s);
			}
			if(canciones.at(s).estaEnReproducidas()){
				reproducidas.remove(s);
			}
			canciones.erase(s);
		}
	}

};


#endif /* IPUD_H_ */
