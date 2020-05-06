#ifndef DOT_H
#define DOT_H


#include "math_vector.h"

double dot(double *u, int dim_u, double *v, int dim_v){

  double result = 0;
  if (dim_u != dim_v) {
    throw std::string("undefined");
  }
  for(int i=0; i<dim_u; i++) {
    result += u[i] * v[i];
  }
    return result;
}

double dot(MathVector const & u, MathVector const & v){
  double result = 0;
  for(int i=1; i<=u.dimension(); i++){
    result += u.component(i) * v.component(i);
  }
  return result;
}
#endif
