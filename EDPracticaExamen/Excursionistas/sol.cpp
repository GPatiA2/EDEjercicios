// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree_eda.h"
using namespace std;

struct valores{
	int excursionistas;
	int equipos;
};

valores rescatar(const bintree<int> & arb){
	if(arb.empty()){
		return {0,0};
	}
	else{
		valores vI = rescatar(arb.left());
		valores vD = rescatar(arb.right());

		valores v;
		v.equipos = 0;
		v.excursionistas = max(vD.excursionistas, vI.excursionistas);
		v.excursionistas += arb.root();

		if(arb.root() == 0){
			v.equipos = vD.equipos + vI.equipos;
		}
		else{
			if(vI.equipos == 0 && vD.equipos == 0){
				v.equipos+=1;
			}
			else if(vI.equipos == 0 && vD.equipos != 0){
				v.equipos = max(vD.equipos, vI.equipos);
			}
			else if(vI.equipos != 0 && vD.equipos == 0){
				v.equipos = max(vD.equipos, vI.equipos);
			}
			else{
				v.equipos = max(vD.equipos, vI.equipos);
				v.equipos += 1;
			}
		}

		return v;

	}
}

void resuelveCaso() {
    // leer los datos de la entrada
	bintree<int> arb = leerArbol(-1);
	valores i = rescatar(arb);
	cout << i.equipos << " " << i.excursionistas <<endl;
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
