#include <stdio.h>

int repetitions();

/**
 * Solution to the CSES "Repetition" problem
 * https://cses.fi/problemset/task/1069
 */
int main()
{  
  printf("%d\n", repetitions());
}

/**
 * repetitions: Reads from the console and solves the problem.
 * @return the length of the longest repetition
 */
int repetitions()
{
  char c, aux;
  int i, cont, max;
  
  i = max = cont = 1;
  while((c = getchar()) != EOF){
    if(i == 1){
      aux = c;
      i++;
    }
    else{
      if(aux == c){
	cont++;
	if(cont > max)
	  max = cont;
      }
      else{
	cont = 1;
	aux = c;
      }
    }
  }
  return max;
}
