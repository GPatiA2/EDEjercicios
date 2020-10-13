// Nombre del alumno Guillermo Garcia Patiño Lenza
// Usuario del Juez A34


#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct{
	string nombre;
	int tiempo;
	string veredicto;
}tEnvio;

inline istream& operator >> (istream & in, tEnvio & t){
	in >> t.nombre;
	in >> t.tiempo;
	in >> t.veredicto;
	return in;
}

typedef struct{
	string estado;
	int tiempo;
	int intentos;
	bool resuelto;
}tProblema;

using problema = string;
using equipo = string;

typedef struct{
	int resueltos;
	int tiempo;
}tSol;

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracioÌ�n, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
	cin.ignore();

	map<equipo, map<problema, tProblema>> concurso; //Indica para cada equipo los resultados de cada problema
	map<equipo, tSol> resultados; //Agrupa para cada equipo, el tiempo total y los resueltos

    string equipo;
    cin >> equipo;
    while(equipo != "FIN"){
    	//Si el equipo no esta registrado, lo registro
    	if(!concurso.count(equipo)){
    		map<problema,tProblema> p;
    		concurso.insert({equipo,p});
    		resultados.insert({equipo, {0,0}});
    	}
      	//Leo el problema que han enviado
    	tEnvio envio;
    	cin >> envio;

    	//A partir de aqui puedo asumir que el equipo siempre estara registrado

    	if(concurso.at(equipo).count(envio.nombre) == 0){
			//Si ese equipo no ha enviado aun el problema, inserto los datos adecuados
    		tProblema p;
    		p.estado = envio.veredicto;
    		p.tiempo = (envio.veredicto != "AC") ? envio.tiempo+20 : envio.tiempo;
    		p.intentos = 1;
    		p.resuelto = false;
    		concurso.at(equipo).insert({envio.nombre, p});
    	}
    	else{
    		//Si no es el primer intento del problema
    		if(concurso.at(equipo).at(envio.nombre).estado != "AC"){
    			//Y el problema no esta correcto ya, sumo los datos adecuados para ese problema
    			concurso.at(equipo).at(envio.nombre).estado = envio.veredicto;
    			concurso.at(equipo).at(envio.nombre).intentos += 1;
    		}
    	}
    	if(concurso.at(equipo).at(envio.nombre).estado == "AC" && !concurso.at(equipo).at(envio.nombre).resuelto){
			//Si el problema en cuestion es correcto, agrupo los resultados en el otro mapa
			resultados.at(equipo).tiempo += concurso.at(equipo).at(envio.nombre).tiempo = envio.tiempo + 20 * (concurso.at(equipo).at(envio.nombre).intentos -1);;
			resultados.at(equipo).resueltos += 1;
			concurso.at(equipo).at(envio.nombre).resuelto = true;
		}

    	cin >> equipo;
    }
    // escribir sol

    vector<pair<string,tSol>> v;
    for(auto p : resultados){
    	v.push_back(p);
    }
    
    sort(v.begin(), v.end(), [](pair<string,tSol> s1, pair<string,tSol> s2) -> bool{
    	return (s1.second.resueltos > s2.second.resueltos) || (s1.second.resueltos == s2.second.resueltos && s1.second.tiempo < s2.second.tiempo) || (s1.second.resueltos == s2.second.resueltos && s1.second.tiempo == s2.second.tiempo && s1.first < s2.first);
    });

    for(auto p: v){
    	cout << p.first << " " << p.second.resueltos << " " << p.second.tiempo << endl;
    }
    cout << "---" << endl;
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
