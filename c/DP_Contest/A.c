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
  int i;
  long long dp[N];
  int n, h[N];
  
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d", &h[i]);
    dp[i] = INF;
  }
  dp[0] = 0;
  dp[1] = (long long)abs_num(h[1] - h[0]);
  for (i = 2; i < n; i++) {
    chmin(dp[i], dp[i - 1] + (long long)abs_num(h[i] - h[i - 1]));
    chmin(dp[i], dp[i - 2] + (long long)abs_num(h[i] - h[i - 2]));
  }

  printf("%lld\n", dp[n - 1]);
  return 0;
}
