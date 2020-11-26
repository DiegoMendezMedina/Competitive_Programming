#include <stdio.h>

/**
 * Array Rearrangment
 * https://codeforces.com/contest/1445/problem/A
 * 
 */

int canwe(int a[], int b[], int n, int x);
void change(int vector[],int i, int j);
void quicksort(int vector[],int inf, int sup);
void quicksortdecreasing(int vector[],int inf, int sup); 

int main(){
  int t;
  
  scanf("%d", &t);
  if(t < 1 || t > 100)
    return 0;
  
  for(int cont = 1; cont <= t; cont++){
    int n, x;
    scanf("%d", &n);
    scanf("%d", &x);
    
    if(n < 1 || n > 50 || x < 1 || x > 1000)
      return 0;
    
    int a[n];
    int b[n];
   
    for(int i = 0; i < n; i++)
      scanf("%d", &a[i]);
    for(int i = 0; i < n; i++)
      scanf("%d", &b[i]);
    
    quicksort(b, 0, n-1);
    quicksortdecreasing(b, 0, n-1);
    
    int r = canwe(a,b,n,x);
    if(r == 0)
      printf("No\n");
    else printf("Yes\n");
    
  }
  return 0;
}

int canwe(int a[], int b[], int n, int x){
  for(int i = 0; i < n; i++){
    if(i == 0)
      if(a[i]+b[i] > x)
	if(i+1<n)
	  if(a[i] + b[i+1] <= x && a[i+1] + b[i] <= x)
	    change(b, i, i+1);
	  else
	    return 0;
	else
	  return 0;
    
    if(i > 0)
      if(a[i] + b[i] > x)
	if(a[i] + b[i-1] <= x && a[i-1] + b[i] <= x)
	  change(b, i, i-1);
	else return 0;
  }
  return 1;
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

void quicksortdecreasing(int vector[], int inf, int sup){
  int i, j, x;
  
  i=inf;
  j=sup;
  x=vector[(i+j)/2];
  
  while(i <= j){ 
    while(vector[i] > x)
      i++;
    while(vector[j] < x)
      j--;
    if(i<=j){
      change(vector, i, j);
      i++;
      j--;
    }
  }
  
  if(inf>j)
    quicksort(vector, inf, j);
  
  if(i>sup)
    quicksort(vector, i, sup);
}
