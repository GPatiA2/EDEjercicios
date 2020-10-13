// Nombre del alumno Guillermo Garcia Patiño Lenza
// Usuario del Juez A34


#include <iostream>
#include <iomanip>
#include <fstream>
#include <map>
using namespace std;

// funcioÌ�n que resuelve el problema
using numero_cap = int;
using dia = int;

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracioÌ�n, y escribiendo la respuesta

//En realidad, lo que voy buscando es el segmento mas grande entre dos iguales
//Si no hay dos iguales, el segmento mas grande se calcula desde el ultimo igual que vi hasta el final.
void resuelveCaso() {
    // leer los datos de la entrada
    int capitulos;
    cin >> capitulos;
    int ini = 0;
    int act = 0;
    int top = 0;
    int val;
	map<numero_cap, dia> serie;
   for(int i = 0; i < capitulos; i++){
    	cin >> val;
    	if(!serie.count(val)){
    		//Si aun no han puesto este capitulo, anoto el dia en el que lo han puesto
    		serie[val] = i;
    	}
    	else{
    		//Si ya han puesto este capitulo
    			//Actualizo el maximo
    		top = max(top, i-ini);
    			//Actualizo la posicion del segmento a la siguiente a la ultima aparicion de ese elemento
    		if(serie.find(val)->second + 1 >= ini){
    			ini = serie.find(val)->second + 1;
    		}
    			//Actualizo la ultima vez que han puesto el capitulo
    		serie.find(val)->second = i;
    	}
//		cout << "INI = " << ini << " TOP = " << top << " I = " << i << endl;
    }
   	top = max(capitulos-ini, top);
    cout << top << endl;
    
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
