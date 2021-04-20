#include <stdio.h>

/**
 * ABC_String.
 * https://codeforces.com/contest/1494/problem/A
 */

int s_length(char s[]);
int solution(char s[], int length);
int int_array(int arr[], int length, int check);
void change_arr(int arr[], int arr2[], int length, int val);
int regular_sequence(int arr[], int length);
void delete(int arr[], int i, int length);

int main(){
  int t, r;
  char a[50];
  
  scanf("%d", &t);

  for(int cont = 0; cont < t; cont ++){
    scanf("%s", a);
    r = solution(a, s_length(a));
    if(r == 1)
      printf("YES\n");
    else
      printf("NO\n");
  }
}

/**
 * s_length, returns the length of the string received.
 * @param char s[], String.
 * @return  int, length of the string received.
 */
int s_length(char s[]){
  int i;
  
  for(i = 0; i < 51; i++)
    if(s[i] == '\0')
      return i;
}

/**
 * solution: Functions that tells if the string received is a regular bracket
 *           sequence.
 * @param s, char[]. String to tell if is a regular bracket sequence.
 * @param length, int. Length of the string.
 * @return 1 if s is a regular bracket sequence, 0 otherwise.
 */
int solution(char s[], int length){
  int arr[length];
  int check = 0;
  
  if(s[0] == s[length-1])
    return -1;
  
  for(int i = 0; i < length; i++)
    if(s[i] == s[0])
      arr[i] = 1;
    else if(s[i] == s[length-1])
      arr[i] = 0;
    else{
      arr[i] = -1;
      check = 1;
    }
  return int_array(arr, length, check);
}

/**
 * int_array: Matches the possible elements of the third letter and tells if 
 *            the array received is a regular_sequence.
 * @param arr, int[]. int array that represent the string with 1's and 0's.
 * @param length, int. length of the string.
 * @param check, int. 1 if the String has three letters. 0 otherwise.
 * @return 1 if arr is a regular sequence, 0 in other case.
 */
int int_array(int arr[], int length, int check){
  int arr2[length];
  int r;
  
  if(check == 1){
    change_arr(arr, arr2, length, 0);
    r = regular_sequence(arr2, length);
    if(r == 1)
      return 1;
    else{
      change_arr(arr, arr2, length, 1);
      return regular_sequence(arr2, length);
    }
  }
  else
    return regular_sequence(arr, length);
}

/**
 * change_arr: Copies arr on arr2 but changes all the elements on the array 
 *    received that have -1 as value with the last int received.
 * @param arr, int[]. int array where the elements except the minus one 
 *                    will be copied.
 * @param arr2, int[]. int array where the elements will be stored.
 * @param length, int. Length of both arrays.
 * @param val, int. Value wich the minus one will be replaced.
 */
void change_arr(int arr[], int arr2[], int length, int val){
  for(int i = 0; i < length; i++)
    if(arr[i] == -1)
      arr2[i] = val;
    else
      arr2[i] = arr[i];
}

/**
 * regular_sequence: Recursive function to checj if arr is a regular 
 *                   bracket sequence.
 * @param arr, int[]. Representation of a String with 1 and 0.
 * @param length, int. Not always the length of the array, just the intrested
 *                     length.
 * @return 1 if arr is a regular bracket sequence.
 *        -1 in other case.
 */
int regular_sequence(int arr[], int length){
  int i, aux;
  aux = 0;

  // base case.
  if(length == 0)
    return 1;

  // first criteria to tell if arr is not a regular sequence.
  if(arr[0] == 0)
    return -1;
  
  for(i = 0; i < length-1; i++){
    int j = i+1;
    if(arr[i] == 1 && arr[j] == 0){
      delete(arr, i, length);
      aux = 1; // So far arr is a regular sequence.
      break;
    }	     
  }

  // second criteria to tell if arr is not a regular sequence.
  if(aux == 0)
    return -1;
  
  // Recursion.
  return regular_sequence(arr, length-2);
}

/**
 * delete: removes the i-th and i+1-th element on the array received.
 * @param arr[], int. 
 * @param i, int. index of the element we want to replace.
 * @param length, int. Not always the lenght of the string, just the intrested 
 *                     length.
 */
void delete(int arr[], int i, int length){
  int j;
  
  for(j = i; j < length-2; j++)
    arr[j] = arr[j+2];
  arr[j+1] = -1;
  arr[j+2] = -1;
}
