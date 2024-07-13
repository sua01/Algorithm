//백준 16466 - 콘서트
#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
  int n;
  scanf("%d", &n); // 1차 티켓팅에서 팔린 티켓 수
  
  // 1차 티켓팅에서 팔린 티켓 번호 입력받기
  int* num = new int[n];
  for(int i = 0; i < n; i++){
    scanf("%d", &num[i]);
  }

  sort(num, num + n); //오름차순 정렬

  // 2차 티켓팅
  int val = 1;
  for(int i = 0; i < n; i++){
    if (val != num[i]) break; // 제일 작은 숫자

    val++;
  }

  printf("%d", val);

  delete[] num;
  return 0;
}