// Nombre del alumno Guillermo Garcia Patiño Lenza
// Usuario del Juez A34


#include <iostream>
#include <iomanip>
#include <fstream>
#include "conjunto.h"
using namespace std;


// función que resuelve el problema


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
	char tipo;
	unsigned int mayores;
	cin >> tipo;
    if (! std::cin)
        return false;
    else{
    	cin >> mayores;
    	if(tipo == 'N'){
    		int aux;
    		set<int> cjto;
    		cin >> aux;
    		while(aux != -1){
    			if( cjto.size() < mayores || aux > cjto.getUltimo() ){
					cjto.insert(aux);
					if(cjto.size() > mayores){
						cjto.eliminaUltimo();
					}
				}
				cin >> aux;
    		}

    		for( int i = cjto.size()-1; i >= 0; i--){
				cout << cjto.getElem(i) << " ";
			}
			cout << endl;
    	}
    	else if(tipo == 'P'){
    		string aux;
    		set<string> cjto;
    		cin >> aux;
    		while(aux != "FIN"){
    			if(cjto.size() < mayores || aux > cjto.getUltimo() ){
					cjto.insert(aux);
    				if(cjto.size() > mayores){
						cjto.eliminaUltimo();
					}
    			}
    			cin >> aux;
    		}
    		for( int i = cjto.size()-1; i >= 0; i--){
				cout << cjto.getElem(i) << " ";
			}
    		cout << endl;
    	}
		return true;
    }

    // escribir sol



}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
    #ifndef DOMJUDGE
     std::ifstream in("datos.txt");
     auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
     #endif


    while (resuelveCaso())
        ;


    // Para restablecer entrada. Comentar para acepta el reto
     #ifndef DOMJUDGE // para dejar todo como estaba al principio
     std::cin.rdbuf(cinbuf);
//     system("PAUSE");
     #endif

    return 0;
}
