//n is strarr size
char* longestConsec(char* strarr[], int n, int k) {
  
  if((n==0) || (k>n) || (k<=0)){
    char * error = calloc(1, sizeof(char));
    *error = '\0';
    return error;
  }
  
  int index=-1;
  int size=-1;
  int currentSize=0;
  
  // find largest possible string
  for(int i=0; i<n; i++){
    printf("\n %s", strarr[i]);
    currentSize = strlen(strarr[i]);
    for(int j = (i+1); j<(i+k); j++){
      if(j<n){
        currentSize += strlen(strarr[j]);
      }
    }
    if(currentSize > size){
      size = currentSize;
      index = i;
    }
  }

  // build final string
  char *ans;
  ans = (char *) calloc(size+1,sizeof(char));
  
  int counter = 0;
  for(int i = index; i<(index+k); i++){
    for(int j=0; j<strlen(strarr[i]); j++){
      *(ans+counter) = strarr[i][j];
      counter++;
    }
  }
  *(ans+counter) = '\0';
  return ans;
}