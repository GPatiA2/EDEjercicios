// Nombre del alumno Guillermo Garcia Patiño Lenza
// Usuario del Juez A34


#include <iostream>
#include <iomanip>
#include <fstream>
#include "consultorio.h"
using namespace std;


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
	int num;
	cin >> num;
    if (!cin){
        return false;
    }
    else{
//    	cout << num << endl;
    	consultorio c;
    	string instruccion;
    	for(int i = 0; i < num; i++){
    		cin >> instruccion;

    		try{
				if(instruccion == "nuevoMedico"){
					string nombre;
					cin >> nombre;
					c.nuevoMedico(nombre);
				}
				else if(instruccion == "pideConsulta"){
					string paciente;
					cin >> paciente;
					string medico;
					cin >> medico;
					int dia;
					cin >> dia;
					string hora;
					cin >> hora;
					fecha f(dia, hora);
					c.pideConsulta(paciente,medico, f);
				}
				else if(instruccion == "listaPacientes"){
					string medico;
					cin >> medico;
					int dia;
					cin >> dia;
					vector<cita> v = c.listaPacientes(medico, dia);
					cout << "Doctor " << medico << " dia " << dia << endl;
					for(cita c : v){
						cout << c.p << " " << c.f.getHora()  <<endl;
					}
				}
				else if(instruccion == "siguientePaciente"){
					string medico;
					cin >> medico;
					string s = c.siguientePaciente(medico);
					cout << "Siguiente paciente doctor " << medico << endl;
					cout << s << endl;
				}
				else if(instruccion == "atiendeConsulta"){
					string medico;
					cin >> medico;
					c.atiendeConsulta(medico);
				}
    		}
			catch (invalid_argument & ia){
				cout << ia.what() << endl;
			}
			catch (domain_error & de){
				cout << de.what() << endl;
			}
    	}
    	cout << "---" << endl;
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
