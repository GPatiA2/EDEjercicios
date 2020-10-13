#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree_eda.h"
using namespace std;

struct valores{
	int caballeros;
	int mostruos;
	int salvo;
};


valores num_a_salvo(bintree<char> const & arb, int valPrev){
	if(arb.empty()){
		return {0,0,0};
	}
	else{
		//Primero hago una variable local que va a ser la que luego devuelva con los datos acumulados
		valores vRet;
		vRet.caballeros = 0;
		vRet.salvo = 0;
		//Voy a calcular los monstruos a la que bajo
		if(arb.root() == 'M'){
			//Sumo 1 a los monstruos aqui porque  tengo que contar los monstruos hasta el nodo en el que estoy
			valPrev += 1;
		}

		//Calculo los valores tanto para el arbol izquierdo como para el derecho
		valores vI = num_a_salvo(arb.left(), valPrev);
		valores vD = num_a_salvo(arb.right(), valPrev);

		//A partir de ahora, en valPrev tengo informacion sobre los datos exclusivamente encima del nodo
		//	y en vD/vI tengo informacion sobre los datos exclusivamente debajo del nodo.
		//	Acumulo en vRet los valores de vD y vI y devuelvo la informacion hacia arriba
		//Los caballeros que hay debajo de este nodo es la suma de los caballeros bajo el hijo izquierdo + los del hijo derecho
		vRet.caballeros += vI.caballeros+vD.caballeros;

		//Los nodos a salvo debajo de este nodo es la suma de los nodos a salvo de los hijos
		vRet.salvo += vD.salvo + vI.salvo;

		//Si el nodo es una Dama, sumo 1 a los que hay a salvo
		if(arb.root() == 'D' && vRet.caballeros >= valPrev){ vRet.salvo += 1;}

		//Si este nodo es un caballero, sumo 1 a los caballeros despues de calcular los nodos a salvo, porque
		//	los caballeros solo cuentan por debajo del nodo
		if(arb.root() == 'C'){ vRet.caballeros += 1;}

		return vRet;
	}
}

void resuelveCaso(){
	bintree<char> arb = leerArbol('.');
	valores vFin = num_a_salvo(arb, 0);
	cout << vFin.salvo << endl;
}


int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
    #ifndef DOMJUDGE
     std::ifstream in("datos.txt");
     auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
     #endif

    int numcasos;
    cin >> numcasos;
    for(int i = 0; i < numcasos; i++){resuelveCaso();}


    // Para restablecer entrada. Comentar para acepta el reto
     #ifndef DOMJUDGE // para dejar todo como estaba al principio
     std::cin.rdbuf(cinbuf);
     system("PAUSE");
     #endif

    return 0;
}
