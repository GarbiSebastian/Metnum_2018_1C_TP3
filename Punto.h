/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   Punto.h
 * Author: panda
 *
 * Created on 12 de junio de 2018, 12:12
 */

#ifndef PUNTO_H
#define PUNTO_H

class Punto {
public:
	Punto(double x, double y);
	Punto();
	Punto(const Punto& orig);
	virtual ~Punto();
	double x;
	double y;
	Punto operator+(const Punto p) const;
	Punto operator*(const double d) const;
	Punto operator-(const Punto p) const;
	void normalizar();
private:

};


#endif /* PUNTO_H */

