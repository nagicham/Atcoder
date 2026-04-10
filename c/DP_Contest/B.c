#include <stdio.h>
#define N (100000)
#define INF (1000000000000000000)
#define chmin(a, b) ((a) = (a) < (b) ? (a) : (b))

int abs_num(int n)
{
  return n > 0 ? n : -n;
}

int main(void)
{
  int i, j;
  long long dp[N];
  int n, k, h[N];

  scanf("%d %d", &n, &k);
  for (i = 0; i < n; i++) {
    scanf("%d", &h[i]);
    dp[i] = INF;
  }
  dp[0] = 0;
  for (i = 1; i < n; i++) {
    for (j = 1; j <= k; j++) {
      if (i >= j) {
	chmin(dp[i], dp[i - j] + (long long)abs_num(h[i] - h[i - j]));
      }
    }
  }
  printf("%lld\n", dp[n - 1]);
  return 0;
}
