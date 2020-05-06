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
TEST(InnerProduct, dot_on_MathVector_dot){
  double a[] = {1, 2};
  double b[] = {3, 4};
  MathVector v(a, 2);
  MathVector u(b, 2);

  double result = v.dot(u);
  ASSERT_EQ(11, result);
  ASSERT_EQ(1, v.component(1));
}
TEST(InnerProduct, copyConstructor){
  double v[] = {1, 2};
  MathVector a(v, 2);
  MathVector b = a;  // call copy constructor

  ASSERT_EQ(1, b.component(1));
  ASSERT_EQ(2, b.component(2));
}
TEST(InnerProduct, add){
  double v[] = {1, 2};
  double u[] = {3, 4};
  MathVector a(v, 2);
  MathVector b(u, 2);
  ASSERT_EQ(4, a.add(b).component(1));
  ASSERT_EQ(6, a.add(b).component(2));
}
TEST(InnerProduct, object_assignment){
  double v[] = {1, 2};
  MathVector a(v, 2);
  {
    double u[] = {3, 4};
    MathVector b(u, 2);
    a = b;    //c++ :shallow copy => write deep copy assignment
    /* when we use heap memory we need to write
      copy constructor & copy assignment to avoid dangling */
  }
  ASSERT_EQ(3, a.component(1));
  ASSERT_EQ(4, a.component(2));
}
TEST(InnerProduct, object_assignment2){
  double u[] = {1, 2};
  MathVector a(u, 2);

  double v[] = {3, 4};
  MathVector b(v, 2);
  double w[] = {5, 6};
  MathVector c(w, 2);
  a = b = c;    // copy assignment

  ASSERT_EQ(5, a.component(1));
  ASSERT_EQ(6, a.component(2));
}
