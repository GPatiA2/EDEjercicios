// Nombre del alumno Guillermo Garcia Patiño Lenza
// Usuario del Juez A34


#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include "bintree_eda.h"
using namespace std;


// función que resuelve el problema

//Busca un valor entre (num) entre dos posiciones de la lista (ini-fin)
int buscar(int num, unsigned int ini, unsigned int fin,vector<int> const& v){
	bool encontrado = false;
	unsigned int i = ini;
	while(i < fin && !encontrado){
		if(v[i] == num){
			encontrado = true;
		}
		else{
			i++;
		}
	}
	return i;
}

// pre/in Fin/Ini indican los trozos de la lista donde estoy mirando

//Realmente me sobra el parametro preFin
bintree<int> construir(unsigned int preIni, unsigned int preFin, unsigned int inIni, unsigned int inFin, vector<int> const & preorden, vector<int> const & inorden){

	if(inFin - inIni <= 0){
		//Si no hay hijo devuelvo un arbol vacio
		bintree<int> arb;
		return arb;
	}
	else if(inFin - inIni == 1){
		//Si este hijo solo tiene un nodo, devuelvo un arbol con solo la raiz
		bintree<int> arb(inorden[inIni]);
		return arb;
	}
	else{

		//Cojo la raiz, que es el primero del trozo de preorden en el que estoy
		int root = preorden[preIni];
		//La busco en el inorden
		int pos = buscar(root, inIni, inFin, inorden);
		//El error estaba en que tengo que contar la distancia desde el inicio del inorden para saber donde
		//	empieza el otro arbol
		int ini2 = pos - inIni + 1;
		//Construyo el hijo izquierdo  mirando desde el principio del inorden hasta la posicion de la raiz
		bintree<int> ltree = construir(preIni + 1, preFin, inIni, pos, preorden, inorden);
		//Construyo el hijo derecho mirando desde la posicion de la raiz hasta el final del inorden
		bintree<int> rtree = construir(preIni + ini2, preFin, pos+1, inFin, preorden, inorden);
		//Construyo un nuevo arbol y lo devuelvo
		bintree<int> arb(ltree, root, rtree);

		return arb;
	}



}


void transformaEnVector(string s, vector<int> & v){

	stringstream stream(s);
	int num;
	while(stream >> num){
		v.push_back(num);
	}

}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
	vector<int> preorden;
	vector<int> inorden;

	string pre;
	string in;

	getline(cin,pre);

    if (! std::cin){
        return false;
    }
    else{
    	getline(cin, in);
    	transformaEnVector(pre,preorden);
    	transformaEnVector(in, inorden);



    	bintree<int> arb = construir(0, preorden.size(), 0, inorden.size(), preorden, inorden);

    	vector<int> postorden = arb.postorder();
    	for(unsigned int i = 0; i < postorden.size(); i++){
    		cout << postorden[i] << " ";
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
