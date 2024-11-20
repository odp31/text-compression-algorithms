#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(char *x, char*y)
{
  char t = *x; 
  *x = *y;
  *y = t;
}

void bubbleSort(char arr[], int n)
{
  int i, j;
  for(i = 0; i < n - 1; i++)
    for(j = 0; j < n - i - 1; j++)
      if(strcmp(&arr[j], &arr[j+1]) > 0)
        swap(&arr[j][0], &arr[j+1][0]);
}

void BWT(char *text)
{
  int n = strlen(text);
  char *suffixArray[n];

  //create suffix array
  for(int i = 0; i < n; i++) {
    suffixArray[i] = (char *)malloc(n+1);
    strcpy(suffixArray[i], text + i);
    strcat(suffixArray[i], text);
  }

  // sort suffix array
  bubbleSort(suffixArray, n);

  // extract last character of each suffix 
  printf("transformed text: ");
  for(int i = 0; i < n; i++) {
    printf("%c", suffixArray[i][n-1]);
  }
  printf("\n");

  // free memory
  for (int i = 0; i < n; i++) {
    free(suffixArray[i[);
  }
}
int main()
{
  char text[] = "banana";
  BWT(text);
  return 0;
}
