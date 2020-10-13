// Nombre del alumno Guillermo Garcia Patiño Lenza
// Usuario del Juez A34


#include <iostream>
#include <iomanip>
#include <fstream>
#include <stack>
#include <queue>
using namespace std;


// Resuelve un caso de prueba, leyendo de la entrada la
// configuracioÌ�n, y escribiendo la respuesta

void print(queue<char> frase){
	while(!frase.empty()){
		cout << frase.front();
		frase.pop();
	}
}

bool esVocal(char c){
	char a = tolower(c);
	if(a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u'){
		return true;
	}
	else{
		return false;
	}
}

bool resuelveCaso() {
    // leer los datos de la entrada
    queue<char> orig;
    string frase;
    getline(cin, frase);
    if (! std::cin){
        return false;
    }
    else{
    	//Meto en una cola simple el mensaje original
    	for(char c : frase){
    		orig.push(c);
    	}
    	//Voy a separar los caracteres del principio de los del final alternando
    	int cont = 0;
    	queue<char> front;
    	stack<char> back; //Para los del final uso una pila porque tengo que invertir su orden
    	while(!orig.empty()){
    		if(cont % 2 == 0){
    			front.push(orig.front());
    		}
    		else{
    			back.push(orig.front());
    		}
    		orig.pop();
    		cont++;
    	}

    	//Junto la parte de atras con la de delante sacando de la pila back
    	while(!back.empty()){
    		front.push(back.top());
    		back.pop();
    	}

//    	print(front);
//    	cout << endl;
    	//Ya he deshecho el segundo cifrado
    	//Voy a deshacer el primer cifrado
    	//Voy a usar back para invertir las vocales y asi no creo otra pila nueva
    	//Voy a ir rellenando en orig
    	while(!front.empty()){
    		if(esVocal(front.front())){
    			while(!back.empty()){
    				orig.push(back.top());
    				back.pop();
    			}
    			orig.push(front.front());
    		}
    		else{
    			back.push(front.front());
    		}
			front.pop();
    	}

    	while(!back.empty()){
    		orig.push(back.top());
			back.pop();
    	}

    	print(orig);
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
