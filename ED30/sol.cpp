// Nombre del alumno Guillermo Garcia PatiÃ±o Lenza
// Usuario del Juez A34


#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include "bintree_eda.h"
using namespace std;


// funcioÌ�n que resuelve el problema

//Busca un valor entre (num) entre dos posiciones de la lista (ini-fin)
int buscar(int num, unsigned int ini, unsigned int fin,vector<int> const& v){
	bool encontrado = false;
	unsigned int i = ini;
	while(i < fin && !encontrado){
		if(v[i] > num){
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
bintree<int> construir(unsigned int preIni, unsigned int preFin, vector<int> const & preorden){

	if(preFin - preIni <= 0){
		//Si no hay hijo devuelvo un arbol vacio
		bintree<int> arb;
		return arb;
	}
	else if(preFin - preIni == 1){
		//Si este hijo solo tiene un nodo, devuelvo un arbol con solo la raiz
		bintree<int> arb(preorden[preIni]);
		return arb;
	}
	else{


		//Cojo la raiz, que es el primero del trozo de preorden en el que estoy
		int root = preorden[preIni];
		//Busco en el preorden el primer elemento mayor que la raiz de este arbol
		int pos = buscar(root, preIni, preFin, preorden);


		//Construyo el hijo izquierdo  mirando desde el siguiente hasta la posicion del primer mayor
		bintree<int> ltree = construir(preIni + 1, pos, preorden);
		//Construyo el hijo derecho mirando desde la posicion del primer mayor hasta el final del preorden
		bintree<int> rtree = construir(pos, preFin, preorden);
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
// configuracioÌ�n, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
	vector<int> preorden;
	vector<int> inorden;

	string pre;


	getline(cin,pre);

    if (! std::cin){
        return false;
    }
    else{

    	transformaEnVector(pre,preorden);

    	bintree<int> arb = construir(0, preorden.size(), preorden);

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
