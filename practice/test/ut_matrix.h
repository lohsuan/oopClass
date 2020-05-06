#include "../src/math_matrix.h"
#include "../src/math_vector.h"

TEST(Matrix, construct){
  double a[2][3] = {{1, 2, 3}, {4, 5, 6}};
  MathMatrix A((double *)a, 2, 3);
  ASSERT_EQ(2, A.component(1, 2));
  ASSERT_EQ(6, A.component(2, 3));

}
