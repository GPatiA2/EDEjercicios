/// Nombre del alumno Guillermo Garcia PatiÃ±o Lenza
// Usuario del Juez A34


#include <iostream>
#include <iomanip>
#include <fstream>
#include <queue>
#include "bintree_eda.h"
using namespace std;

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracioÌ�n, y escribiendo la respuesta

typedef enum {NADA, SEMICOMPLETO, COMPLETO}tEstado ;
typedef struct {
	int altura;
	tEstado estado;
}tsol;

inline ostream& operator << (ostream & out, tEstado st){
	if(st == 0){out << "NADA";}
	if(st == 1){out << "SEMICOMPLETO";}
	if(st == 2){out << "COMPLETO";}
	return out;
}

tsol resolver(bintree<char> const & act){
	if(act.empty()){
		return {0, COMPLETO};
	}
	else{
		tsol sI = resolver(act.left());
		tsol sD = resolver(act.right());
		if(sI.estado == NADA || sD.estado == NADA){
			return{max(sD.altura, sI.altura)+1, NADA};
		}
		else{
			int dif = sI.altura - sD.altura;
			if(dif <= 1 && dif >= 0){
				if(dif == 1){
					tEstado aux;
					if(sD.estado == COMPLETO && sI.estado == COMPLETO){
						aux = SEMICOMPLETO;
					}
					else if(sD.estado == SEMICOMPLETO && sI.estado == COMPLETO){
						aux = NADA;
					}
					else if(sD.estado == COMPLETO && sI.estado == SEMICOMPLETO){
						aux = SEMICOMPLETO;
					}
					else{
						aux = NADA;
					}
					return {max(sD.altura, sI.altura)+1, aux};
				}
				else{
					if(sD.estado == COMPLETO && sI.estado == COMPLETO){
						return {max(sD.altura, sI.altura)+1, COMPLETO};
					}
					else if(sD.estado == SEMICOMPLETO && sI.estado == COMPLETO){
						return {max(sD.altura, sI.altura)+1, SEMICOMPLETO};
					}
					else if(sD.estado == COMPLETO && sI.estado == SEMICOMPLETO){
						return {max(sD.altura, sI.altura)+1, NADA};
					}
					else{
						return {max(sD.altura, sI.altura)+1, NADA};
					}
				}
			}
			else{
				return{max(sD.altura, sI.altura)+1, NADA};
			}
		}
	}
}


void resuelveCaso() {
    // leer los datos de la entrada
	bintree<char> arb = leerArbol('.');
	if(!arb.empty()){
		tsol sol = resolver(arb);
		cout << sol.estado << endl;
	}
	else{
		cout << "COMPLETO" << endl;
	}
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
    #ifndef DOMJUDGE
     std::ifstream in("datos.txt");
     auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
     #endif


    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();


    // Para restablecer entrada. Comentar para acepta el reto
     #ifndef DOMJUDGE // para dejar todo como estaba al principio
     std::cin.rdbuf(cinbuf);
     system("PAUSE");
     #endif

    return 0;
}

/*
 * 	if(!arb.empty()){
		queue<pair<bool, bintree<char>>> pendientes;
		pendientes.push(pair<bool, bintree<char>>(true, arb));
		while(!pendientes.empty() && st != NADA){
			pair<bool, bintree<char>> aux = pendientes.front();
			pendientes.pop();
			//Distinguir el cambio de nivel
			if(aux.first){
				marcado = false;
				faltan = false;
			}

			if (!Hoja(arb)) {
				if(aux.first){
					if(aux.second.right().empty()){
						faltan = true;
						st = SEMICOMPLETO;
					}
					if(aux.second.left().empty() && faltan){
						st = NADA;
					}
				}
				else{
					if(faltan){
						if(aux.second.right().empty()){
							faltan = true;
							st = SEMICOMPLETO;
						}
						if(aux.second.left().empty() && faltan){
							st = NADA;
						}
					}
					else{
						if(aux.second.left().empty() || aux.second.right().empty()){
							st = NADA;
						}
					}
				}
			}
			cout << "EL ESTADO ES " << st << endl;
			//Insertar elementos en la cola
			if(!aux.second.right().empty()){
				cout << "DERECHO * " << endl;
				if(!marcado){
					pendientes.push(pair<bool, bintree<char>>(true, aux.second.right()));
					marcado = true;
				}
				else{
					pendientes.push(pair<bool, bintree<char>>(false, aux.second.right()));
				}
			}
			if(!aux.second.left().empty()){
				cout << "IZQUIERDO * " << endl;
				if(!marcado){
					marcado = true;
					pendientes.push(pair<bool, bintree<char>>(true, aux.second.left()));
				}
				else{
					pendientes.push(pair<bool, bintree<char>>(false, aux.second.left()));
				}
			}

		}
		cout << st << endl;
		cout << "_______________" << endl;
 */
