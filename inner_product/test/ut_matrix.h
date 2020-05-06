#ifndef UT_MATRIX_H
#define UT_MATRIX_H
#include "../src/matrix.h"

class MatrixTest : public ::testing::Test { // "test fixture"
protected: // test data
    void SetUp() override {
      // a
      a[0] = r1;
      a[1] = r2;
      // b
      b[0] = b_r1;
      b[1] = b_r2;
      b[2] = b_r3;
    }
    // a
    int row = 2;
    int col = 3;
    double r1[3] = {1, 2, 3}; // length of the array must be given
    double r2[3] = {4, 5, 6};
    double *a[2];
    // b
    int b_row = 3;
    int b_col = 2;
    double b_r1[2] = {7, 8};
    double b_r2[2] = {9, 10};
    double b_r3[2] = {11, 12};
    double *b[3];
};

TEST_F(MatrixTest, Representation) {
  Matrix m(a, row, col);
  ASSERT_EQ(1, m.at(1, 1));
  ASSERT_EQ(2, m.at(1, 2));
  ASSERT_EQ(3, m.at(1, 3));
  ASSERT_EQ(4, m.at(2, 1));
  ASSERT_EQ(5, m.at(2, 2));
  ASSERT_EQ(6, m.at(2, 3));
  {
    Matrix p = m;
    ASSERT_EQ(1, p.at(1, 1));
  }
  ASSERT_EQ(1, m.at(1, 1));
  ASSERT_EQ(2, m.at(1, 2));
  ASSERT_EQ(3, m.at(1, 3));
  ASSERT_EQ(4, m.at(2, 1));
  ASSERT_EQ(5, m.at(2, 2));
  ASSERT_EQ(6, m.at(2, 3));

  MathVector v = m.row(1);
  ASSERT_EQ(1, v.component(1));
  ASSERT_EQ(2, v.component(2));
  ASSERT_EQ(3, v.component(3));

}

TEST_F(MatrixTest, ThreeByTwo) {
  Matrix m(b, b_row, b_col);
  ASSERT_EQ(9, m.at(2, 1));
  ASSERT_EQ(12, m.at(3, 2));
}

TEST_F(MatrixTest, GetColumn) {
  Matrix m(b, b_row, b_col);
  ASSERT_EQ(8, m.column(2).component(1));
  ASSERT_EQ(10, m.column(2).component(2));
  ASSERT_EQ(12, m.column(2).component(3));
}

TEST_F(MatrixTest, Multiplication) {
  Matrix m(a, 2, 3);
  Matrix n(b, 3, 2);
  Matrix result = m*n;
  ASSERT_EQ(58, result.at(1, 1));
  ASSERT_EQ(64, result.at(1, 2));
  ASSERT_EQ(139, result.at(2, 1));
  ASSERT_EQ(154, result.at(2, 2));
}


#endif
