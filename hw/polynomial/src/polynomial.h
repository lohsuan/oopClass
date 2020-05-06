#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H
#include "./term.h"
class Polynomial {
public:
    // consturctor
    Polynomial(Term *terms, int degree){
      _degree = degree;
      _terms = new Term[_degree+1];
      for(int i=0 ; i<=_degree ; i++){
        _terms[i] = terms[i];
      }
    }

    // copy constructor
    Polynomial(Polynomial const &p){
      _degree = p._degree;
      _terms = new Term[_degree+1];
      for(int i=0 ; i<=_degree ; i++){
        _terms[i] = p._terms[i];
      }
    }

    // destructor
    ~Polynomial(){
      if(_terms != nullptr)
        delete [] _terms;
    }

    // operator assignment
    Polynomial & operator=(const Polynomial &p){
      _degree = p._degree;
      if(_terms != nullptr)
        delete [] _terms;

      _terms = new Term[_degree+1];
      for(int i=0 ; i<=_degree ; i++){
        _terms[i] = p._terms[i];
      }
      return *this;
    }

    // operator add
    Polynomial operator+( Polynomial &p){
      Polynomial result = *this;
      int higher_dg = this->_degree;
      int lower_dg = p._degree;

      if(p._degree > higher_dg){
        higher_dg = p._degree;
        lower_dg = this->_degree;
        result = p;
        p = *this;
      }
      for(int i=0 ; i<=lower_dg ; i++){
        result._terms[i] = result._terms[i] + p._terms[i];
        //result.getTermByExponent(i).getCoefficient() += p.getTermByExponent(i).getCoefficient();
      }
      return result;
    }

    // get designate term by exponent
    Term & getTermByExponent(int exponent) {
      return _terms[exponent];
    }

    // degree of polynomial
    int getDegree(){
      return _degree;
    }

    // evaluate by a given x
    double evaluate(double x){
      double result;
      for(int i=0 ; i<=_degree ; i++){
        result += this->getTermByExponent(i).evaluate(x);
      }
      return result;
    }

private:
    // please add member data if needed
    int _degree;
    Term *_terms;
};
#endif
