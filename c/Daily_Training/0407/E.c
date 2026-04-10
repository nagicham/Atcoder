#include <stdio.h>
#define ll long long

ll llabs(ll x)
{
  return x > 0 ? x : -x;
}

int main(void)
{
  ll diff_x, diff_y, ans;
  ll s_x, s_y, t_x, t_y;

  scanf("%lld%lld%lld%lld", &s_x, &s_y, &t_x, &t_y);
  if ((s_x + s_y) % 2 == 1)
    {
      s_x--;
    }
  if ((t_x + t_y) % 2 == 1)
    {
      t_x--;
    }
  diff_x = llabs(s_x - t_x);
  diff_y = llabs(s_y - t_y);
  ans = diff_y;
  diff_x -= diff_y;
  if (diff_x > 0)
    {
      ans += diff_x / 2;
    }
  printf("%lld\n", ans);
  return 0;
}
