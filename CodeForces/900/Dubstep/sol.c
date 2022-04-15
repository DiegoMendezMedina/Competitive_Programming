#include <stdio.h>

/**
 * Dubstep
 * https://codeforces.com/problemset/problem/208/A
 */

int get_values(int *w, char *s)
{
  int i;
  for(i = 0; i <= 201; i++)
    if(s[i] == 'W' && s[i+1] == 'U'
       && s[i+2] == 'B'){
      w[i] = -1;
      w[i+1] = -2;
      w[i+2] = -2;
      i += 2;
    }
    else if(s[i] == '\0'){
      w[i] = 3;
      return i;
    }
    else
      w[i] = 1;
}

void del_spaces(int *w, char *s, int length)
{
  int i;

  for(i = 0; i < length; i++)
    if(w[i++] == -2)
      while(w[i] < 0)
	w[i++] = -2;	    
}

int main()
{
  int i, length, w[201]={0};
  char s[201];
  
  scanf("%s", s);
  
  length = get_values(w, s);
  del_spaces(w, s, length);

  i = 0;
  while(w[i] < 0)
    i++;
  
  
  for(; i <= length; i++){
    if(w[i] == 3){
      printf("\n");
      return 0;
    }
    else if(w[i]== -1)
      printf(" ");
    else if(w[i]>0)
      printf("%c", s[i]);
  }
  return 0;
}
