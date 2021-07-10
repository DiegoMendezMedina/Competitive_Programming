#include <stdio.h>

void weird(long n);
/**
 * Solution to the CSES "Wird Algorithm" problem.
 * https://cses.fi/problemset/task/1083
 */
int main()
{
  long n;
  
  scanf("%ld", &n);
  weird(n);
}

/**
 * weird: Recursive function; prints and determines the next weird number.
 * @param n, long. Weird number.
 */
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
