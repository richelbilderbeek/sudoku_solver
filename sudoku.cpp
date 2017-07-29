#include "sudoku.h"

#include <algorithm>
#include <stdexcept>

sudoku::sudoku(const std::initializer_list<int>& values)
  : m_grid(9, std::vector<int>(9, 0))
{
  if (values.size() != 81)
    throw std::invalid_argument("sudoku must be supplied 81 values");

  //Initialize grid
  {
    auto i = values.begin();
    for (int y = 0; y != 9; ++y)
    {
      for (int x = 0; x != 9; ++x)
      {
        m_grid[y][x] = *i;
        ++i;
      }
    }
  }

  if (!is_valid(m_grid))
    throw std::invalid_argument("invalid sudoku values supplied");
}

sudoku create_bad_sudoku_1()
{
  return {
    4, 0, 8, 0, 9, 0, 5, 0, 6,
    7, 9, 1, 6, 0, 2, 0, 0, 0,
    0, 0, 0, 8, 1, 0, 9, 7, 2,
    0, 1, 5, 0, 8, 3, 2, 0, 0,
    0, 4, 7, 0, 6, 0, 0, 3, 5,
    6, 0, 0, 0, 2, 5, 4, 9, 0,
    5, 7, 2, 9, 0, 0, 6, 0, 3,
    0, 0, 0, 2, 0, 6, 0, 5, 9,
    1, 6, 0, 5, 0, 8, 0, 2, -1 //-1 is invalid
  };
}

sudoku create_bad_sudoku_2()
{
  return {
    0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0,
    1, 0, 0, 0, 0, 0, 0, 0, 1,
    0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0
  };
}

sudoku create_bad_sudoku_3()
{
  return {
    0, 0, 0, 0, 8, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 8, 0, 0, 0, 0
  };
}

sudoku create_bad_sudoku_4()
{
  return {
    0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 5, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 5
  };
}


sudoku create_sudoku_1()
{
  return {
    4, 0, 8, 0, 9, 0, 5, 0, 6,
    7, 9, 1, 6, 0, 2, 0, 0, 0,
    0, 0, 0, 8, 1, 0, 9, 7, 2,
    0, 1, 5, 0, 8, 3, 2, 0, 0,
    0, 4, 7, 0, 6, 0, 0, 3, 5,
    6, 0, 0, 0, 2, 5, 4, 9, 0,
    5, 7, 2, 9, 0, 0, 6, 0, 3,
    0, 0, 0, 2, 0, 6, 0, 5, 9,
    1, 6, 0, 5, 0, 8, 0, 2, 0
  };
}

bool has_valid_cols(const sudoku_grid& g)
{
  const auto h = transpose(g);
  for (const auto& row: g)
  {
    for (int i = 1; i!=10; ++i)
    {
      if (std::count(std::begin(row), std::end(row), i) > 1)
        return false;
    }
  }
  return true;
}

bool has_valid_rows(const sudoku_grid& g)
{
  for (const auto& row: g)
  {
    for (int i = 1; i!=10; ++i)
    {
      if (std::count(std::begin(row), std::end(row), i) > 1)
        return false;
    }
  }
  return true;
}

bool has_valid_values(const sudoku_grid& g)
{
  //Check for invalid values
  for (const auto& row: g)
  {
    for (const auto& i: row)
    {
      if (i < 0 || i > 9) return false;
    }
  }
  return true;
}

bool is_valid(const sudoku_grid& g)
{
  if (!has_valid_values(g)) return false;
  if (!has_valid_rows(g)) return false;
  if (!has_valid_cols(g)) return false;
  return true;
}

sudoku_grid transpose(const sudoku_grid& g)
{
  //stub
  return g;
}
