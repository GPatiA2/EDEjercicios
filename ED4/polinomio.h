/*
 * polinomio.h
 *
 *  Created on: 4 feb. 2020
 *      Author: Guille
 */

#ifndef POLINOMIO_H_
#define POLINOMIO_H_

#include <vector>
#include <utility>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <stdexcept>
using namespace std;

class Polinomio{
private:
	vector<pair<int,int>> monomios;
public:
	Polinomio(vector<int> const numeros){
		int indice = 0;
		for(unsigned int i = 0; i < numeros.size(); i += 2){
			monomios.push_back(make_pair(numeros[i], numeros[i+1]));
			indice++;
		}

//		sort(monomios.begin(), monomios.end(), comparaPares);
	}

	void setPolinomio(vector<int> & numeros){
		int indice = 0;
		for(unsigned int i = 0; i < numeros.size(); i += 2){
			monomios.push_back(make_pair(numeros[i], numeros[i+1]));
			indice++;
		}
	}

	Polinomio(){}

	bool comparaPares(const pair<int,int>  & p1, const pair<int, int> & p2){
		return p1.second > p2.second;
	}

	int evaluarPol(int x){
		int valor = 0;
		for(unsigned int i = 0; i < monomios.size(); i++){
			valor += pow(x,monomios[i].second)*monomios[i].first;
		}
		return valor;
	}

	void setPair(int index, pair<int,int> monomio){
		monomios.push_back(make_pair(monomio.first, monomio.second));
	}

	int getSize() const{
		return monomios.size();
	}

	pair<int,int> getPair(int index) const{
		return monomios[index];
	}

};

inline istream& operator>> (istream & in, Polinomio & p){
	vector<int> numeros;
	int first;
	int second;
	in >> first;
	in >> second;
	if(cin){
		while(!(first == 0 && second == 0)){
			numeros.push_back(first);
			numeros.push_back(second);
			in >> first;
			in >> second;
		}
	}
	else{
		throw invalid_argument("");
	}

	p.setPolinomio(numeros);
	return in;
}

inline ostream& operator<< (ostream & out, Polinomio const & p){
	int f, s;
	for(int i = 0; i < p.getSize(); i++){
		f = p.getPair(i).first;
		s = p.getPair(i).second;
		out << f << " " << s << " ";
	}

	out << '\n';

	return out;
}


#endif /* POLINOMIO_H_ */
