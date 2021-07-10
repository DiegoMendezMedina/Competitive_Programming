#include <stdio.h>

int missing(int n);

/**
 * Solution to CSES "missing number" problem
 * https://cses.fi/problemset/task/1083
*/
int main()
{
  int n;
 
  scanf("%d", &n);
  printf("%d\n", missing(n));
  return 0;
}

/**
 * missing: Finds the missing number.
 * @param : n, int. Max number.
*/
int missing(int n)
{
  int sum, aux, sumaux;

  sum = sumaux = 0;
  for(int i = 1; i < n; i++){
    scanf("%d", &aux);
    sumaux += aux;
    sum += i;
  }
  
  sum += n;
  return sum - sumaux;
}
