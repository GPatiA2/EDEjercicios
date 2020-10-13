// Nombre del alumno Guillermo Garcia Patiño Lenza
// Usuario del Juez A34


#include <iostream>
#include <iomanip>
#include <fstream>
#include "queue_eda.h"
#include "deque_eda.h"
using namespace std;



// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
	int tamanio;
	int sobres;
	cin >> tamanio;
	cin >> sobres;
    if (tamanio == 0 && sobres == 0){
        return false;
    }
    else{
    	//Para resolver el problema voy a tener siempre una cola de tamanio igual a tantos sobres como pida
    	//	el caso de prueba, con los sobres consecutivos que estoy mirando

    	//Por otro lado voy a mantener una cola doble que va a contener los elementos maximos de cada conjunto
    	// de tres consecutivos. Se va a ir modificando con cada insercion en la cola anterior.
    	int aux;
    	queue<int> orig;
    	deque<int> maxes;
    	//Primero inserto el numero de sobres que se me piden en la cola original
    	for(int i = 0; i < sobres; i++){
    		cin >> aux;
    		orig.push(aux);
    		//Mientras tanto, en la cola doble donde tengo los maximos, si esta vacia inserto el que este insertando
    		// en este momento. Si no, compruebo si lo que voy a insertar es mas grande que el ultimo elemento que he
    		// insertado. Si esto ultimo se cumple, voy a quitar de la cola doble todos los elementos menores que el que voy a insertar
    		// que se encuentren seguidos en la cola doble empezando por atras
    		while(!maxes.empty() && maxes.back() < aux){
    			maxes.pop_back();
    		}
    		//Despues, tendre en la parte de atras de la cola doble el elemento mayor que el que estoy insertando y que esta
    		// a la izquierda del que estoy insertando en la cola original (El elemento menor que el maximo pero mayor que
    		// el resto de los elementos de la cola orig)
    		maxes.push_back(aux);
    	}

    	//Al final del proceso, tengo en el front de la cola doble el elemento mayor de los que se encuentran en la cola
    	// orig
    	cout << maxes.front() << " ";

    	for(int i = sobres; i < tamanio; i++){
    		//Ahora voy a ir insertando en la cola orig los siguientes elementos
    		cin >> aux;

    		//Si el elemento en el front de orig es igual al de maxes, significa que el maximo de los tres elementos actuales
    		// se va de la cola cuando inserte el siguiente
    		if(maxes.front() == orig.front()){
    			//Asi que ya no es el maximo de los tres elementos que hay en la cola orig, lo tengo que quitar de maxes
    			maxes.pop_front();
    		}
    		//Quito un elemento de orig, ya que siempre quiero mantener la misma cantidad de sobres en la cola orig
    		orig.pop();

    		//Meto en orig el elemento que estoy insertando
    		orig.push(aux);

    		//Para garantizar que el elemento en front de maxes es el elemento mayor de los tres que hay en orig,
    		// tengo que repetir el proceso del principio
    		while(!maxes.empty() && maxes.back() < aux){
				maxes.pop_back();
			}
    		//Meto el elemento que acabo de poner en orig, en aux
			maxes.push_back(aux);

			//Como maxes.front siempre es el elemento mayor de los que estan en Orig, imprimo maxes.front
			cout << maxes.front() << " ";
    	}
    	cout << endl;
		return true;
    }

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
     system("PAUSE");
     #endif

    return 0;
}

//
//for(int i = 0; i < sobres; i++){
//		//Primero saco el numero de sobres que necesito y hago el maximo de todos
//		if(sobres == 1){
//			//Si es uno, voy sacando uno a uno
//			m = orig.front();
//		}
//		else{
//			m = max(m, orig.front());
//		}
//		orig.pop();
//	}
//	cout << m << " ";
//	while(!orig.empty()){
//		//Despues voy sacando uno a uno y haciendo el maximo
//		// (el maximo de los tres anteriores)
//		if(sobres == 1){
//			m = orig.front();
//		}
//		else{
//			m = max(m, orig.front());
//		}
//		orig.pop();
//		cout << m << " ";
//	}
