//백준 25501 - 재귀의 귀재
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int cnt;  // 재귀 함수 호출 횟수
int recursion(const char *s, int l, int r){
    cnt++;
    if(l >= r) return 1;
    else if(s[l] != s[r]) return 0;
    else return recursion(s, l+1, r-1);
}

int isPalindrome(const char *s){
    return recursion(s, 0, strlen(s)-1);
}

int main(){
  int t;
  scanf("%d", &t);  // 테스트 케이스 개수

  string str;
  for(int i = 0; i < t; i++){
    cin >> str;
    // isPalindrome 반환값, 재귀 함수 호출 쵯수 출력
    cnt = 0;
    int val = isPalindrome(str.c_str());
    printf("%d %d\n", val, cnt); 
  }
  return 0;
}