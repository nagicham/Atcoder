#include <stdio.h>
#define N (1000)
#define MOD (1000000007)
#define chmax(a, b) (a) = ((a) > (b) ? (a) : (b))

int main(void)
{
  int i, j, dp[N][N] = {0};
  int h, w;
  char map[N][N + 1];

  scanf("%d %d", &h, &w);
  for (i = 0; i < h; i++) {
    scanf("%s", map[i]);
  }

  dp[0][0] = 1;
  
  for (i = 0; i < h; i++) {
    for (j = 0; j < w; j++) {
      if (i + 1 < h && map[i + 1][j] == '.') {
	dp[i + 1][j] += dp[i][j];
	dp[i + 1][j] %= MOD;
      }
      if (j + 1 < w && map[i][j + 1] == '.') {
	dp[i][j + 1] += dp[i][j];
	dp[i][j + 1] %= MOD;
      }
    }
  }

  printf("%d\n", dp[i - 1][j - 1]);
  return 0;
}
