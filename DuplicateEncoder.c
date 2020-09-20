#include <stdlib.h>
#include <string.h>


char *DuplicateEncoder(char *s)
{
  
  int len = strlen(s);
  char *store = (char *) malloc(sizeof(char)*(len+1));
  
  for(int i=0; i<len; i++){
    for(int k=0; k<len; k++){
      if((tolower(s[i]) == tolower(s[k])) && (k!=i)){   
        *(store+i) = ')';
        break;
      }
      *(store+i) = '(';
    }
  }
  *(store+len) = '\0';
  
  return store; 
}