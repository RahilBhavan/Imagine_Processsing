#include "Matrix.hpp"
#include "Image_test_helpers.hpp"
#include "unit_test_framework.hpp"
#include <iostream>
#include <string>
#include <sstream>
#include <cassert>

using namespace std;

// Here's a free test for you! Model yours after this one.
// Test functions have no interface and thus no RMEs, but
// add a comment like the one here to say what it is testing.
// -----
// Sets various pixels in a 2x2 Image and checks
// that Image_print produces the correct output.
TEST(test_print_basic) {
  Image img;
  const Pixel red = {255, 0, 0};
  const Pixel green = {0, 255, 0};
  const Pixel blue = {0, 0, 255};
  const Pixel white = {255, 255, 255};

  Image_init(&img, 2, 2);
  Image_set_pixel(&img, 0, 0, red);
  Image_set_pixel(&img, 0, 1, green);
  Image_set_pixel(&img, 1, 0, blue);
  Image_set_pixel(&img, 1, 1, white);

  // Capture our output
  ostringstream s;
  Image_print(&img, s);

  // Correct output
  ostringstream correct;
  correct << "P3\n2 2\n255\n";
  correct << "255 0 0 0 255 0 \n";
  correct << "0 0 255 255 255 255 \n";
  ASSERT_EQUAL(s.str(), correct.str());
}

// IMPLEMENT YOUR TEST FUNCTIONS HERE
TEST(test_init_dimensions) {
  Image test_image;
  Image_init(&test_image, 6, 7);
  ASSERT_EQUAL(Image_width(&test_image), 6);
  ASSERT_EQUAL(Image_height(&test_image), 7);
}

TEST(test_setpixel) {
  Image test_image;
  Image_init(&test_image, 2, 2);
  
  Pixel p = {2, 5, 10};
  Image_set_pixel(&test_image, 0, 1, p);

  Pixel test = Image_get_pixel(&test_image, 0, 1);
  ASSERT_EQUAL(test.r, 2);
  ASSERT_EQUAL(test.g, 5);
  ASSERT_EQUAL(test.b, 10);
}

TEST(test_getpixel) {
  Image test_image;
    istringstream picture("P3\n1 1\n255\n10 5 1 \n");
  Image_init(&test_image, picture);

  Pixel test = Image_get_pixel(&test_image, 0, 0);
  ASSERT_EQUAL(test.r, 10);
  ASSERT_EQUAL(test.g, 5);
  ASSERT_EQUAL(test.b, 1);
}

TEST(test_fill_simple) {
  Image test_image;
  Image_init(&test_image, 2, 2);
  Pixel colour = {2, 5, 7};
  Image_fill(&test_image, colour);

  Pixel test = Image_get_pixel(&test_image, 1, 1);
  ASSERT_EQUAL(test.r, 2);
  ASSERT_EQUAL(test.g, 5);
  ASSERT_EQUAL(test.b, 7);
}

TEST(test_all_black) {
  Image test_image;
  Image_init(&test_image, 3, 2);
  for (int row = 0; row < 2; ++row) {
    for (int col = 0; col < 3; ++col) {
      Pixel test = Image_get_pixel(&test_image, row, col);
      ASSERT_EQUAL(test.r, 0);
      ASSERT_EQUAL(test.g, 0);
      ASSERT_EQUAL(test.b, 0);
    }
  }  
}

TEST(test_set_pixel_unusal_shape) {
  Image img;
  Image_init(&img, 3, 2);
  Pixel p = {10, 4, 9};
  Image_set_pixel(&img, 1, 2, p);

  Pixel test = Image_get_pixel(&img, 1, 2);
  ASSERT_EQUAL(test.r, 10);
  ASSERT_EQUAL(test.g, 4);
  ASSERT_EQUAL(test.b, 9);
}

TEST_MAIN() // Do NOT put a semicolon here

