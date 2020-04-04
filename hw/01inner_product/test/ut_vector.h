#include "../src/math_vector.h"
#include "../src/dot.h"
#include <cmath>

TEST(InnerProduct, Dot1) {
  // This tset is named Dot1, and belongs to "InnerProduct"
  double u[] = {1, 0, 2};
  double v[] = {1, 1, 3};

  ASSERT_EQ(7, dot(u, 3, v, 3)); // (expet, test)
}

TEST(InnerProduct, Exception) {
  double a[3] = {1, 1, 1};
  double b[2] = {2, 3};
  try {
    dot(a, 3, b, 2);
    FAIL() << "shouldn't be here";
  }
  catch(std::string message) {
    ASSERT_EQ(std::string("undefined"), message);
  }
}

TEST(InnerProduct, MathVector) {
  double a[] = {5, 7};
  MathVector v(a, 2);
  ASSERT_EQ(5, v.component(1));
  ASSERT_EQ(7, v.component(2));
}

TEST(InnerProduct, Zero) {
  double a[] = {0, 0, 0};
  double b[] = {0, 1};
  MathVector v(a, 3);
  MathVector u(b, 2);
  ASSERT_EQ(true, v.isZero());
  ASSERT_EQ(false, u.isZero());
}
TEST(InnerProduct, Lenth) {
  double a[] = {1, 2, 3};
  double b[] = {3, 4};
  MathVector v(a, 3);
  MathVector u(b, 2);
  ASSERT_NEAR(pow(14, 0.5), v.length(), 0.001);
  ASSERT_NEAR(5, u.length(), 0.001);
}

TEST(InnerProduct, Dimension) {
  double a[] = {1, 2, 3};
  double b[] = {3, 4};
  MathVector v(a, 3);
  MathVector u(b, 2);
  ASSERT_EQ(3, v.getDim());
  ASSERT_EQ(2, u.getDim());
}
TEST(InnerProduct, dot_on_MathVector){
  double a[] = {1, 2};
  double b[] = {3, 4};
  MathVector v(a, 2);
  MathVector u(b, 2);

  double result = dot(v, u);
  ASSERT_EQ(11, result);
  ASSERT_EQ(1, v.component(1));
}
