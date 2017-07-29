#include "sudoku.h"

#include <cassert>
#include <iostream>

void test()
{
  //sudoko contructor arguments
  {
    try
    {
      const sudoku s = {1, 2, 3};
      assert(!"Should not get here");
    }
    catch (std::invalid_argument& e)
    {
      //OK
    }
  }
  //sudoko contructor arguments: -1 should be detected
  {
    try
    {
      const sudoku s = create_bad_sudoku_1();
      assert(!"Should not get here");
    }
    catch (std::invalid_argument& e)
    {
      //OK
    }
  }
  //sudoko contructor arguments: same values in row should be detected
  {
    try
    {
      const sudoku s = create_bad_sudoku_2();
      assert(!"Should not get here");
    }
    catch (std::invalid_argument& e)
    {
      //OK
    }
  }
  //sudoko contructor arguments: same values in column should be detected
  {
    try
    {
      const sudoku s = create_bad_sudoku_3();
      assert(!"Should not get here");
    }
    catch (std::invalid_argument& e)
    {
      //OK
    }
  }
  {
    const sudoku s = create_sudoku_1();
  }
}

int main()
{
  test();
}
