#include "add.h"
#include <stdio.h>

extern int add(int a, int b);

int main(void)
{
  int a = 5;
  int b = 3;
  int c = add(a, b);

  printf("%d\n", c);

  return 0;
}
