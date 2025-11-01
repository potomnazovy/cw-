#include <iostream>
#include <cstddef>
void free_convert(int ** result, size_t created)
{
  if (result == nullptr)
  {
    return;
  }
  else {
    for (size_t i = 0; i < created; i++)
    {
        delete[] result[i];
    }
  }
  delete[] result;
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
  int ** result = new int * [rows];
  size_t number_index = 0;
  size_t created = 0;
  try
  {
  for (size_t i = 0; i < rows; i++)
  {
    result[i] = new int [lns[i]];
    for (size_t j = 0; j < lns[i]; j++)
    {
      result[i][j] = t[number_index];
      number_index++;
    }
    created++;
  }
}
catch (const std::bad_alloc &e)
{
  free_convert(result, created);
  throw;
}
return result;
}
void output(int ** result, size_t rows, const size_t * lns)
{
    if (result != nullptr)
    {
      for (size_t i = 0; i < rows; i++)
     {
        std::cout << result[i][0];
        for (size_t j = 1; j < lns[i]; j++)
        {
            std::cout << " " << result[i][j];
        }
        std::cout << "\n";
     } 
    }
    else 
    {
        std::cerr << "Error\n";
    }
}
int main() {
    int t[] = {5, 5, 5, 5, 6, 6, 7, 7, 7, 7, 7, 8};
    size_t n = 12;
    size_t lns[] = {4, 2, 5, 1};
    size_t rows = 4;
    int ** result = nullptr;
    try
    {
      result = convert(t, n, lns, rows);
    }
    catch (const std::bad_alloc &e)
    {
        std::cerr << e.what() << "\n";
        return 1;
    }
    std::cout << "matrix created!\n";
    output(result, rows, lns);
    free_convert(result, rows);
    return 0;
}