#include "Matrix.hpp"
#include "Matrix_test_helpers.hpp"
#include "unit_test_framework.hpp"

using namespace std;

// Here's a free test for you! Model yours after this one.
// Test functions have no interface and thus no RMEs, but
// add a comment like the one here to say what it is testing.
// -----
// Fills a 3x5 Matrix with a value and checks
// that Matrix_at returns that value for each element.
TEST(test_fill_basic) {
  Matrix mat;
  const int width = 3;
  const int height = 5;
  const int value = 42;
  Matrix_init(&mat, 3, 5);
  Matrix_fill(&mat, value);

  for(int r = 0; r < height; ++r){
    for(int c = 0; c < width; ++c){
      ASSERT_EQUAL(*Matrix_at(&mat, r, c), value);
    }
  }
}

// ADD YOUR TESTS HERE
// You are encouraged to use any functions from Matrix_test_helpers.hpp as needed.
// Tests 
TEST(test_matrix_init_basic) {
  Matrix mat; 
  const int width = 4; 
  const int height = 2;
  Matrix_init(&mat, width, height);
  ASSERT_EQUAL(Matrix_width(&mat), width);
  ASSERT_EQUAL(Matrix_height(&mat), height);

  for (int row = 0; row < height; row++) {
    for (int col = 0; col < width; col++) {
      ASSERT_EQUAL(*Matrix_at(&mat, row, col), 0); 
    }
  }
}
// add comment
TEST(test_matrix_init_single_row) {
  Matrix mat;
  const int width = 5;
  const int height = 1;
  Matrix_init(&mat, width, height);
  ASSERT_EQUAL(Matrix_width(&mat), width);
  ASSERT_EQUAL(Matrix_height(&mat), height);

  for (int row = 0; row < height; row++) {
    for (int col = 0; col < width; col++) {
      ASSERT_EQUAL(*Matrix_at(&mat, 0, col), 0); 
    }
  }
}

TEST(test_matrix_init_single_col) {
  Matrix mat;
  const int width = 1;
  const int height = 3;
  Matrix_init(&mat, width, height);
  ASSERT_EQUAL(Matrix_width(&mat), width);
  ASSERT_EQUAL(Matrix_height(&mat), height);

  for (int row = 0; row < height; row++) {
    for (int col = 0; col < width; col++) {
      ASSERT_EQUAL(*Matrix_at(&mat, row, 0), 0); 
    }
  }
}

TEST(test_matrix_print) {

  Matrix mat; 
  Matrix_init(&mat, 2, 2);
  *Matrix_at(&mat, 0, 0) = 1;
  *Matrix_at(&mat, 0, 1) = 2;
  *Matrix_at(&mat, 1, 0) = 3;
  *Matrix_at(&mat, 1, 1) = 4;

  ostringstream Theoritical_output;
  Matrix_print(&mat, Theoritical_output);
  ASSERT_EQUAL(Theoritical_output.str(), "2 2\n1 2 \n3 4 \n");
}

TEST(test_matrix_width) {
 Matrix mat;
 Matrix_init(&mat, 6, 7);
 ASSERT_EQUAL(Matrix_width(&mat), 6);
}

TEST(test_matrix_height) {
 Matrix mat;
 Matrix_init(&mat, 6, 7);
 ASSERT_EQUAL(Matrix_height(&mat), 7);
}

TEST(test_matrix_at) {
  Matrix mat;
  Matrix_init(&mat, 6, 7);
  *Matrix_at(&mat, 6, 5) = 9;

  ASSERT_EQUAL(*Matrix_at(&mat, 6, 5), 9);
  ASSERT_EQUAL(*Matrix_at(&mat, 5, 4), 0);
  ASSERT_EQUAL(*Matrix_at(&mat, 0, 0), 0);
}

TEST(test_fill_border) {
  Matrix mat;
  const int w = 4;
  const int h = 4;
  Matrix_init(&mat, w, h);
  Matrix_fill_border(&mat, 1);

 for (int row = 0; row < h; ++row) {
    for (int col = 0; col < w; ++col) {
      if (row == 0) {
        ASSERT_EQUAL(*Matrix_at(&mat, row, col),1);
      } else if (row == h - 1) {
        ASSERT_EQUAL(*Matrix_at(&mat, row, col), 1);
      } else if (col == 0) {
        ASSERT_EQUAL(*Matrix_at(&mat, row, col), 1);
      } else if (col == w - 1) {
        ASSERT_EQUAL(*Matrix_at(&mat, row, col),1);
      } else {
        ASSERT_EQUAL(*Matrix_at(&mat, row, col), 0);
      }
    }
  }
}

TEST(test_matrix_unusal_shape) {
  Matrix mat; 
  Matrix_init(&mat, 3, 2);
  *Matrix_at(&mat, 0, 1) = 88;
  *Matrix_at(&mat, 1, 0) = 2;
  ostringstream cliprint;
  Matrix_print(&mat, cliprint);
  ASSERT_EQUAL(cliprint.str(), "3 2\n0 0 88 0 \n2 0 0 \n");
}

TEST(test_matrix_max) {
  Matrix mat;
  Matrix_init(&mat, 2, 2);
  Matrix_fill(&mat, -5);
  *Matrix_at(&mat, 1, 1) = -1;
  ASSERT_EQUAL(Matrix_max(&mat), -1);
}

TEST_MAIN()

