/*
 * Guillermo Garcia Patiño Lenza
 * A34
 */

#ifndef COMPLEJO_H_
#define COMPLEJO_H_

#include<iostream>
#include<cmath>
using namespace std;

template <typename T>
class Complejo{
private:
	T pReal;
	T pImag;
	float mod;

	void calcMod(){
		mod = sqrt(pReal*pReal + pImag*pImag);
	}

public:
	Complejo(){}
	Complejo(T r,T i){
		pReal = r;
		pImag = i;
		calcMod();
	}

	Complejo<T> operator*(Complejo const & c){
		return Complejo(pReal*c.pReal - pImag*c.pImag, pReal*c.pImag+pImag*c.pReal);
	}

	Complejo<T> operator+(Complejo const & c){
		return Complejo(pReal+c.pReal , pImag+c.pImag);
	}

	void setRandI(T r, T i){pReal = r; pImag = i; calcMod();}

	bool valido () const {return mod <= 2;}

	~Complejo(){}
};

inline istream& operator>>(istream & in, Complejo<float> & c){
	float r, i;
	in >> r;
	in >> i;
	c.setRandI(r, i);
	return in;
}


#endif /* COMPLEJO_H_ */
