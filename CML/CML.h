#ifndef CML_H
#define CML_H

#include <vector>


using namespace std;

class CML {
public:
    CML();
    CML(const CML& orig);
    virtual ~CML();

    void resolver(vector< vector<int> >& A, vector<int>& b, vector<double>& x);
    void eg(vector< vector<double> >& A, vector<double>& b);
private:
};

#endif /* CML_H */
