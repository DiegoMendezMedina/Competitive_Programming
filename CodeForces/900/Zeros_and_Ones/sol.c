#include <stdio.h>

/**
 * Case of the Zeros and Ones
 * https://codeforces.com/problemset/problem/556/A
 */


int main()
{
  int n, i, nz, no, sol;
  scanf("%d", &n);
  
  char s[n+1];
  scanf("%s", s);

  nz = no = 0;
  for(i = 0; i < n; i++)
    if(s[i] == '0')
      nz ++;
    else if(s[i] == '1')
      no++;
  
  sol = (nz > no)? nz-no : no-nz;
  printf("%d\n", sol);
  return 0;
}
