#include <stdio.h>
#include <math.h>
#define N (6)

void func(int i, int j, int n, char carpet[(int)pow(3, N)][(int)pow(3, N) +1])
{
  if (n == 0)
    {
      carpet[i][j] = '#';
    }
  else
    {
      for (int k = 0; k < 3; k++)
	{
	  for (int l = 0; l < 3; l++)
	    {
	      if (k == 1 && l == 1)
		{
		  for (int s = 0; s < pow(3, n - 1); s++)
		    {
		      for (int t = 0; t < pow(3, n - 1); t++)
			{
			  carpet[i + (int)pow(3, n - 1) + s][j + (int)pow(3, n - 1) + t] = '.';
			}
		    }
		}
	      else
		{
		  func(i + pow(3, n - 1) * k, j + pow(3, n - 1) * l, n - 1, carpet);
		}
	    }
	}
    }
}

int main(void)
{
  int n;
  char carpet[(int)pow(3, N)][(int)pow(3, N) + 1];

  scanf("%d", &n);
  func(0, 0, n, carpet);
  for (int i = 0; i < pow(3, n); i++)
    {
      carpet[i][(int)pow(3, n)] = '\0';
    }
  for (int i = 0; i < pow(3, n); i++)
    {
      printf("%s\n", carpet[i]);
    }
  return 0;
}
