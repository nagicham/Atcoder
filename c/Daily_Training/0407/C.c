#include <stdio.h>
#define N (100)

int main(void)
{
  int n, k, count = 0, ans = 0;
  char s[N + 1];
  
  scanf("%d%d", &n, &k);
  scanf("%s", s);

  for (int i = 0; i < n; i++)
    {
      if (s[i] == 'O')
	{
	  count++;
	}
      else
	{
	  count = 0;
	}
      if (count == k)
	{
	  ans++;
	  count = 0;
	}
    }
  printf("%d\n", ans);
  return 0;
}
