//백준 26145 - 출제비 재분재
#include <iostream>
#include <cstdio>
using namespace std;

int main(){
  int n, m;
  scanf("%d %d", &n, &m); // 출제자, 검수자 수 입력

  int* money = new int[n+m];  // 출제가 받은 출제비 입력
  for(int i = 0; i < n; i++)
    scanf("%d", &money[i]);

  int share, sum;  // 나눠주기로 한 돈
  for(int i = 0; i < n; i++){
    sum = 0;
    for(int j = 0; j < n+m; j++){
      scanf("%d", &share);
      money[j] += share;
      sum += share;
    }
    money[i] -= sum;
  }
  
  for(int i = 0; i < n+m; i++)
    printf("%d ", money[i]);

  delete[] money;
  return 0;
}
