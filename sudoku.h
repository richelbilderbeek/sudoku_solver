#ifndef SUDOKU_H
#define SUDOKU_H

#include <initializer_list>
#include <vector>

//y-x-ordered, zero denotes 'unknown'
using sudoku_grid = std::vector<std::vector<int>>;

class sudoku
{
public:
  sudoku(const std::initializer_list<int>& values);
private:

  //y-x-ordered, zero denotes 'unknown'
  sudoku_grid m_grid;
};

///Will throw: has -1 value
sudoku create_bad_sudoku_1();

///Has same in value in row
sudoku create_bad_sudoku_2();

///Has same in value in column
sudoku create_bad_sudoku_3();

///Has same in value in square
sudoku create_bad_sudoku_4();

sudoku create_sudoku_1();
sudoku create_test_sudoku_2();

bool has_valid_blocks(const sudoku_grid& g);
bool has_valid_cols(const sudoku_grid& g);
bool has_valid_rows(const sudoku_grid& g);
bool has_valid_values(const sudoku_grid& g);


bool is_valid(const sudoku_grid& g);

sudoku solve_sudoku(const sudoku& m);

sudoku_grid transpose(const sudoku_grid& g);

#endif // SUDOKU_H
