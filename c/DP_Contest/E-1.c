#include <stdio.h>
#define N (100)
#define V (100000)
#define INF (1000000000000000000)
#define chmin(a, b) (a) = ((b) > (a) ? (a) : (b))

struct item {
  int weight;
  int value;
};

int main(void)
{
  int i, j, v_sum, result;
  long long dp[N + 1][V + 1];
  int n, w;
  struct item a[N];
  v_sum = 0;
  
  scanf("%d %d", &n, &w);
  for (i = 0; i < n; i++) {
    scanf("%d %d", &a[i].weight, &a[i].value);
    v_sum += a[i].value;
  }
  for (i = 0; i <= n; i++) {
    for (j = 0; j <= v_sum; j++) {
      dp[i][j] = INF;
    }
  }
  dp[0][0] = 0;
  for (i = 0; i < n; i++) {
    for (j = 0; j <= v_sum; j++) {
      chmin(dp[i + 1][j], dp[i][j]);
      if (j >= a[i].value) {
	chmin(dp[i + 1][j], dp[i][j - a[i].value] + a[i].weight);
      }
    }
  }
  
  result = 0;
  for (j = 1; j <= v_sum; j++) {
    if (dp[n][j] <= w) {
      result = j;
    }
  }
  printf("%d\n", result);
  return 0;
}
