#include <stdio.h>

/**
 * Ultra-Fast Mathematician.
 * https://codeforces.com/problemset/problem/61/A
 */


int main(){
  char s1[110];
  char s2[110];
  int r[110];
  
  scanf("%s", s1);
  scanf("%s", s2);
  
  int i, cont;

  for(i = 0;  s1[i] == '0' ||  s1[i] == '1'; i++)
    if(s1[i] == s2[i])
      r[i] = 0;
    else
      r[i] = 1;
  
  cont = i;
  
  for(i = 0;  i < cont; i++)
    printf("%d", r[i]);
  printf("\n");
}
