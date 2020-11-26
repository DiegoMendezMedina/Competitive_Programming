#include <stdio.h>

/**
 * Domino piling
 * https://codeforces.com/problemset/problem/50/A
 */

int main(){
  int M, N, area;

  scanf("%d", &M);
  scanf("%d", &N);

  if(M < 1|| N < 1 ||
     M > 16 || N > 16)
    return 0;

  area = M*N;

  if(area % 2 != 0)
    area = area -1;

  printf("%d\n", area/2);
    
}
