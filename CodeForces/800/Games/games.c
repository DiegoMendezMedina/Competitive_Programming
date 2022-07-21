#include <stdio.h>

/**
 * Games
 * https://codeforces.com/problemset/problem/268/A
 */

typedef struct tuple{
  int home;
  int away;
} tuple;

int match(tuple a, tuple b)
{
  return a.home == b.away;
}

int main()
{
  int n, i, j, sol;
  
  scanf("%d", &n);
  tuple equipos[n];
  
  for(i=0; i<n; i++){
    scanf("%d", &equipos[i].home);
    scanf("%d", &equipos[i].away);
  }

  sol = 0;
  for(i=0; i<n; i++)
    for(j=0; j<n; j++)
      if(match(equipos[i], equipos[j]) && i!=j)
	sol++;
  printf("%d\n", sol);
  
  return 0;
}
