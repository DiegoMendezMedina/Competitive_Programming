#include <stdio.h>

/**
 * Soldier and Bananas.
 * https://codeforces.com/problemset/problem/546/A
 */

int main(){
  int k, w, n;
  int sum;
  scanf("%d %d %d", &k ,&n, &w);
  
  if(k < 1 || k > 1000 || w < 1 || w > 1000)
    return 0;
  if(n < 0 || n > 1000000000)
    return 0;
  
  sum = 0;
  for(int i = 1; i <= w; i++)
    sum += k*i;
  
  int r = sum -n;
  if(r > 0)
    printf("%d\n", r);
  else 
    printf("%d\n", 0);
}
