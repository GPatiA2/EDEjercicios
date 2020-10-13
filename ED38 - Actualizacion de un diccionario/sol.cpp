// Nombre del alumno Guillermo Garcia PatiÃ±o Lenza
// Usuario del Juez A34


#include <iostream>
#include <iomanip>
#include <fstream>
#include <map>
#include<string>
using namespace std;

// funcioÃŒï¿½n que resuelve el problema
using numero_cap = int;
using dia = int;

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracioÃŒï¿½n, y escribiendo la respuesta

using clave = string;
using valor = int;

//Funcion para leer los diccionarios en una linea
map<clave,valor> leerDiccionario(){
		map<clave, valor> m;
		string linea;
		getline(cin, linea);
		stringstream ss(linea);

		clave c;
		valor v;
		while(ss >> c){
			ss >> v;
			m.insert(pair<clave,valor>(c,v));
		}

		return m;
}


void resuelveCaso() {
    // leer los datos de la entrada
	map<clave, valor> m1 = leerDiccionario();
	map<clave, valor> m2 = leerDiccionario();

	//Se inicializan las cadenas que se van a mostrar por pantalla
	string add = "+ ";
	string sub = "- ";
	string cam = "* ";

	//Se colocan iteradores al principio de los dos diccionarios
	auto it1 = m1.begin();
	auto it2 = m2.begin();

	//Variables para comparar los dos diccionarios
	clave c1, c2;
	valor v1, v2;

	while(it1 != m1.end() && it2 != m2.end()){
		//Extraigo los valores de los pares de cada diccionario
		c1 = it1->first, c2 = it2->first;
		v1 = it1->second, v2 =  it2->second;

		//Si la clave del primer diccionario es mayor que la del segundo, es que se ha añadido antes de c1 una clave
		if(c1 > c2){
			add.append(c2 + " ");
			it2++;
		}
		//Si las claves son iguales pero cambian los valores, se ha cambiado el valor para la misma clave
		else if(c1 == c2 && v1 != v2){
			cam.append(c2 + " ");
			it1++;
			it2++;
		}
		//Si la clave del primer diccionario es mayor que la del segundo, se ha quitado una clave del primero
		else if(c1 < c2){
			sub.append(c1 + " ");
			it1++;
		}
		//Si claves y valores coinciden, avanzo los iteradores
		else if(c1 == c2 && v1 == v2){
			it1++;
			it2++;
		}

	}

	//Cuando acabe, si me quedan elementos del primero para recorrer, es que han sido quitados
	while(it1 != m1.end()){
		c1 = it1->first, v1 = it1->second;
		sub.append(c1 + " ");
		it1++;
	}
	//Si al acabar me quedan elementos del segundo sin recorrer, es que han sido añadidos
	while(it2 != m2.end()){
		c2 = it2->first, v2 = it2->second;
		add.append(c2 + " ");
		it2++;
	}


	if(add == "+ " && sub == "- " && cam == "* "){
		cout << "Sin cambios" << endl;
	}
	else{
		if(add != "+ "){
			cout << add << endl;
		}
		if(sub != "- "){
			cout << sub << endl;
		}
		if(cam != "* "){
			cout << cam << endl;
		}
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
    //Ignore añadido porque uso getline para leer despues
    cin.ignore();
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    
    // Para restablecer entrada. Comentar para acepta el reto
     #ifndef DOMJUDGE // para dejar todo como estaba al principio
     std::cin.rdbuf(cinbuf);
     system("PAUSE");
     #endif
    
    return 0;
}
