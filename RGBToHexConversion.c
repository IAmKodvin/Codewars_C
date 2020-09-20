char toHex(int c){
  c = c % 16;
  if(c>9){
    return (char) (65 + c % 10);
  } else {
    return (char) 48 + c;
  }
}

int rgb(int r, int g, int b, char *output)
{
   // Hex = 1..9 A B C D E F G
   int color[6] = {r, 0, g, 0, b, 0};
   for(int i = 0; i<6; i+=2){
     if(color[i]>255){
       color[i] = 255;
     }
     if(color[i]<0){
       color[i] = 0;
     }
     *(output+i) = (char) toHex(color[i]/16);
     *(output+i+1) = (char) toHex(color[i]);
   }
   printf("\nans=%s", output);
   return 0;
}