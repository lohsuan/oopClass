#ifndef MATH_VECTOR_H
#define MATH_VECTOR_H
#include <math.h>
class MathVector {
private:
  double * _vec;
  int _dim;

public:
  MathVector(){    // default constructor
    _vec = nullptr;
    _dim = 0;
  }
  MathVector(double a[], int dim){
    initialize(a, dim);    // refactoring
  }

  MathVector(int dim){ // default
    double a[dim] = {0};
    initialize(a, dim);
  }


  MathVector(MathVector const & u){ // deep copy constructor
    //std::cout<<"copy constructor called."<<std::endl;
    initialize(u._vec, u._dim);    // refactoring
  }

  MathVector & operator = (MathVector const & v) {   // deep copy assignment
    if(_vec != 0){
      delete [] _vec;
    }
    initialize(v._vec, v._dim);
    return *this;
  }

  ~MathVector(){ //destructor
    if(_vec != nullptr)
      delete [] _vec;
  }

  double & component(int index) const {
    return _vec[index-1];
  }

  int dimension() const { // constant member function
    return _dim;
  }

  double dot(MathVector const & v) {
    double result = 0;
    for(int i = 0; i < _dim; i++) {
      result += _vec[i] * v._vec[i];
    }
    return result;
  }

  MathVector add(MathVector const & v) {
    MathVector result = *this;    // copy constructor
    for(int i=1 ; i<=result.dimension() ; i++){
      result.component(i) += v.component(i);
    }
    return result;    // return by value (c++ optimization : elision )
  }

  MathVector scale(double n) {
    MathVector result = *this;
    for(int i = 1; i <= _dim; i++) {
      result.component(i) *= n;
    }
    return result;
  }

  MathVector operator - (MathVector const & v) const {
    MathVector result = *this;    // copy constructor
    for(int i=1 ; i<=result.dimension() ; i++){
      result.component(i) -= v.component(i);
    }
    return result;    // return by value (c++ optimization : elision )
  }

  double length() const {
    double result=0;
    for(int i=1 ; i<=dimension() ; i++){
      result += component(i) *component(i);
    }
    return sqrt(result);
  }

  double areaWith(MathVector const & u, MathVector const & v) const {
    double result = 0;
    double a = (u-*this).length();
    double b = (v-*this).length();
    double c = (u-v).length();
    double s = (a + b + c)/2;
    result = s * (s-a) * (s-b) * (s-c);
    return sqrt(result);
  }

  double angleWith(MathVector u) {
    double result = dot(u)/(length()*u.length());
    return acos(result)/M_PI*180;
  }

private:
  void initialize(double * a, int dim){
    _dim = dim;
    _vec = new double[_dim];
    for(int i=0 ; i<_dim ; i++){
      _vec[i] = a[i];
    }
  }

};

MathVector centroid(MathVector u[], int n) {
  MathVector result(u[0].dimension());
  for(int i = 0; i < n; i++) {
    result = result.add(u[i]);
  }
  return result.scale(1.0/n);
}


#endif
