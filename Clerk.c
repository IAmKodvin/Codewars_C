#include <stdlib.h>

//not very neat..
int tickets(size_t length, const int people[length]) {
  
  int balance[3] = {0};
  int change=0;
  
  for(size_t i=0; i<length; i++){
    
    change = people[i] - 25;
      
    if(people[i]==100){
      balance[2]+=100;
    } else if(people[i]==50){
      balance[1]+=50;
    } else {
      balance[0]+=25;
    }
    
    if((change/50 > 0) && (balance[1] >=50) ){
      balance[1] -= 50;
      change -= 50;
    }
        
    if((change/25 > 0) && (balance[0] >=change)){
      balance[0] -= change;
      change -= change;
    } 
        
    if (change!=0){
      return 0;
    }
  }
    
  return 1;
}