#include <stdio.h>
#define N (100)

int main(void)
{
  int i;
  int part[N] = {0};
  int x, n, q, p;
  int w[N];

  scanf("%d %d", &x, &n);
  for (i = 0; i < n; i++) {
    scanf("%d", &w[i]);
  }
  scanf("%d", &q);
  for (i = 0; i < q; i++) {
    scanf("%d", &p);
    if (part[p - 1]) {
      part[p - 1] = 0;
      x -= w[p - 1];
    }
    else {
      part[p - 1] = 1;
      x += w[p - 1];
    }
    printf("%d\n", x);
  }
  
  return 0;
}
