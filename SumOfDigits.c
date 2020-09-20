int digital_root(int n) {
  int mod = 10;
  int sum = 0;
  int digit;
  while(n>0){
     digit = n % mod;
     sum+=digit;
     n -= digit;
     n /= mod;
  }
  if(!(sum<10)){
    sum = digital_root(sum);
  }
  return sum;
}