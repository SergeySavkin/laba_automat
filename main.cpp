#include "matrix.h"
#include <iomanip>
#include <iostream>

using namespace std;

using namespace algebra;

void print_X(const Matrix &X, int a, int b)
{
    cout << endl;
    for (unsigned i = 0; i < X.size_H(); i++)
    {
        cout << "x[" << i + 1 << "] = " << fixed << setw(a) << setprecision(b) << X.element(i, 0) << endl;
    }

    cout << endl;
}

int main()
{
    Matrix m1(3, 4);
    input_matrix(m1);
    cout << "Method Iteration: " << endl;
    print_X(method_iterations(m1, 0.00001), 13, 7);
    cout << "Method Zeidelya: " << endl;
    print_X(method_zeidelya(m1, 0.00001), 13, 7);
    return 0;
}
