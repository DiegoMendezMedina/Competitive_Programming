#include <stdio.h>

/**
 * Helpful Maths
 * https://codeforces.com/problemset/problem/339/A
 */

void quicksort(int vector[],int inf, int sup);
void change(int vector[], int i, int j);

int main(){
  
  char s[100];
  int nums[55] = {0};
  int c = 0;
  scanf("%s", s);
  
  for(int i = 0; i < 100; i += 2){
    if(s[i] == '1' || s[i] == '2' || s[i] == '3'){
      nums[c] = s[i]-'0';
      c++;
    }
    else if(s[i] != '+')
      break;
  }

  quicksort(nums, 0, c-1);
  
  for(int i = 0; i < c; i++)
    if(i < c-1)
      printf("%d+", nums[i]);
    else
      printf("%d\n", nums[i]);

}

void change(int vector[], int i, int j){
  int aux;
  
  aux = vector[i];
  vector[i] = vector[j];
  vector[j] = aux;
  
}

void quicksort(int vector[], int inf, int sup){
  int i, j, x;
  
  i = inf;
  j = sup;
  x = vector[(i+j)/2];
  
  while(i <= j){ 
      while(vector[i] < x)    
	i++;
      while(vector[j] > x)  
	j--;
      if(i<=j){
	change(vector, i, j);
	i++;
	j--;
      }
  }
  
  if(inf < j)
    quicksort(vector, inf, j);
  if(i < sup)
    quicksort(vector, i, sup);
}
