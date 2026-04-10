#include <stdio.h>
#include <string.h>
#define N (3000)
#define chmax(a, b) (a) = ((a) > (b) ? (a) : (b))

void add(char *s, char a)
{
  for (int i = strlen(s); i >= 0; i--) {
    s[i + 1] = s[i];
  }
  s[0] = a;
}

int main(void)
{
  int i, j, dp[N + 1][N + 1] = {0};
  char result[N + 1];
  char s[N + 1], t[N + 1];

  scanf("%s", s);
  scanf("%s", t);

  for (i = 0; i < strlen(s); i++) {
    for (j = 0; j < strlen(t); j++) {
      if (s[i] == t[j]) {
	chmax(dp[i + 1][j + 1], dp[i][j] + 1);
      }
      chmax(dp[i + 1][j + 1], dp[i + 1][j]);
      chmax(dp[i + 1][j + 1], dp[i][j + 1]);
    }
  }

  i = (int)strlen(s);
  j = (int)strlen(t);
  result[0] = '\0';
  while (dp[i][j] > 0) {
    if (dp[i][j] == dp[i - 1][j]) {
      i--;
    }
    else if (dp[i][j] == dp[i][j - 1]) {
      j--;
    }
    else {
      add(result, s[i - 1]);
      i--;
      j--;
    }
  }
  printf("%s\n", result);
  return 0;
}
