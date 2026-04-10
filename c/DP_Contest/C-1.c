#include <stdio.h>
#define N (100000)
#define ACTIVITY (3)
#define chmax(a, b) (a) = ((a) > (b) ? (a) : (b))

int main(void)
{
  int i, j, k;
  long long result, dp[N + 1][ACTIVITY] = {0};
  int n, a[N][3];

  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d %d %d", &a[i][0], &a[i][1], &a[i][2]);
  }
  for (i = 0; i < n; i++) {
    for (j = 0; j < ACTIVITY; j++) {
      for (k = 0; k < ACTIVITY; k++) {
	if (j == k) {
	  continue;
	}
	chmax(dp[i + 1][k], dp[i][j] + a[i][k]);
      }
    }
  }

  result = 0;
  for (j = 0; j < ACTIVITY; j++) {
    chmax(result, dp[n][j]);
  }
  printf("%lld\n", result);
  return 0;
}
