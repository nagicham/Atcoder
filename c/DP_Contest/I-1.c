
//動的確保
//dpテーブルは一次元配列

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N (2999)

int main(void)
{
  int i, j;
  double sum, *dp;
  int n;
  double *p;
  sum = 0.0;
  
  scanf("%d", &n);

  p = (double *)malloc(sizeof(double) * n);
  dp = (double *)malloc(sizeof(double) * (n + 1));
  memset(dp, 0.0, sizeof(double) * (n + 1));
  
  for (i = 0; i < n; i++) {
    scanf("%lf", &p[i]);
  }
  
  dp[0] = 1.0;
  for (i = 0; i < n; i++) {
    for (j = i; j >= 0; j--) {
      dp[j + 1] += dp[j] * p[i];
      dp[j] *= (1.0 - p[i]);
    }
  }
  for (j = n / 2 + 1; j <= n; j++) {
    sum += dp[j];
  }
  printf("%.10lf\n", sum);
  return 0;
}
