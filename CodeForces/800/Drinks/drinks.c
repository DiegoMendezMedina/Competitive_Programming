#include <stdio.h>

/**
 * Drinks.
 * https://codeforces.com/problemset/problem/200/B
 */

int main(){
  int n;
  float aux, ps;
  
  scanf("%d", &n);
  
  if(n < 1 || n > 100)
    return 0;
  
  ps = 0;
  
  for(int i = 1; i <= n; i++){
    scanf("%f", &aux);
    ps += aux;
  }
  printf("%f\n", ps/n);
}
