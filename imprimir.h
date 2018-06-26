#ifndef IMPRIMIR_H
#define IMPRIMIR_H

#include "typedefs.h"
#include <vector>
#include <iostream>
#include <iomanip>

using namespace std;
#ifdef __cplusplus
extern "C" {
#endif
#ifdef __cplusplus
}
#endif

template<typename T>
void imprimir(vector< vector< T > > &m, ostream &out) {
	for (unsigned int i = 0; i < m.size(); i++) {
		vector< T > v = m[i];
		for (unsigned int j = 0; j < v.size(); j++) {
			out << v[j] << " ";
		}
		out << endl;
	}
}

template<typename T>
void imprimirUchar(vector< vector< T > > &m, ostream &out) {
	for (unsigned int i = 0; i < m.size(); i++) {
		vector< T > v = m[i];
		for (unsigned int j = 0; j < v.size(); j++) {
			out << (int) v[j] << " ";
		}
		out << endl;
	}
}

//
//template<typename T>
//void imprimir(vector< vector< T > > &m){
//	imprimir(m,cout);
//}

template<typename T>
void imprimir(vector<T> &v, ostream &out, bool transpuesto) {
	out << scientific;
	if (transpuesto) {
		for (unsigned int i = 0; i < v.size(); i++) {
			//			out << (double)v[i] << endl;
			out << v[i] << endl;
		}
	} else {
		//		out << (double)v[0];
		out << (int) v[0];
		for (unsigned int i = 1; i < v.size(); i++) {
			//			out << " " << (double)v[i];
			out << " " << v[i];
		}
		out << endl;
	}
}

template<typename T>
void imprimirUchar(vector<T> &v, ostream &out, bool transpuesto) {
	out << scientific;
	if (transpuesto) {
		for (unsigned int i = 0; i < v.size(); i++) {
			//			out << (double)v[i] << endl;
			out << (int) v[i] << endl;
		}
	} else {
		//		out << (double)v[0];
		out << (int) v[0];
		for (unsigned int i = 1; i < v.size(); i++) {
			//			out << " " << (double)v[i];
			out << " " << (int) v[i];
		}
		out << endl;
	}
}

template<typename T>
void imprimir(vector<T> &v, ostream &out) {
	imprimir(v, out, false);
}

template<typename T>
void imprimir(vector<T> &v) {
	imprimir(v, cout);
}

void imprimir(Punto &p) {
	cout << "x: " << p.x << " - y: " << p.y << endl;
}

template<typename NumericType>
void imprimirOctave(const vector< vector<NumericType> >& A) {
	unsigned int m = A.size(), n = A[0].size();
	cerr << "[ ";
	for (unsigned int i = 0; i < m; i++) {
		for (unsigned int j = 0; j < n; j++) {
			cerr << A[i][j] << ", ";
		}
		cerr << "; ";
	}
	cerr << " ];" << endl << endl;

}

template<typename NumericType>
void imprimirOctave(const vector<NumericType>& v) {
	unsigned int m = v.size();
	cerr << "[ ";
	for (unsigned int i = 0; i < m; i++) {
		cerr << v[i] << ", ";
	}
	cerr << " ]';" << endl << endl;
}


#endif /* IMPRIMIR_H */

