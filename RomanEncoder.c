#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *solution(int n) {
  char roman[8] = {'M', 'D', 'C', 'L', 'X', 'V', 'I'};
  int dec[7] = {1000, 500, 100, 50, 10, 5, 1};
  char * encoded;
  encoded = (char *) malloc(sizeof(char)*255);
  
  int counter=0;
  int digit = n;
  int div = 1000;
  int rest;
  int mtp;
  
  while(n!=0){
    digit = n / div;
    rest = digit * div;

    if(digit!=0){
      for(int i = 0; i<7; i++){
        // nbr 9 and 4 fix
        if(rest == (dec[i]-div)){
            if(digit == 9){
              *(encoded+counter) = roman[i+2];
              counter++;
              *(encoded+counter) = roman[i];
              counter++;
              n-= (dec[i] - dec[i+2]);
            }
            if(digit == 4){
              *(encoded+counter) = roman[i+1];
              counter++;
              *(encoded+counter) = roman[i];
              counter++;
              n = n - (dec[i]-dec[i+1]);
            }
            break;
        }
        // adds maximum three of currrent roman
        mtp = rest / dec[i];
        if((mtp !=0) && (mtp <= 3 )){
          for(int k = 0; k<mtp; k++){
            *(encoded+counter) = roman[i];
            counter++;
            n-=dec[i];
          }
           break;
        }
      }
    }
    // should only decrease when rest is zero
    if( (div!=1) && (n<div)){
      div /= 10;
    }
    if(n < 0){
      n = 0;
    }
  }

  *(encoded+counter) = '\0';
  return encoded;
}