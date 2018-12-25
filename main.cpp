#include "matrix.h"
#include <iostream>

using namespace std;

using namespace algebra;

int main()
{
    Matrix m1(3, 3);
    Matrix m2(3, 3);
    input_matrix(m1);
    m2 = m1;
    m2 = m1 * m2;
    print_matrix(m2);
    return 0;
}
