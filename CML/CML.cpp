#include <cassert>
#include <cmath>
#include <iostream>

#include "CML.h"
#include "constantes.h"
#include "imprimir.h"

CML::CML() {
}

CML::CML(const CML& orig) {
}

CML::~CML() {
}

template<typename NumericType>
double productoInterno(const vector<NumericType> &u, const vector<NumericType> &v) {
    assert(u.size() == v.size());
    double sum = 0;
    for (unsigned int i = 0; i < u.size(); i++) {
        sum += u[i] * v[i];
    }
    return sum;
}

template<typename NumericType>
void A_por_v(const vector< vector<NumericType> >& A, const vector<NumericType>& v, vector<double>& resultado) {
    unsigned int m = A.size();
    unsigned int n = A[0].size();
    assert(n == v.size());
    assert(m == resultado.size());
    for (unsigned int i = 0; i < m; i++) {
        resultado[i] = productoInterno(A[i], v);
    }
}

template<typename NumericType>
void transponer(const vector< vector<NumericType> >&A, vector< vector<NumericType> >&At) {
    unsigned int m = A.size();
    unsigned int n = A[0].size();
    assert(At.size() == n);
    assert(At[0].size() == m);
    for (unsigned int i = 0; i < n; i++) {
        for (unsigned int j = 0; j < m; j++) {
            At[i][j] = A[j][i];
        }
    }
}

template<typename NumericType>
void At_por_A(vector<vector<NumericType> >& At, vector<vector<double> >& AtxA) {
    unsigned int n = At.size();
    unsigned int m = At[0].size();
    double calculo;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            calculo=0;
            for (int k = 0; k < m; k++) {
                calculo += At[i][k] * At[j][k];
            }
            AtxA[i][j] = calculo;
            AtxA[j][i] = calculo;
        }
    }
}

void eliminacionGaussiana(vector< vector<double> >& A, vector<double>& b) {
    double m_ij, a_ij, a_jj;
    unsigned int m = A.size();
    unsigned int n = A[0].size();
    assert(m==n);
    assert(m==b.size());
    for (unsigned int j = 0; j < m; j++) {
        a_jj = A[j][j];
        for (unsigned int i = j + 1; i < m; i++) {
            a_ij = A[i][j];
            if (fabs(a_ij) > epsilon) {//if a_ij != 0
                m_ij = a_ij / a_jj;
                for (unsigned int k = j; k < m; k++) {
                    A[i][k] = A[i][k] - m_ij * A[j][k];
                }
                b[i] = b[i] - m_ij * b[j];
            }
            A[i][j] = 0;
        }
    }
}

void backwardSubstitution(vector< vector<double> >& A,const vector<double>& b, vector<double>& x) {
    unsigned int m = b.size(),i;
    double suma_parcial, div;
    for (unsigned int _i = 0; _i < m; _i++) {
        i = m - 1 - _i;
        div = A[i][i];
        suma_parcial = 0;
        for (unsigned int j = i + 1; j < m; j++) {
            suma_parcial += x[j] * A[i][j] / div;
        }
        x[i] = b[i] / div - suma_parcial;
    }
}

void CML::resolver(vector<vector<int> >& A, vector<int>& b, vector<double>& x) {
    unsigned int m = A.size();
    unsigned int n = A[0].size();
    assert(m = b.size());
    assert(n = x.size());
    vector<vector<int> > At(n, vector<int>(m, 0));
    vector<vector<double> > AtxA(n, vector<double>(n, 0));
    vector<double> Atxb(n, 0);
    transponer(A, At);
//    cout << "At ="; imprimirOctave(At);
    At_por_A(At, AtxA);
//    cout << "AtxA ="; imprimirOctave(AtxA);
    A_por_v(At, b, Atxb);
//    cout << "Atxb ="; imprimirOctave(Atxb);
    eliminacionGaussiana(AtxA,Atxb);
//    cout << "AtxA_eg ="; imprimirOctave(AtxA);
//    cout << "Atxb_eg ="; imprimirOctave(Atxb);
    backwardSubstitution(AtxA,Atxb,x);

}