#include <stdio.h>
#include <string.h>
#define N (300)

double rec(int n, int i, int j, int k, double dp[N + 1][N + 1][N + 1])
{
  double result = 0.0;

  if (dp[i][j][k] >= 0.0) {
    return dp[i][j][k];
  }
  if (i > 0) {
    result += rec(n, i - 1, j, k, dp) * i;
  }
  if (j > 0) {
    result += rec(n, i + 1, j - 1, k, dp) * j;
  }
  if (k > 0) {
    result += rec(n, i, j + 1, k - 1, dp) * k;
  }

  result += n;
  result *= 1.0 / (i + j + k);

  return dp[i][j][k] = result;
}

int main(void)
{
  int i;
  double dp[N + 1][N + 1][N + 1];
  int n, temp, a, b, c;
  a = b = c = 0;
  
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d", &temp);
    if (temp == 1) {
      a++;
    }
    else if (temp == 2) {
      b++;
    }
    else {
      c++;
    }
  }

  memset(dp, -1.0, sizeof(dp));
  dp[0][0][0] = 0.0;

  printf("%.10lf\n", rec(n, a, b, c, dp));

  return 0;
}
