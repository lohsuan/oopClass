#include "math_vector.h"
double dot(double *u, int dim_u, double *v, int dim_v){

  double result = 0;
  if(dim_u != dim_v){
    throw std::string("undefined");  // throw out error message
  }
  for(int i=0 ; i<dim_u ; i++){
    result += u[i] * v[i];
  }

  return result;
}
double dot(MathVector & u, MathVector & v){
  double result = 0;
  for(int i=1 ; i<=u.getDim() ; i++){
    result += v.component(i) * u.component(i);
  }
  return result;
}
