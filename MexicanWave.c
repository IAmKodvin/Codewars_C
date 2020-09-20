void wave(char *y, char **target)
{
  int count = 0;
  for(int i = 0; i<strlen(y); i++){
    if(y[i] != ' '){
      target[count] = strcpy(target[count], y);
      *(target[count]+i) = toupper(y[i]);
      count++;
    }
  }
  
}