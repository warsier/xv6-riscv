#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
#include "kernel/fs.h"
#include "kernel/fcntl.h"

#define ABS(x) ((x) < 0 ? -(x) : (x))

int **
matrix_alloc(int size)
{
  int **ptr = (int **)malloc(sizeof(int *) * size);
  int i;
  for (i = 0; i < size; i++)
  {
    ptr[i] = (int *)malloc(sizeof(int) * size);
  }
  return ptr;
}

void matrix_free(int **ptr, int size)
{
  int i;
  for (i = 0; i < size; i++)
    free(ptr[i]);
  free(ptr);
}

int **
matrix_mul(int **result, int **x, int **y, int size)
{
  int i, j, k;
  for (i = 0; i < size; i++)
  {
    for (j = 0; j < size; j++)
    {
      result[i][j] = 0;
      for (k = 0; k < size; k++)
      {
        result[i][j] += x[i][k] * y[k][j];
      }
    }
  }
  return result;
}

int main(int argc, char *argv[])
{
  const int LEN = 100;
  int **a = matrix_alloc(LEN);
  int **b = matrix_alloc(LEN);
  int **c = matrix_alloc(LEN);
  for (int i = 0; i < 300; i++)
  {
    if (i % 2 == 0)
      matrix_mul(c, a, b, LEN);
    else
      matrix_mul(a, c, b, LEN);
  }
  printf("finished testproc2\n");
  exit(0);
}