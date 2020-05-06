#ifndef MATH_VECTOR_H
#define MATH_VECTOR_H
#include <cmath>

class MathVector {

public:
  MathVector(double a[], int dim){
    _dim = dim;
    _vec = new double[_dim];
    for( int i=0 ; i<_dim ; i++) {
      _vec[i] = a[i];
    }
  }

  ~MathVector(){  // destructor
    delete []_vec;
  }


  MathVector(MathVector const & u){  // deep copy constructor
    _dim = u.getDim();
    _vec = new double[_dim];
    for( int i=0 ; i<_dim ; i++) {
      _vec[i] = u._vec[i];
    }
  }
  
  MathVector & operator = (MathVector & u) {
    // return's MathVector could be left or right value
    // so we need to pass result as a "variable" not "value"
    // by using reference operator (&)
    _dim = u.getDim();
    if(_vec != NULL){
      delete [] _vec;
    }
    _vec = new double[_dim];
    for( int i=0 ; i<_dim ; i++) {
      _vec[i] = u._vec[i];
    }
    return *this;
    // "this" is a "pointer" point to class MathVector itself
    // so we need to dereference it.
  }

  double & component (int index) const{
    return _vec[index-1];
  }

  bool isZero () const{
    for(int i=0 ; i<_dim ; i++) {
      if(_vec[i] != 0) return false;
    }
    return true;
  }
  double length(){
    int temp = 0;
    for(int i=0 ; i<_dim ; i++){
      temp += pow(_vec[i], 2);
    }
    return pow(temp, 0.5);
  }
  // double length() const {
  //   double temp = 0;
  //   for(int i=0 ; i<_dim ; i++){
  //     temp += pow(_vec[i], 2);
  //   }
  //   return pow(temp, 0.5);
  // }
  int getDim() const {
    return _dim;
  }
  double dot(MathVector const & v){
    double result = 0;
    for(int i=0 ; i<_dim ; i++){
      result += _vec[i] * v._vec[i];
    }
    return result;
  }

  MathVector add(MathVector const & v){
    MathVector result = *this;
    for(int i=1 ; i<=result.getDim() ; i++){
      result.component(i) += v.component(i);
    }
    return result;
  }
private:
  double *_vec;
  int _dim;

};

#endif
