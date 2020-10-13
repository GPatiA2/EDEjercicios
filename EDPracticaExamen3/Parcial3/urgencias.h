
// NOMBRE Y APELLIDOS  Guillermo Garcia Patiño Lenza A34

/*
 * Comentarios sobre los TAD elegidos:
 *
 * 	Uso un set para guardar los recuperados porque es un tipo ordenado sin repeticiones que luego me permite sacar a un vector los datos
 *
 * 	Para poder acceder a la informacion de un paciente en tiempo constante uso un unordered_map que me permite asignar a cada paciente su
 * 		gravedad y su posicion en alguna de las 3 colas.
 *
 *	Para mantener las 3 colas de las diferentes gravedades, uso un vector que inicializo en el constructor con 3 listas de pacientes vacias.
 *	De esta manera asigno a cada posicion del vector una de las gravedades y puedo acceder a ellas en tiempo cte.
 *	Podria usar un unordered_map, pero para tan pocas colas, no merece la pena ocupar mas memoria de la necesaria y el manejo entre las dos
 *		estructuras de datos es similar
 *
 *	Para las colas de cada gravedad podria usar una deque, pero ya que este tipo de datos no lo puedo recorrer y necesito guardarme un
 *	iterador a la posicion del paciente en la cola, prefiero guardar una lista que si puedo recorrer y de la cual tiene sentido
 *	tener un iterador.
 */

#ifndef URGENCIAS
#define URGENCIAS

#include <iostream>          
#include <string>
#include <stdexcept>
#include <set>
#include <unordered_map>
#include <list>
#include <vector>
#include <algorithm>
using namespace std;

using paciente = string;
using gravedad = int;

/*
 * Uso un struct para guardar juntos la gravedad del paciente y la localizacion en la cola de gravedad en la que se encuentra el paciente
 * Esta informacion junta me permite acceder a la cola de gravedad donde esta el paciente y a su posicion en esa cola en tiempo cte
 */
struct infoPaciente {
	gravedad g;
	list<paciente>::iterator loc;
};

class urgencias {


private:
	//
	set<paciente> recuperaciones;

	vector<list<paciente>> espera;

	unordered_map<paciente,infoPaciente> pacientes;


public:
   
	urgencias(){ //Coste O(n) donde n es el numero de posiciones que tiene la tabla hash disponibles por defecto ya que tengo que reservar
				 // la memoria para cada una de ellas.
		recuperaciones = {};
		list<paciente> l3;
		list<paciente> l1;
		list<paciente> l2;
		espera = {l1,l2,l3};
		pacientes = {};
	}

	/*
	 * Esta operacion tiene coste constante, ya que solo realiza busquedas en un mapa no ordenado e inserta elementos en el
	 * En el caso peor, el mapa se tiene que ampliar, asi que la operacion tiene coste O(n) donde n es el valor
	 * absoluto de la diferencia entre las posiciones del vector de la tabla hash antes y despues de ser ampliado.
	 */
	void nuevo_paciente(paciente const & p, gravedad gr){
		gr--; //Resto 1 a la gravedad para mantener la coherencia con las posiciones del vector
		if(!pacientes.count(p)){
			if(!(gr < 0 || gr > 2)){
				//Si los datos son correctos, inserto al final de la cola de la gravedad correspondiente
				//Y me guardo un iterador a esa posicion en la cola que almaceno junto con la gravedad del paciente en el mapa
				// de paciente-infoPaciente
				auto it = espera[gr].insert(espera[gr].end(), p);
				infoPaciente ip; ip.g = gr; ip.loc = it;
				pacientes[p] = ip;
			}
			else{
				throw  domain_error("Gravedad incorrecta");
			}
		}
		else{
			throw domain_error("Paciente repetido");
		}
	}

	/*
	 * Gravedad actual tiene coste constante ya que solo realiza una busqueda en un mapa no ordenado
	 */
	int gravedad_actual(paciente const & p) const {
		auto it = pacientes.find(p);
		if(it != pacientes.end()){
			int i  = it->second.g;
			return i+1;
		}
		else{
			throw domain_error("Paciente inexistente");
		}
	}

	/*
	 * Siguiente es una operacion con coste O(n) (en el caso peor) donde n es el numero de gravedades distintas que tiene la sala de urgencias.
	 * Esto debido a que para encontrar al siguiente paciente, necesita pasar por las colas de las diferentes gravedades en orden, buscando
	 * 	si hay alguien a quien atender en ellas.
	 */
	paciente siguiente(){
		//Si no estan todas las colas vacias
		if(!(espera[0].empty() && espera[1].empty() && espera[2].empty())){
			int i = 2;
			bool encontrado = false;
			paciente p;
			//Miro de la mas grave a la mas leve y atiendo al primer paciente que encuentro
			while( i > -1 && !encontrado){
				if(!espera[i].empty()){
					p = espera[i].front();
					espera[i].pop_front();
					pacientes.erase(p);
					encontrado = true;
				}
				i--;
			}
			return p;
		}
		else{
			throw domain_error("No hay pacientes");
		}
	}

	/*
	 * La operacion mejora tiene coste log(n) en el caso peor. Este coste viene determinado por tener que insertar en el set de recuperados
	 * 		que es un tipo de datos ordenado que se implementa con arboles de busqueda equilibrados, y la insercion de un elemento en este tipo
	 * 		de datos es de coste log(n) donde n es el numero de pacientes que se han recuperado ya
	 *
	 * 	A pesar de eso, en la mayoria de los casos la operacion es de coste constante ya que solo realiza busquedas, inserciones por delante
	 * 		en las colas de gravedad, y eliminaciones de las colas de gravedad (que puedo hacer en tiempo constante gracias a que las listas
	 * 		se implementan con listas doblemente enlazadas).
	 */
	void mejora(paciente const & p) {
		auto it = pacientes.find(p);
		if(it != pacientes.end()){
			//Obtengo la informacion del paciente que me piden
			infoPaciente & ip = it->second;
			//Lo saco de la cola en la que esta ahora
			espera[ip.g].erase(ip.loc);
			//Resto uno a su gravedad
			ip.g --;
			//Si es mayor que -1 (osea mayor que 0 en el enunciado del problema)
			if(ip.g > -1) {
				//Lo inserto en la cola de la siguiente gravedad por delante
				auto it2 = espera[ip.g].insert(espera[ip.g].begin(), p);
				//Y actualizo su localizacion en la informacion del paciente
				ip.loc = it2;
			}
			//Si no es mayor que -1 (osea, es 0 o menor en el enunciado del problema)
			else{
				//Lo inserto en el set de recuperados de manera ordenada, si es que no esta ya insertado
				if(!recuperaciones.count(p)) {
					recuperaciones.insert(p);
				}
				//Y lo borro de la lista de pacientes
				pacientes.erase(p);
			}
		}
		else{
			throw domain_error("Paciente inexistente");
		}
	}

	/*
	 * Esta operacion tiene coste O(n) donde n es el numero de pacientes recuperados ya que tengo que insertar todos ellos en el vector
	 * que voy a devolver
	 */
	vector<paciente> recuperados(){
		vector<paciente> vp;
		for(auto p: recuperaciones){
			vp.push_back(p);
		}
		return vp;
	}

};


#endif
