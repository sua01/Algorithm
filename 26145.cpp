//백준 26145 - 출제비 재분재
#include <iostream>
#include <cstdio>
using namespace std;

int main(){
  int n, m;
  scanf("%d %d", &n, &m); // 출제자, 검수자 수 입력

  int* money = new int[n];  // 출제가 받은 출제비 입력
  for(int i = 0; i < n; i++)
    scanf("%d", &money[i]);

  delete[] money;
  return 0;
}
