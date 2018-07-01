/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   main.cpp
 * Author: panda
 *
 * Created on 11 de junio de 2018, 11:46
 */

#include <cstdlib>
#include <iostream>
#include <vector>
#include <cassert>
#include <math.h>
#include <string>
#include "Punto.h"
#include "imprimir.h"
#include "LectorPNG.h"
#include "typedefs.h"




using namespace std;

bool enRango(Punto &puntito, double limite) {

	return (puntito.x >= 0 && puntito.y >= 0 && puntito.x < limite && puntito.y < limite);
}

matrizReal tiraRayo(Punto inicio, Punto dir) {
	Punto p = inicio;
	double delta = 0;
	matrizReal res(10, vectorReal(10, 0));
	dir.normalizar();
	while (enRango(p, 10)) {
		res[floor(p.x)][floor(p.y)] = 1;
		delta += 0.001;
		p = inicio + dir*delta;
	}
	delta = 0;
	p = inicio;
	while (enRango(p, 10)) {
		res[floor(p.x)][floor(p.y)] = 1;
		delta -= 0.001;
		p = inicio + dir*delta;
	}
	return res;
}

void test1() {
	unsigned int tam = 10;
	Punto inicio;
	inicio.x = 8.9;
	inicio.y = 8.1;
	Punto direccion;
	direccion.x = 1.3;
	direccion.y = -1.1;
	Punto p;
	//int x ,y;
	matrizReal a(tam, vectorReal(tam, 0));
	for (unsigned int i = 0; i < tam; i++) {
		for (unsigned int j = 0; j < tam; j++) {
			a[i][j] = (i * (tam)) + j;
		}
	}
	matrizReal b(tam, vectorReal(tam, 0));



	double delta = 0;
	assert(inicio.x >= 0 && inicio.x <= tam);
	assert(inicio.y >= 0 && inicio.y <= tam);
	direccion.normalizar();
	p = inicio;
	while (enRango(p, tam)) {

		b[floor(p.x)][floor(p.y)] = 1;
		delta += 0.001;
		p = inicio + direccion*delta;
	}
	p = inicio;
	while (enRango(p, tam)) {

		b[floor(p.x)][floor(p.y)] = 1;
		delta -= 0.001;
		p = inicio + direccion*delta;
	}


	imprimir(b);
}

int main(int argc, char** argv) {
	//	std::string str = "tomo.png";
	//	LectorPNG lalala(str.c_str());
	//	lalala.init();
	//	cout << lalala.mostramealgo() << " --  sadasdsadasdasdasdasdas" << endl;
	Punto i;
	Punto d1, d2;
	double r1, r2;
	cout << "lalalala" << endl;
	matrizReal a;
	for (int f = 0; f < 10; f++) {
		for (int c = 0; c < 10; c++) {
			i = Punto(f + .5, c + .5);
			r1 = rand() % 100;
			r2 = rand() % 100;
			d1 = Punto(r1, r2);
			d2 = Punto(r2, -r1);
			a = tiraRayo(i, d1);
			imprimir(a);
			cout << endl;
			a = tiraRayo(i, d2);
			imprimir(a);
			cout << endl;
		}
	}
	//	i.x = 0.999;
	//	i.y = 0.999;
	//	d.x = 0;
	//	d.y = 1;
	//	a = tiraRayo(i, d);
	//	imprimir(a);
	//	cout << endl;


	return 0;
}

