#include "../src/polynomial.h"
#include "../src/term.h"
#include <cmath>

TEST(Polynomial, construct_and_getFuntion){
  Term t1(-7, 0);
  Term t2(6, 1);
  Term t3(0, 2);
  Term t4(1, 3);
  Term t[] = {t1, t2, t3, t4};
  Polynomial p(t, 3);
  ASSERT_NEAR(-7, p.getTermByExponent(0).getCoefficient(), 0.001);
  ASSERT_NEAR(6, p.getTermByExponent(1).getCoefficient(), 0.001);
  ASSERT_NEAR(0, p.getTermByExponent(2).getCoefficient(), 0.001);
  ASSERT_NEAR(1, p.getTermByExponent(3).getCoefficient(), 0.001);
  ASSERT_EQ(3, p.getDegree());
}
TEST(Polynomial, copy_construct){
  Term t1(-7, 0);
  Term t2(6, 1);
  Term t3(0, 2);
  Term t4(1, 3);
  Term t[] = {t1, t2, t3, t4};
  Polynomial p1(t, 3);
  Polynomial p2 = p1;
  ASSERT_NEAR(-7, p2.getTermByExponent(0).getCoefficient(), 0.001);
  ASSERT_NEAR(6, p2.getTermByExponent(1).getCoefficient(), 0.001);
  ASSERT_NEAR(0, p2.getTermByExponent(2).getCoefficient(), 0.001);
  ASSERT_NEAR(1, p2.getTermByExponent(3).getCoefficient(), 0.001); //
  ASSERT_EQ(3, p2.getDegree());
}
TEST(Polynomial, eq){
  Term t1(-7, 0);
  Term t2(6, 1);
  Term t3(0, 2);
  Term t4(1, 3);
  Term t5(4, 5);
  Term t[] = {t1, t2};
  Term tt[] = {t3, t4};
  Term ttt[] = {t5};
  Polynomial p1(t, 1);
  Polynomial p2(tt, 3);
  Polynomial p3(ttt, 5);
  p1 = p2 = p3;
  ASSERT_EQ(4, p1.getTermByExponent(0).getCoefficient());
  ASSERT_EQ(4, p2.getTermByExponent(0).getCoefficient());
  ASSERT_EQ(4, p3.getTermByExponent(0).getCoefficient());
  ASSERT_EQ(5, p1.getDegree());
  ASSERT_EQ(5, p2.getDegree());
  ASSERT_EQ(5, p3.getDegree());
}
TEST(Polynomial, add){
  Term t1(7, 0);
  Term t2(6, 1);
  Term t3(0, 0);
  Term t4(2, 1);
  Term t5(4, 2);
  Term t[] = {t1, t2};
  Term tt[] = {t3, t4, t5};
  Polynomial p1(t, 1);    // 7 + 6x
  Polynomial p2(tt, 2);   // 0  + 2x + 4x^2
  Polynomial p = p1 + p2;   // 7 + 8x + 4x^2
  ASSERT_NEAR(7, p.getTermByExponent(0).getCoefficient(), 0.001);
  ASSERT_NEAR(8, p.getTermByExponent(1).getCoefficient(), 0.001);
  ASSERT_NEAR(4, p.getTermByExponent(2).getCoefficient(), 0.001);
  ASSERT_EQ(2, p.getDegree());
}
TEST(Polynomial, poly_evaluate){
  Term t1(-7, 0);
  Term t2(6, 1);
  Term t3(0, 2);
  Term t4(1, 3);
  Term t[] = {t1, t2, t3, t4};
  Polynomial p(t, 3);
  double result = p.evaluate(4.8);
  ASSERT_NEAR(-7 + 4.8*6 + pow(4.8, 3), result, 0.001);
}
