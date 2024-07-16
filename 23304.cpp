//백준 23304 - 아카라카
#include <iostream>
#include <cstring>
using namespace std;

int recursion(const char *s, int l, int r){
  if(1 >= r) return 1;
  else if(s[l] != s[r]) {
    cout<<s[l]<<" "<<s[r];
    return 0;
  }
  else return recursion(s, l+1, r-1);
}

int isAkarakaPalindrome(const char *s){
  if (strlen(s) == 1) return 1; // 문자열의 길이가 1일 때
  else{
    int len = strlen(s) / 2;
    cout << len;

    if(strlen(s) % 2 == 0){ // 문자열 길이가 짝수인 경우
      return recursion(s, 0, len -1) && recursion(s, len, strlen(s) - 1);
    }
    else {  //문자열 길이가 홀수인 경우
      return recursion(s, 0, len -1) && recursion(s, len + 1, strlen(s) - 1);
    }
  }
}

int main(){
  string str;
  cin >> str;

  int isaP = isAkarakaPalindrome(str.c_str());

  if(isaP){
    cout << "AKARAKA" << " " << isaP;
  }
  else
    cout << "IPSELENTI"<< " " << isaP;

  return 0;
}