
//静的確保
//dpテーブルは二次元配列

#include <stdio.h>
#define N (2999)

int main(void)
{
  int i, j;
  double sum, dp[N + 1][N + 1] = {0};
  int n;
  double p[N];
  sum = 0.0;
  
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%lf", &p[i]);
  }
  dp[0][0] = 1.0;
  for (i = 0; i < n; i++) {
    for (j = 0; j <= i; j++) {
      dp[i + 1][j + 1] += dp[i][j] * p[i];
      dp[i + 1][j] += dp[i][j] * (1.0 - p[i]);
    }
  }
  for (j = n / 2 + 1; j <= n; j++) {
    sum += dp[n][j];
  }
  printf("%.10lf\n", sum);
  return 0;
}
