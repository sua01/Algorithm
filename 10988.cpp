//백준 10988 - 팰린드롬인지 확인하기
#include <iostream>
#include <cstring>
using namespace std;

int recursion(const char *s, int l, int r){
    if(l >= r) return 1;
    else if(s[l] != s[r]) return 0;
    else return recursion(s, l+1, r-1);
}

int isPalindrome(const char *s){
    return recursion(s, 0, strlen(s)-1);
}

int main(){
  string str;
  cin >> str; // 문자열 입력받기

  cout << isPalindrome(str.c_str());

  return 0;
}