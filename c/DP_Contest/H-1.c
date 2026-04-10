#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MOD (1000000007)
#define chmax(a, b) (a) = ((a) > (b) ? (a) : (b))

int main(void)
{
  int i, j, **dp;
  int h, w;
  char **map;

  scanf("%d %d", &h, &w);

  dp = (int **)malloc(sizeof(int *) * h);
  map = (char **)malloc(sizeof(char *) * h);

  for (i = 0; i < h; i++) {
    dp[i] = (int *)malloc(sizeof(int) * w);
    memset(dp[i], 0, sizeof(int) * w);
    map[i] = (char *)malloc(sizeof(char) * (w + 1));
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
