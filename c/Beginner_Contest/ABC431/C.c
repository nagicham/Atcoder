#include <stdio.h>
#define N (200000)

void swap(int i, int j, int a[])
{
  int temp;

  temp = a[i];
  a[i] = a[j];
  a[j] = temp;
}
 
void quick_sort(int left, int right, int a[])
{
  int i, j, pivot;
  i = left;
  j = right;
  pivot = a[i];
  
  if (left >= right) {
    return;
  }

  while (1) {
    while (a[i] < pivot) {
      i++;
    }
    while (a[j] > pivot) {
      j--;
    }
    if (i >= j) {
      break;
    }
    swap(i, j, a);
    i++;
    j--;
  }

  quick_sort(left, i - 1, a);
  quick_sort(j + 1, right, a);
}

int main(void)
{
  int i, j, count;
  int n, m, k;
  int h[N], b[N];
  j = count = 0;
  
  scanf("%d %d %d", &n, &m, &k);
  for (i = 0; i < n; i++) {
    scanf("%d", &h[i]);
  }
  quick_sort(0, n - 1, h);
  for (i = 0; i < m; i++) {
    scanf("%d", &b[i]);
  }
  quick_sort(0, m - 1, b);

  for (i = 0; i < n; i++) {
    while (j < m) {
      if (h[i] <= b[j]) {
	j++;
	count++;
	break;
      }
      j++;
    }
    if (count >= k) {
      printf("Yes\n");
      return 0;
    }
    else if (j >= m) {
      break;
    }
  }
  printf("No\n");
  return 0;
}
