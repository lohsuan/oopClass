#include <gtest/gtest.h>


// #include "./ut_matrix.h"
#include "./ut_inner_product.h"
#include "./ut_convex_polygon.h"

int main(int argc, char * argv[]) {
  testing::InitGoogleTest( &argc, argv);
  return RUN_ALL_TESTS();
}
