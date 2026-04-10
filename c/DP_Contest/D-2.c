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
  long long result, dp[W + 1] = {0};
  int n, w;
  struct item a[N];
  
  scanf("%d %d", &n, &w);
  for (i = 0; i < n; i++) {
    scanf("%d %d", &a[i].weight, &a[i].value);
  }
  for (i = 0; i < n; i++) {
    for (j = w; j >= 0; j--) {
      if (j >= a[i].weight) {
	chmax(dp[j], dp[j - a[i].weight] + a[i].value);
      }
    }
  }
  result = 0;
  for (j = 1; j <= w; j++) {
    chmax(result, dp[j]);
  }
  printf("%lld\n", result);

  return 0;
}
