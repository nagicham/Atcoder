#include <stdio.h>
#include <stdlib.h>
#define N (100000)
#define chmax(a, b) (a) = ((a) > (b) ? (a) : (b))

struct list {
  int vertex;
  struct list *next;
};

void add(struct list *p, int x)
{
  struct list *q;

  q = (struct list *)malloc(sizeof(struct list));
  while (p->next != NULL) {
    p = p->next;
  }
  p->vertex = x;
  p->next = q;
  q->next = NULL;
}

int rec(struct list *p[N], int idx, int memo[])
{
  int temp, max = 0;

  if (memo[idx] != -1) {
    return memo[idx];
  }
  if (p[idx]->next == NULL) {
    return memo[idx] = 0;
  }
  while (p[idx]->next != NULL) {
    temp = rec(p, p[idx]->vertex, memo);
    chmax(max, 1 + temp);
    p[idx] = p[idx]->next;
  }

  return memo[idx] = max;
}

int main(void)
{
  int i, longest, temp, memo[N];
  struct list *g[N];
  int n, m, x, y;
  longest = 0;

  scanf("%d %d", &n, &m);
  for (i = 0; i < n; i++) {
    g[i] = (struct list *)malloc(sizeof(struct list));
    g[i]->next = NULL;
    memo[i] = -1;
  }
  
  for (i = 0; i < m; i++) {
    scanf("%d %d", &x, &y);
    add(g[x - 1], y - 1);
  }
  
  for (i = 0; i < n; i++) {
    temp = rec(g, i, memo);
    chmax(longest, temp);
  }

  printf("%d\n", longest);

  return 0;
}
