#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
using namespace std;

using vectord = vector<double>;
using matrixd = vector<vector<double>>;
using FuncFillMatrix = double(*)(double, unsigned, unsigned);

namespace algebra
{
    enum Error {SizeError, ZeroDivision};
    enum Direction {right, left, up, down};

    class Matrix
    {
    private:
        matrixd content;

    private:
        friend bool check_vector(const vector <bool> &v);
        friend bool check_matr_x(const Matrix &x0, const Matrix &x1, double epsilon);

    public:
        Matrix(unsigned m = 0, unsigned n = 0);     //  Creates a matrix of zeros
        double element(unsigned i, unsigned j) const;
        void set_element(double e, unsigned i, unsigned j);
        vectord row(unsigned i) const;
        void set_row(vectord &v, unsigned i);
        Matrix operator + (const Matrix &matr) const;       // Matrix addition
        Matrix operator - (const Matrix &matr) const;       // Matrix subtraction
        void clear();       // Completely cleans the container
        void resize(unsigned m, unsigned n);        // Changes the size of the matrix
        void randint(int a = 0, int b = 100);       // Fills a matrix of integer numbers
        void random();      // Fills a matrix of float numbers from 0 to 1
        void randfloat(int a = 0, int b = 100);         // Fills a matrix of float numbers
        void same_num(double num);      // Fills a matrix of same numbers
        void one();         // Creates identity matrices
        void zero();        // Creates zero matrices
        Matrix operator * (const Matrix &matr) const;       // Matrix multiplication
        Matrix operator * (double num) const;       // Matrix multiplication by scalar
        Matrix T() const;       // Matrix transposition
        Matrix minor(unsigned i, unsigned j) const;     // Finding minor
        double det() const;     // Calculating the determinant
        Matrix inverse() const;     // Finding the inverse matrix
        unsigned size_W() const;        // Number of lines
        unsigned size_H() const;        // Number of columns
        void operator *= (const Matrix &matr);       // Matrix multiplication
        void operator += (const Matrix &matr);       // Matrix addition
        void operator -= (const Matrix &matr);       // Matrix subtraction
        void operator *= (double num);       // Matrix multiplication by scalar
        void fill_matrix(FuncFillMatrix func);      // Filling the matrix using the lambda function
        Matrix replace_line(unsigned index) const;      // function to change the zero and non-zero string
        void delta(Direction d);        // Creating a triangular matrix
        friend Matrix operator * (double num, Matrix &matr);       // Matrix multiplication by scalar
        friend Matrix method_gauss(const Matrix &matr);     // Implementation of the Gauss method
        friend vectord reverse_step(const Matrix &matr);        // Finding unknowns after using the Gauss method


        friend Matrix method_iterations(const Matrix &matr, double E);
        friend Matrix method_zeidelya(const Matrix &matr, double E);
    };
    void print_row(const Matrix &matr, unsigned i, int a = 7, int b = 2);       // Print one of the rows of the matrix
    void print_matrix(const Matrix &matr, int a = 7, int b = 2);        // Print matrix
    void input_matrix(Matrix &matr);        // Sequential line by element entry
}

#endif // MATRIX_H
