
//メモリ容量オーバーでうまくいかないです

#include <stdio.h>
#include <stdlib.h>
#define N (100000)
#define chmax(a, b) (a) = ((a) > (b) ? (a) : (b))

void add(int a[], int n)
{
  while (*a != -1) {
    a++;
  }
  *a = n;
  *(a + 1) = -1;
}

int rec(int a[N][N], int idx, int dp[])
{
  int i, max;
  i = max = 0;
  
  if (dp[idx] != -1) {
    return dp[idx];
  }
  while (a[idx][i] != -1) {
    chmax(max, rec(a, a[idx][i], dp) + 1);
    i++;
  }
  return dp[idx] = max;
}

int main(void)
{
  int i, result, dp[N], g[N][N];
  int n, m, x, y;
  result = 0;

  scanf("%d %d", &n, &m);

  for (i = 0; i < n; i++) {
    g[i][0] = dp[i] = -1;
  }
  for (i = 0; i < m; i++) {
    scanf("%d %d", &x, &y);
    add(g[x - 1], y - 1);
  }
  for (i = 0; i < n; i++) {
    chmax(result, rec(g, i, dp));
  }
  printf("%d\n", result);

  return 0;
}
