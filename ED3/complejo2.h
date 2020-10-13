/*
 * Guillermo Garcia Patiño Lenza
 * A34
 */
//
//#ifndef COMPLEJO2_H_
//#define COMPLEJO2_H_
//
//#include <cmath>
//#include <iostream>
//using namespace std;
//
//class Complejo{
//private:
//	float real;
//	float imaginario;
//
//public:
//	Complejo(float r, float i){
//		real = r;
//		imaginario = i;
//	}
//
//	Complejo(){}
//
//	~Complejo(){}
//
//	void setR(float r){
//		real = r;
//	}
//
//	void setI(float i){
//		imaginario = i;
//	}
//
//	float getR()const{return real;}
//	float getI()const{return imaginario;}
//
//	Complejo operator*(Complejo const & c){
//		float r1 = getR();
//		float i1 = getI();
//		float r2 = c.getR();
//		float i2 = c.getI();
//
//		float aux1 = r1*r2 - i1 * i2;
//		float aux2 = r1*i2 - r2 * i1;
//
//		return Complejo(aux1, aux2);
//	}
//
//	Complejo operator+(Complejo const & c){
//		float r1 = getR();
//		float i1 = getI();
//		float r2 = c.getR();
//		float i2 = c.getI();
//
//		return Complejo(r1+r2 , i1+i2);
//	}
//
//	float mod(){
//		return sqrt((real*real) + (imaginario*imaginario));
//	}
//
//
//
//};
//
//
//inline istream& operator>> (istream & in, Complejo & c){
//	float r, i;
//	in >> r;
//	in >> i;
//	c.setI(i);
//	c.setR(r);
//	return in;
//}
//

#endif /* COMPLEJO2_H_ */
