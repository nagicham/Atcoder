#include <stdio.h>
#define N (100)
#define W (100000)
#define chmax(a, b) (a) = ((a) > (b) ? (a) : (b))

struct item {
  int weight;
  int value;
};

int main(void)
{
  int i, j;
  long long result, dp[N + 1][W + 1] = {0};
  int n, w;
  struct item a[N];
  
  scanf("%d %d", &n, &w);
  for (i = 0; i < n; i++) {
    scanf("%d %d", &a[i].weight, &a[i].value);
  }

  for (i = 0; i < n; i++) {
    for (j = 0; j <= w; j++) {
      chmax(dp[i + 1][j], dp[i][j]);
      if (j >= a[i].weight) {
	chmax(dp[i + 1][j], dp[i][j - a[i].weight] + a[i].value);
      }
    }
  }

  result = 0;
  for (j = 1; j <= w; j++) {
    chmax(result, dp[n][j]);
  }
  printf("%lld\n", result);

  return 0;
}
