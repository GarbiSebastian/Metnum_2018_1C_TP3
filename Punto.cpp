/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   Punto.cpp
 * Author: panda
 *
 * Created on 12 de junio de 2018, 12:12
 */
#include <math.h>
#include "Punto.h"

Punto::Punto(double x1, double y1) {
	this->x = x1;
	this->y = y1;
}

Punto::Punto() {

}

Punto::Punto(const Punto& orig) {
	x = orig.x;
	y = orig.y;
}

Punto::~Punto() {
}

Punto Punto::operator+(const Punto p) const {
	Punto res;
	res.x = p.x + this->x;
	res.y = p.y + this->y;
	return res;
}

Punto Punto::operator-(const Punto p) const {
	Punto res;
	res.x = p.x - this->x;
	res.y = p.y - this->y;
	return res;
}

Punto Punto::operator*(const double d) const {
	Punto res;
	res.x = this->x*d;
	res.y = this->y*d;
	return res;
}

void Punto::normalizar() {
	double norma = sqrt(pow(this->x, 2) + pow(this->y, 2));
	this->x = this->x / norma;
	this->y = this->y / norma;
}