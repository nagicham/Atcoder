
//静的確保
//dpテーブルは一次元配列

#include <stdio.h>
#define N (2999)

int main(void)
{
  int i, j;
  double sum, dp[N + 1] = {0};
  int n;
  double p[N];
  sum = 0.0;
  
  scanf("%d", &n);
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
