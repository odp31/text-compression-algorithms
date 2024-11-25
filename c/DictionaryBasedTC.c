#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CODE_LEN 16

typedef struct {
  char *str;
  int code;
} DictEntry;

int main()
{
  char *text = "ABACAABB";
  int dictSize = 256;
  DictEntry dict[65536];

  for(int i = 0; i < 256; i++) {
    dict[i].str = (char *)malloc(2);
    dict[i].str[0] = i;
    dict[i].str[1] = '\0';
    dict[i].code = i;
  }

  int i = 0, j = 0;
  while(i < strlen(text)) {
    char *p = dict[j].str;
    while(i < strlen(text) && *p == text[i]) {
      i++;
      p++;
    }
    if(*p == '\0') {
      printf("%d ", dict[j].code); // match found 
      j = 0;
    }
    else{
      // no match, add new string to dictionary 
      dict[dictSize].str = (char *)malloc(strlen(dict[j].str) + 2);
      strcpy(dict[dictSize].str, dict[j].str);
      dict[dictSize].str[strlen(dict[j].str)] = text[i];
      dict[dictSize].str[strlen(dict[j].str) + 1] = '\0';
      dict[dictSize].code = dictSize;
      j = 0;
    }
  }
// handle last character
printf("%d ", dict[j].code);
return 0;
}
