#include "../src/term.h"
#include <cmath>
TEST(Term, getFunction){
  Term t(1.5, 2);
  ASSERT_NEAR(1.5, t.getCoefficient(), 0.001);
  ASSERT_EQ(2, t.getExponent());
}
TEST(Term, default){
  Term t;
  ASSERT_NEAR(0, t.getCoefficient(), 0.001);
  ASSERT_EQ(0, t.getExponent());
}
TEST(Term, construct){
  Term t(1.5, 3);
  ASSERT_NEAR(1.5, t.getCoefficient(), 0.001);
  ASSERT_EQ(3, t.getExponent());
}
TEST(Term, eq_operator){
  Term t1(1.5, 3);
  Term t2(2.4, 5);
  t1 = t2;
  ASSERT_NEAR(2.4, t1.getCoefficient(), 0.001);
  ASSERT_EQ(5, t1.getExponent());
  Term t3(3.5, 6);
  t1 = t2 = t3;
  ASSERT_NEAR(3.5, t1.getCoefficient(), 0.001);
  ASSERT_EQ(6, t1.getExponent());
}
TEST(Term, add_op){
  Term t1(1.5, 3);
  Term t2(2.8, 3);
  Term t = t1 + t2;
  ASSERT_NEAR(4.3, t.getCoefficient(), 0.001);
  ASSERT_EQ(3, t.getExponent());
}
TEST(Term, add_Exception){
  Term t1(1.5, 3);
  Term t2(2.4, 2);
  ASSERT_ANY_THROW(t1+t2);
}
TEST(Term, mul_op){
  Term t1(1.5, 3);
  Term t2(2.4, 2);
  Term t = t1 * t2;
  ASSERT_NEAR(1.5*2.4, t.getCoefficient(), 0.001);
  ASSERT_EQ(3+2, t.getExponent());
}

TEST(Term, eqeq_op){
  Term t1(1.5, 3);
  Term t2(2.8, 3);
  Term t3(2.8, 3);
  ASSERT_EQ(false, t1 == t2);
  ASSERT_EQ(true, t2 == t3);
}
TEST(Term, evaluate){
  Term t1(1.5, 3);
  ASSERT_EQ(1.5 * pow(2.5, 3), t1.evaluate(2.5));
}
