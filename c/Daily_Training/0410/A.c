#include <stdio.h>
#define N (20)

int main(void)
{
  int n;
  char s[N + 1];

  scanf("%d", &n);
  scanf("%s", s);
  if (n >= 3 && s[n - 3] == 't' && s[n - 2] == 'e' && s[n - 1] == 'a')
    {
      printf("Yes\n");
    }
  else
    {
      printf("No\n");
    }
  return 0;
}
