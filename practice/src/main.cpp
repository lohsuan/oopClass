#include<iostream>
#include"dot.h"

int main(){

  double u[2] = {1, 0};
  double v[2] = {1, 1};

  double result = dot(u, 2, v, 2);
  std::cout << result << std::endl;

  double *c = new double[2];
  double *d = new double[2];

  for (int i=0 ; i<2 ; i++) {
    c[i] = i+1;   //{1, 2}
    d[i] = i+3;   //{1, 4}
  }
  result = dot(c, 2, d, 2);
  std::cout << result << std::endl;

  delete [] c;
  delete [] d;
  
  return 0;
}
