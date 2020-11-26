#include <stdio.h>

/**
 * Bit++
 * https://codeforces.com/contest/282/problem/A
 */
 
int main(){
  int n;
  int res;
  char s[5];
  
  scanf("%d", &n);
  
  if(n < 1 || n > 150)
    return 0;
  
  res = 0;
  for(int i = 1; i <= n; i++){
    scanf("%s", s);
    
    for(int j = 0; j < 3; j++)
      if(s[j] == '+' && s[j+1] =='+'){
	res++;
	break;
      }
      else if(s[j] == '-' && s[j+1] == '-'){
	res--;
	break;
      }
  }
  
  printf("%d\n", res);
  return 0;
}
