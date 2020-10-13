
// Guillermo Garcia Patiño Lenza
// A34

#include <iostream>               
#include <fstream>               
#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

// COMENTARIO SOBRE LA SOLUCIÃ“N Y SU COSTE JUSTIFICADO
/**
 * Para solucionar el problema voy a usar una tabla hash (ya que no se especifica orden en las claves, y asi minimizo tiempos de acceso,
 * busqueda e insercion) en las que, en la clave guardare el nombre del sensor, y en el valor usare un vector de Strings para guardar las
 * horas de los avisos en orden de llegada y poder acceder a ellos de manera lineal.
 *
 * Primero se leen todos los datos del problema y se insertan en el mapa, y despues se consultan el nombre del sensor, y la hora del
 * aviso i-esimo para ese sensor (siendo i el numero que leo de la entrada)
 *
 * Coste:
 *  Construir la tabla hash tiene Coste O(n) donde n es el tamanio inicial del vector de la tabla hash
 *  El primer bucle, para leer la entrada y almacenarla en el mapa, tiene Coste O(c*numavisos) donde numavisos es el numero de avisos que
 *  	dan los sensores y c una constante. (Ya que buscar en la tabla hash, insertar en ella, e insertar por dentras en un vector es todo de
 *  	coste constante)
 *  El segundo bucle, que se usa para consultar los datos que me piden por la entrada y mostrar la solucion por pantalla, tiene coste O(c*nConsultas)
 *  	donde nConsultas son el numero de consultas sobre avisos que se realizan y c es una constante (Como se ha mencionado antes, buscar en la
 *  	tabla es de coste constante, al igual que acceder a una posicion de un vector)
 *
 *  Al final, aplicando la regla de la suma, queda que el coste del problema es O(max(n, c*numavisos, c*nConsultas)), que si eliminamos las constantes
 *  	multiplicativas, queda que al final, el coste es O(t) lineal en el maximo entre las consultas que realizo y los avisos que recibo.
 */
using sensor = string;
using hora = string;

bool resuelveCaso() {
   int numavisos;
   cin >> numavisos;
   if (!cin){
      return false;
   }
   else{
	   int nConsultas;
	   cin >> nConsultas;
	   unordered_map<sensor,vector<hora>> avisos;
	   sensor s;
	   hora h;
	   for(int i = 0; i < numavisos; i++){
		   cin >> s; //Coste cte
		   cin >> h; //Coste cte
		   avisos[s].push_back(h); //Buscar coste cte, insertar en el vector por detras coste cte
	   }

	   unsigned int ordinal;
	   for(int j = 0; j < nConsultas; j++){
		   cin >> s; //Coste cte
		   cin >> ordinal; //Coste cte
		   if(avisos.count(s)){ //Coste cte
			   if(avisos.at(s).size() >= ordinal){ //Coste cte
				   cout << avisos.at(s).at(ordinal-1) << " "; //Coste cte
			   }
			   else{
				   cout << "-- "; //Coste cte
			   }
		   }
		   else{
			   cout << "-- "; //Coste cte
		   }
	   }
	   cout << endl;
	   return true;
   }

}


int main() {
   // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
   std::ifstream in("casos.txt");
   auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
   
   while (resuelveCaso());

   // para dejar todo como estaba al principio
#ifndef DOMJUDGE
   std::cin.rdbuf(cinbuf);
   system("PAUSE");
#endif
   return 0;
}
