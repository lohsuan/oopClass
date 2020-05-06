#ifndef MATRIX_H
#define MATRIX_H
#include "math_vector.h"
#include "dot.h"

class Matrix {
public:

  Matrix(double *a[], int row, int col){
    _row = row;
    _col = col;
    _m = new double [_row * _col];
    for(int i=0 ; i<_row ; i++){
      for(int j=0 ; j<_col ; j++){
        _m[i*_col + j] = a[i][j];
      }
    }
  }

  Matrix(int row, int col) {
    _row = row;
    _col = col;
    _m = new double[_row * _col];
    for(int i = 0; i < _row*_col; i++) {
      _m[i] = 0.0;
    }
  }
  
  Matrix(Matrix const & a){  // copy constructor
    _row = a._row;
    _col = a._col;
    _m = new double [_row * _col];
    for(int i=0 ; i<_row ; i++){
      for(int j=0 ; j<_col ; j++){
        _m[i*_col + j] = a._m[i*_col + j];
      }
    }
  }

  ~Matrix() { // destructor
    if(_m){
      delete [] _m;
    }
  }

  Matrix operator * (Matrix const & other) {
    Matrix result(_row, other._col);
    for(int i = 1; i <= _row; i++) {
      for(int j = 1; j <= other._col; j++) {
        // result.at(i, j) = row(i).dot(other.column(j));
        result.at(i, j) = dot(row(i), other.column(j));
      }
    }
    return result;
  }

  double & at(int i, int j) const {
    return _m[(i-1)*_col + (j-1)];
  }

  MathVector row(int i) {
    return MathVector(_m + (i-1)*_col, _col); // MathVector(double a[], int dim)
  }

  MathVector column(int j) const {
    MathVector result(_row);
    for(int i = 1; i <= _row; i++) {
      result.component(i) = at(i, j); // optimization: inline function
    }
    return result;
  }

private:
  int _row;
  int _col;
  double *_m;
};

#endif
