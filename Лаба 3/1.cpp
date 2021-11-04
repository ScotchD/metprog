#include <stdio.h>
#include <string.h>
#define SIZE 1002
int x[SIZE], y[SIZE], dp[SIZE][SIZE];
int n, m, i, j, res;
int max(int i, int j)
{
  return (i > j) ? i : j;
}
int lcs(int *x, int *y, int m, int n)
{
  if (m == 0 || n == 0)
    return 0;
  if (dp[m][n] != -1) return dp[m][n];
  if (x[m] == y[n])
    return dp[m][n] = 1 + lcs(x, y, m - 1, n - 1);
  else
    return dp[m][n] = max(lcs(x, y, m, n - 1), lcs(x, y, m - 1, n));
}
int main(void)
{
  scanf("%d", &n);
  for (i = 1; i <= n; i++) scanf("%d", &x[i]);
  scanf("%d", &m);
  for (i = 1; i <= m; i++) scanf("%d", &y[i]);
  memset(dp, -1, sizeof(dp));
  res = lcs(x, y, n, m);
  printf("%d\n", res);
  return 0;
}
