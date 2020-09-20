char keywords[31][20] = {"zero", "one", "two", "three", "four", "five", "six",
                            "seven", "eight", "nine", "ten",
                            "eleven", "twelve", "thirteen", "fourteen", "fifteen",
                            "sixteen", "seventeen", "eighteen", "nineteen",
                            "twenty", "thirty", "forty", "fifty", "sixty", "seventy",
                            "eighty", "ninety", "hundred", "thousand", "million"};

int values[31] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14 , 15,
                          16, 17, 18, 19, 20, 30, 40, 50, 60, 70, 80, 90,
                          100, 1000, 1000000};

int getvalue (char key[]){
  int i;
  for(i = 0; i<31; i++){
    if(strcmp(key, keywords[i]) == 0){
      //printf("\n %s %d", key, values[i]);
      return values[i];
    }
  }
  return -1;
}


long parse_int (const char* number) {
  int sum=0;
  int index = 0;
  int lastnumber = 0;
  int lastnumbersum = 0;
  
  int currentnumber;
  char buffer[20];
  
  while(*number){
    // break operator and add to sum
    if((*number == ' ') || (*number == '-') ){

      buffer[index] = '\0';

      if(strcmp(buffer, "and") != 0){
        currentnumber = getvalue(buffer);
       
        if((sum<currentnumber) && (sum !=0)){
          sum += sum * currentnumber - sum;
          lastnumbersum = 0;
        } else if((lastnumbersum<currentnumber) && (lastnumbersum !=0)){
          sum += lastnumbersum * currentnumber - lastnumbersum;
          lastnumbersum = 0;
        } else {
          sum += currentnumber;
          lastnumbersum += currentnumber;
        }
        //printf("\n sum = %d, last= %d", sum, lastnumbersum);
      }
      index = 0;
    } else {
      buffer[index] = *number;
      index++;
    }
    *number++;
  }
  // Add last number
  buffer[index] = '\0';
  currentnumber = getvalue(buffer);
  if((sum<currentnumber) && (sum !=0)){
          sum += sum * currentnumber - sum;
  } else if((lastnumbersum<currentnumber) && (lastnumbersum !=0)){
          sum += lastnumbersum * currentnumber - lastnumbersum;
  } else {
          sum += currentnumber;
  }
  
  //printf("\n returned %d", sum);
  return sum;
}