/*
** @param str: a C-string containing only lowercase letters and spaces (' ')
** @return:    a C-string allocated on the heap containing the highest scoring word of str
*/
char  *highestScoringWord(const char *str)
{
  int score=-1;
  int index = 0;
  int newIndex = 0;
  int size=0;
  int currentScore=0;
  int currentSize=0;
  char *c = str;
  int count = 0;
  
  while(*c){
    if((*c == ' ')){
      if(currentScore>score){
        index = newIndex;
        score = currentScore;
        size = currentSize;
      }
      newIndex = count+1;
      currentScore = 0;
      currentSize = 0;
    } else {
      currentScore += (*c - 96);
      currentSize++;
    }
    count++;
    c += 1;
    if((currentScore>score) && (!*c)){
        index = newIndex;
        score = currentScore;
        size = currentSize;
    }
  }

  char * ans;
  ans = (char *) malloc(sizeof(char)*(size+1));
  count = 0;
  for(int i=index; i<(index+size); i++){
    *(ans + count) = str[i];
    count++;
  }
  *(ans+count) = '\0';
  return ans;
}