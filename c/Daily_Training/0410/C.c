#include <stdio.h>
#include <stdbool.h>
#define M (100)

int main(void)
{
  int n, m, a;
  char b;
  bool baby[M] = {false};

  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; i++)
    {
      scanf("%d", &a);
      getchar();
      scanf("%c", &b);
      if (!baby[a] && b == 'M')
	{
	  printf("Yes\n");
	  baby[a] = true;
	}
      else
	{
	  printf("No\n");
	}
    }
  return 0;
}
