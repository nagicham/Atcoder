#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define K (100000)
#define N (100)

int main(void)
{
  int i, j;
  bool dp[K + 1];
  int n, k, a[N];

  scanf("%d%d", &n, &k);
  for (i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  memset(dp, false, sizeof(bool) * (k + 1));
  for (i = 1; i <= k; i++) {
    for (j = 0; j < n; j++) {
      if (i >= a[j]) {
	if (!(dp[i - a[j]])) {
	    dp[i] = true;
	}
      }
    }
  }
  if (dp[k]) {
    printf("First\n");
  }
  else {
    printf("Second\n");
  }
  return 0;
}
