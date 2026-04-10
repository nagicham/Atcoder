#include <stdio.h>

int main(void)
{
  int s, a, b, x;
  int ans = 0;

  scanf("%d%d%d%d", &s, &a, &b, &x);
  while (x > 0)
    {
      for (int i = 0; i < a; i++)
	{
	  ans += s;
	  x--;
	  if (x <= 0)
	    {
	      break;
	    }
	}
      x -= b;
    }
  printf("%d\n", ans);
  return 0;
}
