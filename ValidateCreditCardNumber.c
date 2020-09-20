#include <stdbool.h>

bool validate(long digits) {
    int arr[16] = {0};
    int i = 15;
    while(digits!=0){
      arr[i] = digits % 10;
      digits /=10;
      i--;
    }
    int sum=0;
    int doubletime=0;

    for(int k=15; k>i; k--){
      // stp 1, double time
      if(doubletime){
        arr[k] *= 2;
        if(arr[k] > 9){
          arr[k] -= 9;
        }
        doubletime = 0;
      } else {
        doubletime = 1;
      }
      sum+=arr[k];
    }
    if((sum % 10) == 0){
      return 1;
    }
    return 0;
}