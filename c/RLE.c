#include <stdio.h>
#include <string.h>

void compress(char *input)
{
  int count = 1; 
  for (int i = 1; i <= strlen(input); i++) {
    if(input[i] == input[i-1]) {
      count++;
    }else {
      printf("%d%c", count, input[i-1]);
      count = 1;
    }
  }
}

int main() {
  char input[] = "AAABCCDEEE";
  compress(input);
  return 0;
}
