#include <iostream>
#include <new>

int ** makeMtx(int ** mtx, size_t m, size_t n);
int ** transpose(int ** mtx, size_t m, size_t n);
void rmMtx(int ** mtx, size_t m);

int main()
{
  size_t m = 0;
  size_t n = 0;
  std::cin >> m >> n;
  if (!std::cin || m == 0 || n == 0)
  {
    return 1;
  }

  int ** mtx = nullptr;
  try
  {
    mtx = makeMtx(mtx, m, n);
  }
  catch (const std::bad_alloc&)
  {
    return 2;
  }

  for (size_t i = 0; i < m; ++i)
  {
    for (size_t j = 0; j < n; ++j)
    {
      if (!(std::cin >> mtx[i][j]))
      {
        rmMtx(mtx, m);
        return 1;
      }
    }
  }

  int ** transposed = nullptr;
  try
  {
    transposed = transpose(mtx, m, n);
  }
  catch (const std::bad_alloc&)
  {
    rmMtx(mtx, m);
    return 2;
  }

  for (size_t i = 0; i < n; ++i)
  {
    for (size_t j = 0; j < m; ++j)
    {
      std::cout << transposed[i][j];
      if (j < m - 1)
      {
        std::cout << " ";
      }
    }
    std::cout << "\n";
  }

  rmMtx(mtx, m);
  rmMtx(transposed, n);

  return 0;
}

int ** makeMtx(int ** mtx, size_t m, size_t n)
{
  mtx = new int *[m];
  for (size_t i = 0; i < m; ++i)
  {
    mtx[i] = new int[n];
  }
  return mtx;
}

int ** transpose(int ** mtx, size_t m, size_t n)
{
  int ** result = makeMtx(nullptr, n, m);
  for (size_t i = 0; i < m; ++i)
  {
    for (size_t j = 0; j < n; ++j)
    {
      result[j][i] = mtx[i][j];
    }
  }
  return result;
}

void rmMtx(int ** mtx, size_t m)
{
  if (mtx == nullptr)
  {
    return;
  }
  for (size_t i = 0; i < m; ++i)
  {
    delete[] mtx[i];
  }
  delete[] mtx;
}
