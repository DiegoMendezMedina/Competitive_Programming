#include <stdio.h>

void weird(long n);

int main()
{
  long n;
  
  scanf("%ld", &n);
  weird(n);
}

void weird(long n)
{
  if(n == 1){
    printf("1\n");
    return;
  }
  printf("%ld ", n);
  if(n % 2 == 0)
    weird(n/2);
  
  else weird((n*3)+1);
}
