#ifndef TERM_H
#define TERM_H
#include <cmath>
class Term {
public:
    // default constructor
    // default constructor should construct a term //
    // with coefficient 0 and exponent zero        //
    Term(){
      _c = 0;
      _e = 0;
    }
    // constructor
    Term(double coefficient, int exponent){
      _c = coefficient;
      _e = exponent;
    }

    // operator assignment
    Term & operator=(Term const &t){
      _c = t._c;
      _e = t._e;
      return *this;
    }

    // operator add
    Term operator+(Term const &t){
      Term result = *this;
      if(result._e != t._e){
        throw std::string("undefined");
      }
      result._c += t._c;
      return result;
    }

    // operator multiply
    Term operator*(Term const &t){
      Term result = *this;
      result._c *= t._c;
      result._e += t._e;
      return result;
    }

    // operator equal
    bool operator==(Term const &t){
      if(_e == t._e && _c == t._c)
        return true;
      return false;
    }

    // access coefficient of a term
    double &  getCoefficient() {
      return _c;
    }

    // access exponent of a term
    int getExponent() const {
      return _e;
    }

    // evaluate by a given x
    double evaluate(double x){
      return _c * pow(x, _e);
    }

private:
    // please add member data if needed
    double _c;
    int _e;
};
#endif
