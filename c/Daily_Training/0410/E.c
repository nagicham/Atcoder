#include <stdio.h>
#include <stdbool.h>
#define N (8)

int permutation[N] = {0};
int ga[N][N] = {0}, gb[N][N] = {0}, gcopy[N][N] = {0};
bool flag = false, used[N] = {false};

bool check(int n)
{
  for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
	{
	  if (ga[i][j] != gcopy[i][j])
	    {
	      return false;
	    }
	}
    }
  return true;
}

void func(int n, int k)
{
  int i, j;
  
  if (k == n)
    {
      for (i = 0; i < n; i++)
	{
	  for (j = 0; j < n; j++)
	    {
	      gcopy[i][j] = gb[permutation[i]][permutation[j]];
	    }
	}
      if (check(n))
	{
	  flag = true;
	  return;
	}
    }
  else
    {
      for (i = 0; i < n; i++)
	{
	  if (used[i])
	    {
	      continue;
	    }
	  permutation[k] = i;
	  used[i] = true;
	  func(n, k + 1);
	  used[i] = false;
	}
    }
}

int main(void)
{
  int i;
  int n, m, a, b;

  scanf("%d%d", &n, &m);
  for (i = 0; i < m; i++)
    {
      scanf("%d%d", &a, &b);
      ga[a - 1][b - 1] = 1;
      ga[b - 1][a - 1] = 1;
    }
  for (i = 0; i < m; i++)
    {
      scanf("%d%d", &a, &b);
      gb[a - 1][b - 1] = 1;
      gb[b - 1][a - 1] = 1;
    }
  func(n, 0);
  if (flag)
    {
      printf("Yes\n");
    }
  else
    {
      printf("No\n");
    }
  return 0;
}
