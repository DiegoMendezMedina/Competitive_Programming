#include <stdio.h>

/**
 * NIT Destroys the Universe solution.
 * https://codeforces.com/problemset/problem/1696/B
 */

int all_zeros(int* a, int l, int r)
{
  int i;

  for(i = l; i <= r; i++)
    if(a[i] != 0)
      return 0;
  return 1;
}

int solution(int* a, int n)
{
  int i, l, r;
  
  if(all_zeros(a, 0, n-1))
    return 0;
  
  l = r = -1;
  for(i = 0; i < n; i++)
    if(a[i] != 0){
      l = i;
      break;
    }

  if(i != -1)
    for(i = n-1; i > l; i--)
      if(a[i] != 0){
	r = i;
	break;
      }
  
  if(r == -1)
    return 1;

  l++;
  r--;
  for(i = l; i <= r; i++)
    if(a[i] == 0)
      return 2;
  
  return 1;
}

int main()
{
  int t, n, i, j;

  scanf("%d", &t);
  for(i = 0; i < t; i++){
    scanf("%d", &n);
    int a[n];
    for(j = 0; j < n; j++)
      scanf("%d", &a[j]);
    printf("%d\n", solution(a, n));
  }
  
  return 0;
}
