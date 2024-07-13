//백준 16466 - 콘서트
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
  int n;
  cin >> n; // 1차 티켓팅에서 팔린 티켓 수
  
  // 1차 티켓팅에서 팔린 티켓 번호 입력받기
  int* num = new int[n];
  for(int i = 0; i < n; i++){
    cin >> num[i];
  }

  sort(num, num + n); //오름차순 정렬

  // 2차 티켓팅
  int min = 1;
  for(int i = 0; i < n; i++){
    if(min == num[i]){
      min++;
      
    }
    else{
      min++;
    }
  }

  cout << min++;

  delete[] num;
  return 0;
}