#include <stdio.h>

void beautiful(int n, int aux, int flag);
/**
 * Solution to the CSES "Permutations problem.
 * https://cses.fi/problemset/task/1070/
 */
int main()
{
  int n;

  scanf("%d", &n);
  beautiful(2, n, 0);
}

/**
 * beautiful: Recursive function; prints the beatiful permutations if exists,
 *            "NO SOLUTION" if not.
 * NOTE: Al ready proven there are no beatiful permutation for aux = 3 and
 *       aux = 2.
 * @param n, int. next number of the permutation.
 * @param aux, int. last and max number of the permutation.
 * @param flag, int(BOOL). Determines if all the odd numbers have been printed.
 *            
 */
void beautiful(int n, int aux, int flag)
{
  if(aux == 1){
    printf("1\n");
    return;
  }
  
  if(aux == 3 || aux == 2){
    printf("NO SOLUTION\n");
    return;
  }
  
  if((n == aux | n == aux-1)){
    printf("%d ", n);
    if(!flag)
      beautiful(1, aux, 1);
    else
      printf("\n");
    return;
  }
  
  printf("%d ", n);
  beautiful(n+2, aux, flag);
}
