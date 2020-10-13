#include <iostream>
#include <iomanip>
#include <fstream>
#include <queue>
#include <cmath>
#include "bintree_eda.h"
using namespace std;

void resuelveCaso(vector<bool> const & primos){
	bintree<int> arb = leerArbol(-1);
	queue<pair<bintree<int>,bool>> pendientes;

	int nivel = 0;
	int valor;
	bool nivMarcado = false;
	bool encontrado = false;
		if(!primos[arb.root()] && !arb.empty()){
			pendientes.push({arb,true});
			nivMarcado = true;
		}

		while(!pendientes.empty() && !encontrado){
			pair<bintree<int>,bool> p = pendientes.front();
			pendientes.pop();

			if(p.second){
				nivMarcado = false;
				nivel++;
			}

			if(p.first.root() % 7 == 0){
				encontrado = true;
				valor = p.first.root();
			}

			if(!p.first.left().empty() && !primos[p.first.left().root()]){
				bool primer = !nivMarcado;
				pendientes.push({p.first.left(), primer});
				if(!nivMarcado){nivMarcado = true;}
			}

			if(!p.first.right().empty() && !primos[p.first.right().root()]){
				bool primer = !nivMarcado;
				pendientes.push({p.first.right(), primer});
				if(!nivMarcado){nivMarcado = true;}
			}

		}

		if(encontrado){
			cout << valor << " " << nivel << endl;
		}
		else{
			cout << "NO HAY" << endl;
		}


}


int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
    #ifndef DOMJUDGE
     std::ifstream in("datos.txt");
     auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
     #endif

    vector<bool> esPrimo(5000,true);
	esPrimo[0] = false; esPrimo[1] = false;
	for(int i = 2; i < sqrt(5000); ++i){
		if(esPrimo[i]){
			for(int j = i*i ; j < 5000; j+= i){
				esPrimo[j] = false;
			}
		}
	}

    int numcasos;
    cin >> numcasos;
    for(int i = 0; i < numcasos; i++){resuelveCaso(esPrimo);}


    // Para restablecer entrada. Comentar para acepta el reto
     #ifndef DOMJUDGE // para dejar todo como estaba al principio
     std::cin.rdbuf(cinbuf);
     system("PAUSE");
     #endif

    return 0;
}
