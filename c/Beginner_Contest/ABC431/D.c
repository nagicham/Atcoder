#include <stdio.h>
#define N (500)
#define W (250000 / 2)
#define INF_LL (1000000000000000000)

struct part {
  int weight;
  long long value;
};

long long max(long long x, long long y)
{
  return x > y ? x : y;
}

int main(void)
{
  int i, j, k, sum_w;
  long long s, dp[W + 1];
  struct part a[N];
  int n, w;
  long long h, b;
  sum_w = k = 0;
  s = 0;
  
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d %lld %lld", &w, &h, &b);
    sum_w += w;
    s += b;
    if (h > b) {
      a[k].weight = w;
      a[k].value = h - b;
      k++;
    }
  }
  
  n = k;
  for (j = 1; j <= sum_w / 2; j++) {
    dp[j] = -INF_LL;
  }
  dp[0] = 0;

  for (i = 0; i < n; i++) {
    for (j = sum_w / 2; j >= 0; j--) {
      if (j >= a[i].weight) {
	dp[j] = max(dp[j], dp[j - a[i].weight] + a[i].value);
      }
    }
  }

  long long ans = -INF_LL;
  for (i = 0; i <= sum_w / 2; i++) {
    if (ans < dp[i]) {
      ans = dp[i];
    }
  }
  printf("%lld\n", ans + s);
  return 0;
}
