#ifndef CONVEX_POLYGON_H
#define CONVEX_POLYGON_H
#include "./math_vector.h"

class ConvexPolygon{
public:
  ConvexPolygon(MathVector vertices[], int numberOfVertices) {
    _numberOfVertices = numberOfVertices;
    _vertices = new MathVector[_numberOfVertices];
    for(int i=0 ; i<_numberOfVertices ; i++){
      _vertices[i] = vertices[i];
    }
  }
  ~ConvexPolygon() {
    if(_vertices!=nullptr)
      delete [] _vertices;
  }
  MathVector vertex(int index) {
    return _vertices[index];
  }
  double perimeter() const {
    double result = 0;
    for(int i=1 ; i<_numberOfVertices ; i++){
      result += (_vertices[i] - _vertices[i-1]).length();
    }
    result += (_vertices[0] - _vertices[_numberOfVertices-1]).length();
    return result;
  }

  double area() const {
    double result = 0;
    for(int i = 1; i < _numberOfVertices-1; i++){
      result += _vertices[0].areaWith(_vertices[i], _vertices[i+1]);
    }
    return result;
  }

private:
  MathVector *_vertices;
  int _numberOfVertices;

};


#endif
