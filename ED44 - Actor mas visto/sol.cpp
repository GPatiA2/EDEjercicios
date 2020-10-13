// Nombre del alumno Guillermo Garcia Patiño Lenza
// Usuario del Juez A34


#include <iostream>
#include <iomanip>
#include <fstream>
#include <unordered_map>
#include <map>
#include <vector>
#include <set>
using namespace std;

using pelicula = string;
using aparicion = int;
using actor = string;

typedef struct{
	unordered_map<pelicula, aparicion> part; //De un actor para cada pelicula, el tiempo que aparece
	int total; //total de minutos del actor
}tinfo;

typedef struct{
	int apa; //Ultima aparicion de la pelicula
	int rep; //Repeticiones de una pelicula
	set<actor> reparto;
}tpeli;

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracioÌ�n, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int peliculas;
    cin >> peliculas;
    if (peliculas == 0){
        return false;
    }
    else{
    	map<actor, tinfo> actores; //Mapa de los actores y su aparicion en cada pelicula
    	unordered_map<pelicula, tpeli> pelis;
    	pelicula nombrePeli;
    	int nActores;
    	//se leen los datos para cada actor en cada peli
    	for(int i = 0; i < peliculas; i++){
    		cin >> nombrePeli; //Leo la pelicula
    		cin >> nActores;   //Leo el numero de actores que tiene
    		int minutos;
    		string nombreActor;
    		for(int j = 0; j < nActores; j++){
    			cin >> nombreActor; //Leo el nombre del actor
    			cin >> minutos;     //Leo el numero de minutos que aparece en esa pelicula
    			//Meto los datos en la tabla que corresponde a la participacion de este actor en esta pelicula
    			actores[nombreActor].part[nombrePeli] = minutos;
    			actores[nombreActor].total = 0;
    			pelis[nombrePeli].reparto.insert(nombreActor);
    		}
    	}
    	cin >> peliculas;

    	pelicula p; //Nombre de la pelicula que voy a leer

    	//Se leen los datos de cuando ponen las peliculas y las veces que las ponen

    	int maxT = 0; //Maximo de tiempo de un actor en pantalla
    	pair<pelicula, tpeli> aux1; //Pelicula que mas han puesto, junto con su info
    	aux1.second.apa = 0;  aux1.second.rep = 0;

    	//Voy leyendo la pelicula
    	for(int i = 0; i < peliculas; i++){
    		cin >> p; //Leo el titulo

    		pelis[p].rep++; //Le sumo una repeticion
    		pelis[p].apa = i; //Indico el indice de su ultima aparicion

    		//Si la pelicula se ha emitido mas veces que la que mas veces se ha emitido, y ha aparecido despues que
    		//  la pelicula que mas veces se ha emitido
    		if(pelis[p].rep >= aux1.second.rep || (pelis[p].rep == aux1.second.rep && pelis[p].apa > aux1.second.apa)){
    			//Actualizo los datos de la pelicula que mas veces se ha emitido
    			aux1.first = p;
    			aux1.second = pelis[p];
    		}

    		//Para cada actor
    		for(auto a: pelis[p].reparto){
    			auto & tiempos = actores[a];
				//Le sumo el tiempo que ha salido en esa pelicula
				tiempos.total += tiempos.part[p];
				//Hago el maximo
				maxT = max(maxT, tiempos.total);

    		}
    	}

    	cout << aux1.second.rep << " " << aux1.first << endl;

    	cout << maxT << " ";
    	for(auto ac: actores){
    		if(ac.second.total >= maxT){
    			cout << ac.first << " ";
    		}
    	}
    	cout << endl;

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
     system("PAUSE");
     #endif
    
    return 0;
}
