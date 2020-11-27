#include <stdio.h>

/**
 * Elimination.
 * https://codeforces.com/problemset/problem/1445/B
 */

int main(){
  int t, a, b, c, d;
  int s1, s2;
  scanf("%d", &t);

  if(t < 1 || t > 3025)
    return 0;
  
  while(t >0){
    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &c);
    scanf("%d", &d);

    if( a < 0 || d > 9 || d > a || b > c)
      return 0;
    
    s1 = a+b;
    s2 = c+d;
    if(s1 > s2)
      printf("%d\n", s1);
    else
      printf("%d\n", s2);
    t--;
  }
}
