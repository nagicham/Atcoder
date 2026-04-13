#include <stdio.h>
#define S (100000)

void swap(char *a, char *b)
{
  char temp;

  temp = *a;
  *a = *b;
  *b = temp;
}

int main(void)
{
  int l, r;
  char s[S + 1];

  scanf("%d%d", &l, &r);
  scanf("%s", s);
  l--;
  r--;
  while (l < r)
    {
      swap(&s[l++], &s[r--]);
    }
  printf("%s\n", s);
  return 0;
}
