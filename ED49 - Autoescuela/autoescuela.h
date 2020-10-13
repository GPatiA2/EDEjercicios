/*
 * autoescuela.h
 *
 *  Created on: 22 may. 2020
 *      Author: Guille
 */

#ifndef AUTOESCUELA_H_
#define AUTOESCUELA_H_
#include <string>
#include <unordered_map>
#include <set>
#include <vector>
using namespace std;

using nombre = string;
using puntos = int;
using profesor = string;

struct tAlumno{
	puntos p;
	profesor prof;

	tAlumno(puntos const & puntos, profesor const & profe){
		p = puntos;
		prof = profe;
	}
	bool operator < (tAlumno const & other){ return this->p < other.p;}
	bool operator == (tAlumno const & other){ return this->p == other.p;}
};


class autoescuela {

private:

	unordered_map<profesor, set<nombre>> profesores;
	unordered_map<nombre, tAlumno> matriculados;

	void registra(nombre const & a, profesor const & p){
		tAlumno aux({0,p});
		//Inserto la informacion en el mapa de matriculados y consigo el iterador a lo que acabo de insertar
		matriculados.insert({a,aux}).first;
		//Inserto en el conjunto de alumnos del profesor p el iterador del mapa que corresponde al alumno insertado
		profesores[p].insert(a);
	}

	void cambia(nombre const & a, profesor const & p){
		//Consigo un iterador al elemento del mapa correspondiente al alumno
		auto it = matriculados.find(a);
		//Borro ese iterador del conjunto de alumnos del profesor
		profesores.at(it->second.prof).erase(a);
		//Lo inserto en el conjunto de alumnos del nuevo profesor
		if(profesores.count(p)){
			profesores.at(p).insert(a);
		}
		else{
			profesores[p].insert(a);
		}
		it->second.prof = p;
	}




public:

	autoescuela(){}

	void alta(nombre const & a, profesor const& p){
		if(matriculados.count(a)){
			cambia(a,p);
		}
		else{
			registra(a,p);
		}
	}

	bool es_alumno(nombre const & a, profesor const& p) const {
		if(matriculados.count(a) && profesores.count(p)){
			//Busco al alumno en el conjunto de alumnos del profesor
			auto & cjto = profesores.at(p);
			return cjto.count(a);
		}
		else{
			return false;
		}
	}

	puntos puntuacion(nombre const& a) const {
		if(matriculados.count(a)){
			return matriculados.at(a).p;
		}
		else{
			string s = "El alumno ";
			s.append(a);
			s.append(" no esta matriculado");
			throw domain_error(s);
		}
	}

	void actualizar(nombre const & a, puntos const & ptos){
		auto it = matriculados.find(a);
		if(it != matriculados.end()){
			it->second.p += ptos;
		}
		else{
			string s = "El alumno ";
			s.append(a);
			s.append(" no esta matriculado");
			throw domain_error(s);
		}
	}

	const vector<nombre> examen(profesor const & prof, puntos const & ptos) const{
		vector<nombre> v;
		if(profesores.count(prof)){
			auto & alumnos = profesores.find(prof)->second;
			auto it = alumnos.begin();
			while(it != alumnos.end()){
				if(matriculados.at(*it).p >= ptos){
					v.push_back(*it);
				}
				it++;
			}
			return v;
		}
		else{
			return v;
		}
	}

	void aprobar(nombre const & a){
		if(matriculados.count(a)){
			profesor p = matriculados.at(a).prof;
			profesores.at(p).erase(a);
			matriculados.erase(a);
		}
		else{
			string s = "El alumno ";
			s.append(a);
			s.append(" no esta matriculado");
			throw domain_error(s);
		}
	}

};



#endif /* AUTOESCUELA_H_ */
