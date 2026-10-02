#include "Matrix.hpp"
#include <cassert>
#include <iostream>
using namespace std;

// REQUIRES: mat points to a Matrix
//           0 < width && 0 < height
// MODIFIES: *mat
// EFFECTS:  Initializes *mat as a Matrix with the given width and height,
//           with all elements initialized to 0.
void Matrix_init(Matrix *mat, int width, int height) {
  mat->width = width;
  mat->height = height;
  mat->data = vector<int>(width * height, 0);
}

// REQUIRES: mat points to a valid Matrix
// MODIFIES: os
// EFFECTS:  First, prints the width and height for the Matrix to os:
//             WIDTH [space] HEIGHT [newline]
//           Then prints the rows of the Matrix to os with one row per line.
//           Each element is followed by a space and each row is followed
//           by a newline. This means there will be an "extra" space at
//           the end of each line.
void Matrix_print(const Matrix *mat, std::ostream &os) {
  os << mat->width << " " << mat->height << endl;
  for (int row = 0; row < mat->height; row++) {
    for (int col = 0; col < mat->width; col++) {
      int index = row * mat->width + col;
      os << mat->data[index] << " ";
    }
    os << endl;
  }
}

// REQUIRES: mat points to a valid Matrix
// EFFECTS:  Returns the width of the Matrix.
int Matrix_width(const Matrix *mat) { return mat->width; }

// REQUIRES: mat points to a valid Matrix
// EFFECTS:  Returns the height of the Matrix.
int Matrix_height(const Matrix *mat) {
  return mat->height; // TODO Replace with your implementation!
}

// REQUIRES: mat points to a valid Matrix
//           0 <= row && row < Matrix_height(mat)
//           0 <= column && column < Matrix_width(mat)
//
// MODIFIES: (The returned pointer may be used to modify an
//            element in the Matrix.)
// EFFECTS:  Returns a pointer to the element in the Matrix
//           at the given row and column.
int *Matrix_at(Matrix *mat, int row, int column) {
  return &mat->data[(row * mat->width) + column]; // The formula for finding the 2D index is row *
                             // width + column, as there is no 2D index, they
                             // are stored in a flat array, so you have to find
                             // the space its stored.
}

// REQUIRES: mat points to a valid Matrix
//           0 <= row && row < Matrix_height(mat)
//           0 <= column && column < Matrix_width(mat)
//
// EFFECTS:  Returns a pointer-to-const to the element in
//           the Matrix at the given row and column.
const int *Matrix_at(const Matrix *mat, int row, int column) {
  return &mat->data[(row * mat->width) + column];
}

// REQUIRES: mat points to a valid Matrix
// MODIFIES: *mat
// EFFECTS:  Sets each element of the Matrix to the given value.
void Matrix_fill(Matrix *mat, int value) {
  for (int &x : mat->data) {
    x = value;
  }
}

// REQUIRES: mat points to a valid Matrix
// MODIFIES: *mat
// EFFECTS:  Sets each element on the border of the Matrix to
//           the given value. These are all elements in the first/last
//           row or the first/last column.
void Matrix_fill_border(Matrix *mat, int value) {
  int w = Matrix_width(mat); // initalizing w to width so we dont have to do it multiple times
  int h = Matrix_height(mat); // initalizing h to hieght so we dont have to do it multiple times.

  for (int counter = 0; counter < w; ++counter) {
    *Matrix_at(mat, 0, counter) = value; // Replaces all the horzontal borders
    *Matrix_at(mat, h-1, counter) = value;
  }

  for (int counter = 0; counter < h; ++counter) {
    *Matrix_at(mat, counter, 0) = value; // Replaces all the vertical borders
    *Matrix_at(mat, counter, w-1) = value;
  }
}

// REQUIRES: mat points to a valid Matrix
// EFFECTS:  Returns the value of the maximum element in the Matrix
int Matrix_max(const Matrix *mat) {
  int w = Matrix_width(mat);
  int h = Matrix_height(mat);
  int max = *Matrix_at(mat, 0, 0);

  for (int counter_row = 0; counter_row < h; ++counter_row) {
    for (int counter_width = 0; counter_width < w; ++counter_width) {
      if (*Matrix_at(mat, counter_row, counter_width) > max) {
        max = *Matrix_at(mat, counter_row, counter_width);
      }
    }
  }
  return max;
}

// REQUIRES: mat points to a valid Matrix
//           0 <= row && row < Matrix_height(mat)
//           0 <= column_start && column_end <= Matrix_width(mat)
//           column_start < column_end
// EFFECTS:  Returns the column of the element with the minimal value
//           in a particular region. The regi:on is defined as elements
//           in the given row and between column_start (inclusive) and
//           column_end (exclusive).
//           If multiple elements are minimal, returns the column of
//           the leftmost one.
int Matrix_column_of_min_value_in_row(const Matrix *mat, int row,
                                      int column_start, int column_end) {
  int min_value = column_start;

  for (int counter = column_start + 1; counter < column_end; ++counter) {
    if (*Matrix_at(mat, row, min_value) > *Matrix_at(mat, row, counter))
      min_value = counter;
  }

  return min_value;
}

// REQUIRES: mat points to a valid Matrix
//           0 <= row && row < Matrix_height(mat)
//           0 <= column_start && column_end <= Matrix_width(mat)
//           column_start < column_end
// EFFECTS:  Returns the minimal value in a particular region. The region
//           is defined as elements in the given row and between
//           column_start (inclusive) and column_end (exclusive).
int Matrix_min_value_in_row(const Matrix *mat, int row, int column_start,
                            int column_end) {
  int min_column =
      Matrix_column_of_min_value_in_row(mat, row, column_start, column_end);

  return *Matrix_at(mat, row, min_column);
}
