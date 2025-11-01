#include <iostream>
#include <cstddef>
void destroy(int ** mtx, size_t created)
{
  for (size_t i = 0; i < created; i++)
  {
    delete[] mtx[i];
  }
  delete[] mtx;
}
int ** create(size_t rows, size_t cols)
{
  int ** mtx = new int * [rows];
  size_t created = 0;
  try
  {
  for (; created < rows; created++)
  {
    mtx[created] = new int[cols];
  }
}
  catch (const std::bad_alloc &e)
  {
    destroy(mtx, created);
    throw;
  }
  return mtx;
}
void construct(int ** mtx, int init, size_t rows, size_t cols)
{
  for (size_t i = 0; i < rows; i++)
  {
    for (size_t j = 0; j < cols; j++)
    {
        mtx[i][j] = init;
    }
  }
}
int main()
{
  size_t r = 0, c = 0;
  std::cin >> r >> c;
  if (!std::cin)
  {
    std::cerr << "Bad input\n";
    return 2;
  }
  int ** matrix = nullptr;
  try
  {
    matrix = create(5, 5);
  }
  catch (const std::bad_alloc &e)
  {
    std::cerr << e.what() << "\n";
    return 1;
  }
  construct(matrix, 2, 5, 5);
  std::cout << matrix[0][0];
  destroy(matrix, 5);
}