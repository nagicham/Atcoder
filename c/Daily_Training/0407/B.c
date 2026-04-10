#include <stdio.h>
#include <string.h>
#define S (10)

int main(void)
{
  char s[S + 1], t[S + 1];

  scanf("%s", s);
  scanf("%s", t);
  if (strcmp(s, "AtCoder") == 0 && strcmp(t, "Land") == 0)
    {
      printf("Yes\n");
    }
  else
    {
      printf("No\n");
    }
  return 0;
}
	 
