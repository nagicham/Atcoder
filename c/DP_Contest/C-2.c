#include <stdio.h>
#define N (100000)
#define ACTIVITY (3)
#define chmax(a, b) (a) = ((a) > (b) ? (a) : (b))

int main(void)
{
  int i, j;
  long long result, dp[N + 1][ACTIVITY] = {0};
  int n, a[N], b[N], c[N];

  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d %d %d", &a[i], &b[i], &c[i]);
  }
  
  for (i = 0; i < n; i++) {
    j = 0; 
    chmax(dp[i + 1][j], dp[i][1] + a[i]);
    chmax(dp[i + 1][j], dp[i][2] + a[i]);
    j = 1;
    chmax(dp[i + 1][j], dp[i][0] + b[i]);
    chmax(dp[i + 1][j], dp[i][2] + b[i]);    
    j = 2;
    chmax(dp[i + 1][j], dp[i][0] + c[i]);
    chmax(dp[i + 1][j], dp[i][1] + c[i]);
  }
  
  result = 0;
  for (j = 0; j < ACTIVITY; j++) {
    chmax(result, dp[n][j]);
  }
  printf("%lld\n", result);
  return 0;
}
