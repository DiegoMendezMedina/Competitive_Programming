#include <stdio.h>

/**
 * HQ9+
 * https://codeforces.com/problemset/problem/133/A
 */

int main()
{
  int i;
  char s[101];
  scanf("%s", s);
  
  for(i = 0; i < 101; i++)
    if(s[i] == 'H' || s[i] == 'Q'
       || s[i] == '9'){
      printf("YES\n");
      return 0;
    }
    else if(s[i] == '\0'){
      printf("NO\n");
      return 0;
    }
  
  return 0;
}
