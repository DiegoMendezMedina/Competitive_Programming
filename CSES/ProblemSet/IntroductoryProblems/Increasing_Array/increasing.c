#include <stdio.h>

long increasing(int n);

/**
 * Solution to the CSES "Increasing Array" problem.
 * https://cses.fi/problemset/task/1094
 */
int main()
{
  int n;
  
  scanf("%d", &n);
  printf("%ld\n", increasing(n));
}

/**
 * increasing: solution to the increasing array problem.
 * @param n, int. Size of the input.
 */
long increasing(int n)
{
  int i, next, prev, aux;
  long cont;
  
  cont = aux = 0;
  i = 1;
  while(i <= n){
    aux = 0;
    if(i == 1)
      scanf("%d", &prev);
    else{
      scanf("%d", &next);
      aux = (next < prev)? prev-next : 0;
      prev = next + aux;
      cont += aux;
    }
    i++;
  }
  return cont;
}
