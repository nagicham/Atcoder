#include <stdio.h>
#define N (100)

int main(void)
{
  int n, q, type, num, count[N] = {0};
  
  scanf("%d%d", &n, &q);
  for (int i = 0; i < q; i++)
    {
      scanf("%d%d", &type, &num);
      if (type == 1)
	{
	  count[num - 1]++;
	}
      else if (type == 2)
	{
	  count[num - 1] += 2;
	}
      else
	{
	  if (count[num - 1] >= 2)
	    {
	      printf("Yes\n");
	    }
	  else
	    {
	      printf("No\n");
	    }
	}
    }
  return 0;
}
