#include <inttypes.h>

void uint32_to_ip(uint32_t ip, char *output)
{
  /* you dont need to allocate memory, use 'output' */
  uint32_t binary=0;
  int i;
  int index=0;
  
  uint32_t arr[4] = {0,0,0,0};
  for(i=0; ip>0; i++){
   binary |= ((ip%2) << i);
   ip = ip/2;
   if((i%7==0) && (i>0)){
     arr[index] = binary;
     binary = 0;
     index++;
     i=-1;
   }
  }
  arr[index] = binary;
  //printf("\n %d.%d.%d.%d", arr[3], arr[2], arr[1], arr[0]);
  sprintf(output, "%d.%d.%d.%d", arr[3], arr[2], arr[1], arr[0]);
}