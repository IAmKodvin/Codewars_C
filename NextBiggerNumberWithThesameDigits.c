#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int compare (const void * a, const void * b)
{
  return ( *(int*)b - *(int*)a );
}

long long next_bigger_number(long long n) {
    long long digits[255] = {0};
    int i = 0;
    int tmp = 0;
    int done = 0;
    long long nextBig = 10;
    int nextBigIndex = -1;

    // store digits in array
    while(n>0){
      digits[i] = n%10;
      printf("\n%lld,%lld", digits[i],n);
      n/=10;
      i++;
    }

    for(int k = 1; k<i; k++){
      // swappable case
      if(digits[k] < digits[k-1]){
        // next biggest
        for(int j = 0; j<k; j++){
          if((digits[j]>digits[k]) && (digits[j] <= nextBig)){
            nextBig = digits[j];
            nextBigIndex = j;            
          }
        }
        // swap with next biggest
        tmp = digits[k];
        digits[k] = nextBig;
        digits[nextBigIndex] = tmp;
        // sort rest of array
        qsort(digits, k, sizeof(long long), compare);
        done = 1;
        break;
      }
    }

    if(done==0){
      return -1;
    }
    for(int k = 0; k<i; k++){
      n+= digits[k]*powl(10, k);
    }
    printf("\n solution %lld", n);
    return n;
}