#ifndef MATH_VECTOR_H
#define MATH_VECTOR_H
#include <cmath>

class MathVector {
  double *_vec;
  int _dim;

public:
  MathVector(double a[], int dim){
    _dim = dim;
    _vec = new double[_dim];
    for( int i=0 ; i<_dim ; i++) {
      _vec[i] = a[i];
    }
  }
  ~MathVector(){  
    delete []_vec;
  }

  MathVector(MathVector & a){
    _dim = a.getDim();
    _vec = new double[_dim];
    for( int i=0 ; i<_dim ; i++) {
      _vec[i] = a._vec[i];
    }

  }
  double component(int index) {
    return _vec[index-1];
  }

  bool isZero(){
    for(int i=0 ; i<_dim ; i++) {
      if(_vec[i] != 0) return false;
    }
    return true;
  }
  double length(){
    double temp = 0;
    for(int i=0 ; i<_dim ; i++){
      temp += pow(_vec[i], 2);
    }
    return pow(temp, 0.5);
  }
  int getDim(){
    return _dim;
  }
};

#endif
