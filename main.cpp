#include <iostream>
#include <cstddef>
void destroy(int ** mtx, size_t created)
{
  if (mtx == nullptr) {
    return;
  }
  else {
  for (size_t i = 0; i < created; i++)
  {
    delete[] mtx[i];
  }
  delete[] mtx;
}
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
void input(int ** mtx, size_t rows, size_t cols)
{
  for (size_t i = 0; i < rows; i++) 
  {
    for (size_t j = 0; j < cols; j++)
    {
        std::cin >> mtx[i][j];
    }
  }
}
void output(int ** mtx, size_t rows, size_t cols)
{
    for (size_t i = 0; i < rows; i++)
    {
        std::cout << mtx[i][0];
        for (size_t j = 1; j < cols; j++)
        {
            std::cout << ' ' << mtx[i][j];
        }
        std::cout << "\n";
    }
}
int ** convert(const int * t, size_t n, const size_t * lns, size_t rows)
{
  if (t == nullptr || lns == nullptr)
  {
    return nullptr;
  }
  size_t elements = 0;
  for (size_t i = 0; i < rows; i++)
  {
    elements += lns[i];
  }
  if (elements != n)
  {
    return nullptr;
  }
  int ** mtx = new int * [rows];
  size_t number_index = 0;
  size_t created = 0;
  try
  {
  for (size_t i = 0; i < rows; i++)
  {
    mtx[i] = new int [lns[i]];
    for (size_t j = 0; j < lns[i]; j++)
    {
      mtx[i][j] = t[number_index];
      number_index++;
    }
    created++;
  }
}
catch (const std::bad_alloc &e)
{
  destroy(mtx, created);
  throw;
}
return mtx;
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
  std::cout << "created!" << "\n";
  construct(matrix, 0, 5, 5);
  std::cout << matrix[0][0];
  input(matrix, r, c);
  if (!std::cin)
  {
    destroy(matrix, r);
    std::cerr << "Input error\n";
    return 1;
  }
  output(matrix, r, c);
  destroy(matrix, r);
}