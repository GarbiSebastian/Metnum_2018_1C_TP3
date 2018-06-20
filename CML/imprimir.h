#ifndef IMPRIMIR_H
#define IMPRIMIR_H

using namespace std;
#ifdef __cplusplus
extern "C" {
#endif
#ifdef __cplusplus
}
#endif

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

