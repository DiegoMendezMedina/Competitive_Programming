#include <stdio.h>

int main(){
  int t, n;
  
  scanf("%d", &t);
  
  for(int cont = 1; cont <= t; cont++){
    scanf("%d", &n);
    
    for(int i = 1; i <= n; i++)
      printf("%d ", 2*(n+i));
    
    printf("\n");
  }
  return 0;
}
