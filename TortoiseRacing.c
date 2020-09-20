int* race(int v1, int v2, int g) {
    int * ans;
    ans = malloc(sizeof(int)*3);
    if(v2<v1){
      ans[0] = -1;
      ans[1] = -1;
      ans[2] = -1;
      return ans;
    } else {
      ans[0] = g/(v2-v1);
      ans[1] = g*60/(v2-v1)-ans[0]*60;
      ans[2] = g*3600/(v2-v1)-ans[0]*3600-ans[1]*60;
      return ans;
    }

}