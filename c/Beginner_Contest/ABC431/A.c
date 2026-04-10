#include <stdio.h>

int main(void)
{
  int h, b;

  scanf("%d %d", &h, &b);
  printf("%d\n", h > b ? h - b : 0);
  return 0;
}
  

