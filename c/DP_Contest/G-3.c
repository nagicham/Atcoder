
//ƒƒ‚ƒŠ‚Í“®“IŠm•Û‚¶‚á‚È‚­‚Ä‚à“®ì‚µ‚Ü‚·

#include <stdio.h>
#include <stdlib.h>
#define N (100000)
#define chmax(a, b) (a) = ((a) > (b) ? (a) : (b))

struct list {
  int vertex;
  struct list *next;
};

void add(struct list *g[], int x, int y)
{
  struct list *p;
  
  p = (struct list *)malloc(sizeof(struct list));
  p->vertex = y;
  p->next = g[x];
  g[x] = p;
}

int main(void)
{
  int i, front, back, temp, topo_size, result, *indeg, *queue, *topo, *dp;
  struct list *p, **g;
  int n, m, x, y;
  front = back = topo_size = result = 0;
  
  scanf("%d %d", &n, &m);

  indeg = (int *)malloc(sizeof(int) * n);
  queue = (int *)malloc(sizeof(int) * n);
  topo = (int *)malloc(sizeof(int) * n);
  dp = (int *)malloc(sizeof(int) * n);
  g = (struct list **)malloc(sizeof(struct list) * n);

  for (i = 0; i < n; i++) {
    g[i] = NULL;
    indeg[i] = 0;
    dp[i] = 0;
  }
  for (i = 0; i < m; i++) {
    scanf("%d %d", &x, &y);
    add(g, x - 1, y - 1);
    indeg[y - 1]++;
  }
  
  for (i = 0; i < n; i++) {
    if (indeg[i] == 0) {
      queue[back++] = i;
    }
  }
  while (front < back) {
    temp = queue[front++];
    topo[topo_size++] = temp;
    for (p = g[temp]; p != NULL; p = p->next) {
      indeg[p->vertex]--;
      if (indeg[p->vertex] == 0) {
	queue[back++] = p->vertex;
      }
    }
  }

  for (i = topo_size - 1; i >= 0; i--) {
    temp = topo[i];
    for (p = g[temp]; p != NULL; p = p->next) {
      chmax(dp[temp], dp[p->vertex] + 1);
    }
  }

  for (i = 0; i < n; i++) {
    chmax(result, dp[i]);
  }
  printf("%d\n", result);
  return 0;
}
