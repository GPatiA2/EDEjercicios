/*
 * consultorio.h
 *
 *  Created on: 19 may. 2020
 *      Author: Guille
 */

#ifndef CONSULTORIO_H_
#define CONSULTORIO_H_
#include <string>
#include <unordered_map>
#include <map>
#include <set>
#include <vector>
#include "fecha.h"

using namespace std;
using medico = string;
using paciente = string;
using dia = int;

struct cita{
	fecha f;
	paciente p;

	cita(fecha fe, paciente pac) : f(fe), p(pac){}
	bool operator == (cita const & other) const{
		return this->f == other.f;
	}

	bool operator < (cita const & other) const{
		return this->f < other.f;
	}
};


class consultorio{

private:
	unordered_map<medico, map<dia, set<cita>>> consultas;
	//Llevo un mapa que tiene como clave, el nombre del medico, y como valor un mapa ordenado de las citas para cada dia de ese medico
	//Almaceno las citas en un set, aprovechando que esta implementado con arboles de busqueda, para mantener el tiempo logaritmico de acceso

public:
	consultorio(){
		unordered_map<medico, map<dia, set<cita>>> consultas;
	};

	void nuevoMedico(medico m){ //Coste constante: crear las estructuras de datos que utilizo es de coste constante para todas ellas
//		consultas[m] = {}; //Inserta el nuevo medico con un mapa de citas vacio
		auto it = consultas.insert({m, {}});
		if(!it.second){
			throw invalid_argument("");
		}
	}

	void pideConsulta(paciente  p, medico const & m, fecha f){ //Coste logaritmico respecto al numero de claves:
													  //buscar en el diccionario ordenado es coste logaritmico, igual que insertar
		if(consultas.count(m)){//Consultar si esta registrado el medico que se pide
			if(!consultas.at(m).count(f.getDia())){
				consultas.at(m)[f.getDia()];
			}
			cita c(f,p);
			if(!consultas[m][f.getDia()].count(c)){
				consultas[m][f.getDia()].insert(c);
			}
			else{
				throw domain_error("Fecha ocupada");
			}
		}
		else{
			//Lanzar error "Medico no existente"
			throw invalid_argument("Medico no existente");
		}
	}

	paciente siguientePaciente(medico const & m) const {//Coste logaritmico respecto la numero de dias registrados para el medico: buscar el primer elemento en un mapa ordenado es coste logaritmico
		if(consultas.count(m)){ //Consultar si esta registrado el medico que se pide
			if(!consultas.at(m).empty()){
				//Del primer dia que tiene citas // Saco el nombre del primer paciente que tiene
				string it = consultas.at(m).cbegin()->second.begin()->p;
				return it;
			}
			else{
				throw domain_error("No hay pacientes");
			}
		}
		else{
			//Lanzar error "Medico no existente"
			throw invalid_argument("Medico no existente");
		}
	}

	void atiendeConsulta(medico const & m){ //Coste logaritmico respecto al numero de dias registrados para el medico: por lo mismo que en el metodo anterior
		auto med = consultas.find(m);
		if(med != consultas.end()){ //Consultar si esta registrado el medico que se pide
			if(!consultas.at(m).empty()){
				//De el primer dia que tiene citas // La primera cita que tiene
				auto it = consultas.at(m).begin()->second.begin();
				consultas.at(m).begin()->second.erase(it);
				//Si el conjunto se ha quedado vacio, tengo que eliminar ese conjunto del arbol
				if(consultas.at(m).begin()->second.empty()){
					consultas.at(m).erase(consultas.at(m).begin());
				}
			}
			else{
				throw domain_error("No hay pacientes");
			}
		}
		else{
			//Lanzar error "Medico no existente"
			throw invalid_argument("Medico no existente");
		}
	}

	vector<cita> listaPacientes(medico const & m, int const & d) const { //Coste lineal con respecto a las citas que tenga el medico m en el dia d
		if(consultas.count(m)){ //Consulto si el medico esta registrado
			vector<cita> v; //Creo un vector para devolverlo despues
			if(!consultas.at(m).empty()){
				if(consultas.at(m).count(d)){
					auto & cjto = consultas.at(m).find(d)->second;
					for(cita c : cjto){
						v.push_back(c);
					}
				}
			}
			return v;
		}
		else{
			//Lanzar error "Medico no existente"
			throw invalid_argument("Medico no existente");
		}
	}

};



#endif /* CONSULTORIO_H_ */

//
//void pideConsulta(paciente const & p, medico const & m, fecha const & f){ //Coste logaritmico respecto al numero de claves:
//													  //buscar en el diccionario ordenado es coste logaritmico, igual que insertar
//		if(consultas.count(m)){//Consultar si esta registrado el medico que se pide
//			if(!consultas.at(m).count(f.getDia())){
//				consultas.at(m)[f.getDia()];
//			}
//			auto citasDia = consultas.find(m)->second.find(f.getDia()); //Extraigo el par dia-conjunto de citas para el medico m en el dia f.getDia()
//			cita c(f,p); //Construyo una nueva cita con los datos que me dan
//			auto & cjtoCitas = citasDia->second;
//			if(cjtoCitas.find(c)->f != f){ //Si la cita no se encuentra ya en el conjunto
//											//*Nota: para esto uso el count porque supongo que usa el operador ==, que he sobrecargado antes
//											//			para que una cita sea igual a otra solo si estan en la misma fecha
//				cjtoCitas.insert(c); //Se inserta
//			}
//			else{
//				//Lanzar error "Fecha ocupada"
//				throw invalid_argument("Fecha ocupada");
//			}
//		}
//		else{
//			//Lanzar error "Medico no existente"
//			throw invalid_argument("Medico no existente");
//		}
//	}
//
//	paciente siguientePaciente(medico const & m) const {//Coste logaritmico respecto la numero de dias registrados para el medico: buscar el primer elemento en un mapa ordenado es coste logaritmico
//		if(consultas.count(m)){ //Consultar si esta registrado el medico que se pide
//			auto & citasMedico = consultas.find(m)->second; //Extraigo el mapa de citas para ese medico
//			if(!citasMedico.empty()){ //Si el mapa no esta vacio
//				auto it = citasMedico.cbegin(); //Cojo un iterador al primer elemento del mapa (primer dia que el medico tiene citas)
//				if(it->second.begin() != it->second.end()){
//					return it->second.begin()->p;  //Creo un iterador al primer elemento del conjunto de citas para ese medico y ese dia, y devuelvo
//												//	el paciente al que le toca.
//				}
//				else{
//					throw invalid_argument("No hay pacientes");
//				}
//			}
//			else{
//				//Lanzar error "No hay pacientes"
//				throw invalid_argument("No hay pacientes");
//			}
//		}
//		else{
//			//Lanzar error "Medico no existente"
//			throw invalid_argument("Medico no existente");
//		}
//	}
//
//	void atiendeConsulta(medico const & m){ //Coste logaritmico respecto al numero de dias registrados para el medico: por lo mismo que en el metodo anterior
//		auto med = consultas.find(m);
//		if(med != consultas.end()){ //Consultar si esta registrado el medico que se pide
//			auto & citasMedico = med->second; //Extraigo el mapa de citas para ese medico
//			if(!citasMedico.empty()){ //Si el mapa no es vacio
//				auto it = citasMedico.begin(); //Hago un iterador al primer elemento del mapa
//				set<cita> & citasPrimerDia = it->second; //Consigo una referencia al conjunto del primer dia del mapa
//				if(!citasPrimerDia.empty()){
//					auto el = citasPrimerDia.cbegin();
//					cita c = *el;
//					citasPrimerDia.erase(c); //Borro el primer elemento del conjunto
//				}
//				else{
//					//Lanzar error "No hay pacientes"
//					throw invalid_argument("No hay pacientes");
//				}
//			}
//			else{
//				//Lanzar error "No hay pacientes"
//				throw invalid_argument("No hay pacientes");
//			}
//		}
//		else{
//			//Lanzar error "Medico no existente"
//			throw invalid_argument("Medico no existente");
//		}
//	}
//
//	vector<cita> listaPacientes(medico const & m, int const & d) const { //Coste lineal con respecto a las citas que tenga el medico m en el dia d
//		if(consultas.count(m)){ //Consulto si el medico esta registrado
//			vector<cita> v; //Creo un vector para devolverlo despues
//
//			auto it1 = consultas.find(m)->second; //Saco el conjunto de citas correspondientes al medico y al dia que piden
//			if(!it1.empty()){
//				auto it2 = it1.find(d)->second; //Saco el conjunto de citas correspondientes al medico y al dia que piden
//				for(cita c : it2){ //Para cada cita del conjunto
//					v.push_back(c); //Meto al paciente en el vector
//				}
//				return v; //Devuelvo el vector
//			}
//			else{
//				return v;
//			}
//		}
//		else{
//			//Lanzar error "Medico no existente"
//			throw invalid_argument("Medico no existente");
//		}
//	}
