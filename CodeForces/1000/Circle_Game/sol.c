#include <stdio.h>

/**
 * Circle Game solution
 * https://codeforces.com/problemset/problem/1695/B
 */

/* true if Mike win*/
int sol(int * a, int n)
{
  int i, min, j;

  if(n%2 != 0)
    return 1;

  j = 0;
  min = a[0];
  for(i = 1; i < n; i++)
    if(min > a[i]){
      min = a[i];
      j = i;
    }

  return (j%2 == 0)? 0:1;
}

int main()
{
  int t, n, i, j, res;

  scanf("%d", &t);

  for(i = 0; i < t; i++){
    scanf("%d", &n);
    int a[n];
    for(j = 0; j < n; j++)
      scanf("%d", &a[j]);
    res = sol(a, n);
    if(res)
      printf("Mike\n");
    else printf("Joe\n");
  }
  
  return 0;
}
