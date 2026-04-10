#include <stdio.h>
#define N (3000)
#define ll long long

ll max(ll x, ll y)
{
  return x > y ? x : y;
}

ll min(ll x, ll y)
{
  return x > y ? y : x;
}

int main(void)
{
  int i, j;
  ll dp[N + 1][N + 1];
  int n, a[N];

  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  for (i = 0; i <= n; i++) {
    dp[i][i] = 0;
  }
  for (i = 1; i <= n; i++) {
    for (j = 0; j <= n - i; j++) {
      if ((n - i) % 2) { //ŒãŽè
	dp[j][j + i] = min(dp[j + 1][j + i] - (ll)a[j], dp[j][j + i - 1] - (ll)a[j + i - 1]);
      }
      else { //æŽè
	dp[j][j + i] = max(dp[j + 1][j + i] + (ll)a[j], dp[j][j + i - 1] + (ll)a[j + i - 1]);
      }
    }
  }
  printf("%lld\n", dp[0][n]);
  return 0;
}
