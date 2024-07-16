//백준 23304 - 아카라카
#include <iostream>
#include <cstring>
using namespace std;

int recursion(const char *s, int l, int r){
  if(1 >= r) return 1;
  else if(s[l] != s[r]) return 0;
  else return recursion(s, l+1, r-1);
}

int isPalindrome(const char *s){
  if (strlen(s) == 1) return 1; // 문자열의 길이가 1일 때 아카라카 팰린드롬
  else return recursion(s, 0, strlen(s)-1);
}

int isAkarakaPalindrome(const char *s){
  int len = strlen(s) / 2;
  cout << len;
  return recursion(s, 0, len -1) && recursion(s, len + 1, strlen(s) - 1);
}

int main(){
  string str;
  cin >> str;

  int isP = isPalindrome(str.c_str());
  int isaP = isAkarakaPalindrome(str.c_str());

  if(isP && isaP){
    cout << "AKARAKA" << isP <<" " << isaP;
  }
  else
    cout << "IPSELENTI"<< isP <<" " << isaP;

  return 0;
}