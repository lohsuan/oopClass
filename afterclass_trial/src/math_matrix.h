#ifndef MATH_MATRIX_H
#define MATH_MATRIX_H

// #include "math_vector.h"

class MathMatrix {
public:
  MathMatrix(double *arr, int row, int col){
    _row = row;
    _col = col;
    _mat = new double*[_row];
    for(int i=0 ; i<_row ; i++){
      _mat[i] = new double[_col];
    }
    for(int i=0 ; i<row ; i++){
      for(int j=0 ; j<col ; j++){
        _mat[i][j] = *((arr+i*col) + j);
      }
    }
  }
  double component(int row, int col){
    return _mat[row-1][col-1];
  }
private:
  double **_mat;
  int _col;
  int _row;
  // void initialize(double *ptr, int col, int row){
  //
  // }
};


#endif
