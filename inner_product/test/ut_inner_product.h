#include "../src/dot.h"
#include "../src/math_vector.h"

TEST(InnerProduct, First) {
  double a[2] = {1, 1};
  double b[2] = {2, 3};
  ASSERT_EQ(5,dot(a, 2, b, 2));
}

TEST(InnerProduct, Exception) {
  double a[3] = {1, 1, 1};
  double b[2] = {2, 3};
  try {
    dot(a, 3, b, 2);
    FAIL() << "should'nt be here";
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

TEST(InnerProduct, dot_on_MathVector){
  double u[] = {1, 2};
  double v[] = {3, 4};
  MathVector a(u, 2);
  MathVector b(v, 2);
  ASSERT_EQ(2, a.dimension());

  double result = dot(a, b);
  ASSERT_EQ(11, result);
  ASSERT_EQ(1, a.component(1));
}

TEST(InnerProduct, dot_on_MathVector_dot){
  double u[] = {1, 2};
  double v[] = {3, 4};
  MathVector a(u, 2);
  MathVector b(v, 2);
  ASSERT_EQ(2, a.dimension());

  double result = a.dot(b);
  ASSERT_EQ(11, result);
  ASSERT_EQ(1, a.component(1));
}

TEST(InnerProduct, add){
  double u[] = {1, 2};
  double v[] = {3, 4};
  MathVector a(u, 2);
  MathVector b(v, 2);
  ASSERT_EQ(4, a.add(b).component(1));
  //ASSERT_EQ(6, a.add(b).component(2));
}

TEST(InnerProduct, copyConstructor){
  double u[] = {1, 2};

  MathVector a(u, 2);
  MathVector b = a;   // copy constructor
  ASSERT_EQ(1, b.component(1));
  ASSERT_EQ(2, b.component(2));

}
TEST(InnerProduct, object_assignment){
  double u[] = {1, 2};
  MathVector a(u, 2);
  {
    double v[] = {3, 4};
    MathVector b(v, 2);
    a = b;    // copy assignment
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
  a = b =c;    // copy assignment

  ASSERT_EQ(5, a.component(1));
  ASSERT_EQ(6, a.component(2));
}

TEST(InnerProduct, AreaWith){
  double a[] = {1, 0};
  double b[] = {4, 0};
  double c[] = {4, 4};
  MathVector u(a, 2);
  MathVector v(b, 2);
  MathVector w(c, 2);

  ASSERT_EQ(6, u.areaWith(v, w));
}
