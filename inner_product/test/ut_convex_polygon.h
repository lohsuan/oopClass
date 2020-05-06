#include "../src/math_vector.h"
#include "../src/convex_polygon.h"

#include <algorithm>

class ConvexPolygonTest : public ::testing::Test {
protected:
  void SetUp(){
    double a[] = {1, 0};
    double b[] = {4, 0};
    double c[] = {4, 4};
    double d[] = {1, 4};
    u = MathVector(a, 2);
    v = MathVector(b, 2);
    w = MathVector(c, 2);
    x = MathVector(d, 2);
  }

  MathVector u;
  MathVector v;
  MathVector w;
  MathVector x;
};

TEST_F(ConvexPolygonTest, FixtureCheck) {
  ASSERT_EQ(4, v.component(1));
  ASSERT_EQ(0, v.component(2));
}

TEST_F(ConvexPolygonTest, CreatConvexPolygon) {
  MathVector vertices[4] = {u, v, w, x};
  ConvexPolygon cp(vertices, 4);
  ASSERT_EQ(4, cp.vertex(1).component(1));
  ASSERT_EQ(0, cp.vertex(1).component(2));
}

TEST_F(ConvexPolygonTest, Perimeter) {
  MathVector vertices[4] = {u, v, w, x};
  ConvexPolygon cp(vertices, 4);
  ASSERT_EQ(14, cp.perimeter());
}

TEST_F(ConvexPolygonTest, Area){
  MathVector vertices[4] = {u, v, w, x};
  ConvexPolygon cp(vertices, 4);
  ASSERT_EQ(12, cp.area());
}

// TEST_F(ConvexPolygonTest, VerticesNotOrdered){
//   MathVector vertices[4] = {u, w, x, v};
//   ConvexPolygon cp(vertices, 4);
//   ASSERT_EQ(14, cp.perimeter());
// }

TEST_F(ConvexPolygonTest, Centroid){
  MathVector vertices[4] = {u, w, x, v};
  MathVector o = centroid(vertices, 4);
  ASSERT_EQ(2.5, o.component(1));
  ASSERT_EQ(2, o.component(2));
}

TEST_F(ConvexPolygonTest, Scale) {
  MathVector v = w.scale(2);
  ASSERT_EQ(8, v.component(1));
  ASSERT_EQ(8, v.component(2));
}

TEST_F(ConvexPolygonTest, Angle) {
  MathVector vertices[4] = {u, w, x, v};
  MathVector o = centroid(vertices, 4);
  MathVector v1 = u-o;
  MathVector v2 = v-o;
  ASSERT_NEAR(74, v1.angleWith(v2), 1.0);
}

template<class T>
class AngleComp{
public:
  AngleComp(T o, T ref){
    _o = o;
    _ref = ref;
  }
  bool operator() (T & a, T & b){
    return _ref.angleWith(a-_o) < _ref.angleWith(b-_o);
  }

private:
  T _o;
  T _ref;
};

TEST_F(ConvexPolygonTest, SortByAngle) {
  MathVector vertices[4] = {u, w, x, v};
  MathVector o = centroid(vertices, 4);
  MathVector ref = vertices[0] - o;
  AngleComp <MathVector> comp(o, ref);
  std::sort(vertices, vertices+4, comp);
  ASSERT_EQ(1, vertices[0].component(1));
  ASSERT_EQ(0, vertices[0].component(2));
  ASSERT_EQ(4, vertices[1].component(1));
  ASSERT_EQ(0, vertices[1].component(2));
  ASSERT_EQ(4, vertices[2].component(1));
  ASSERT_EQ(4, vertices[2].component(2));
  ASSERT_EQ(1, vertices[3].component(1));
  ASSERT_EQ(4, vertices[3].component(2));
}

TEST_F(ConvexPolygonTest, SortAscending) {
  int myints[] = {32,71,12,45,26,80,53,33};
  std::sort(myints+0, myints+8);
  ASSERT_EQ(12, myints[0]);
  ASSERT_EQ(80, myints[7]);
}

template<class T>
bool greaterThan(T & a, T & b) {
  return a>b;
}
TEST_F(ConvexPolygonTest, SortIntDescending) {
  int myints[] = {32,71,12,45,26,80,53,33};
  std::sort(myints+0, myints+8, greaterThan<int>);
  ASSERT_EQ(80, myints[0]);
  ASSERT_EQ(12, myints[7]);
}
TEST_F(ConvexPolygonTest, SortDoubleDescending) {
  double mynums[] = {32.0,71.0,12.0,45.0,26.0,80.0,53.0,33.0};
  std::sort(mynums+0, mynums+8, greaterThan<double>);
  ASSERT_EQ(80, mynums[0]);
  ASSERT_EQ(12, mynums[7]);
}


template<class T>
bool distanceTo26(T & a, T & b) {
  return abs(a-26) < abs(b-26);
}
TEST_F(ConvexPolygonTest, SortAscendingByDistanceTo26) {
  int myints[] = {32,71,12,45,26,80,53,33};
  std::sort(myints+0, myints+8, distanceTo26<int>);
  ASSERT_EQ(26, myints[0]);
  ASSERT_EQ(32, myints[1]);
  ASSERT_EQ(33, myints[2]);
  ASSERT_EQ(12, myints[3]);
}

// 希望不要把26寫死
// 把 comp 當 object call
// class template
template<class T>
class Comparator {
public:
  Comparator(T base) {
    _base = base;
  }
  // () : funtion calling operator
  // 我們對 這個 operator 做 overloading
   // 就像自己寫 copy assignment + - = ... 一樣
  bool operator () (T & a, T & b) {
    return abs(a-_base) < abs(b-_base);
  }

private:
  T _base;
};

TEST_F(ConvexPolygonTest, SortDoubleAscendingByObject) {
  double mynums[] = {32.0,71.0,12.0,45.0,26.0,80.0,53.0,33.0};
  Comparator<double> comp(26);  // Comparator class 生成 comp object
                                // 呼叫 constructor 並傳入參數 26 作為 base
  // we are using comp as a function
  // comp should be a pointer to function
  std::sort(mynums+0, mynums+8, comp);
  // 所以 comp 是 function and object ??
  ASSERT_EQ(26, mynums[0]);
  ASSERT_EQ(32, mynums[1]);
  ASSERT_EQ(33, mynums[2]);
  ASSERT_EQ(12, mynums[3]);
}
