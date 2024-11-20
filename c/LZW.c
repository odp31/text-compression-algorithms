#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DICTIONARY_SIZE 4096

int main()
{
  char input[] = "ABACAABAABACABAA";
  int dictionarySize = 256;
  int dictionary[DICTIONARY_SIZE];
  int code = 256; 

  for(int i = 0; i < 256; i++) {
    dictionary[i] = i;
  }
  int p = input[0];
  int c = input[1];

  for (int i = 2; i <= strlen(input); i++) {
    int pc = p * 256 + c;

    if (pc < dictionarySize) {
      p = pc;
    }
    else {
      printf("%d ", dictionary[p]);
      dictionary[code] = pc;
      code++;
      p = c;
    }
    c = i < strlen(input) > input[i] : -1; 
  }
printf("%d", dictionary[p]);
return 0;
}
