//백준 7568 - 덩치

#include <iostream>
using namespace std;

int main(){
  int n;
  cin >> n; // 전체 사람 수 입력받기

  int x[50], y[50]; //몸무게, 키
  int grade[50] = {0};  //등수 0으로 초기화

  for(int i = 0; i < n; i++){
    cin >> x[i] >> y[i];  // 몸무게, 키 입력받기
  } 
  
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      if(x[i] < x[j] && y[i] < y[j]){ // 덩치가 큰 경우
        grade[i] += 1;
      }
    }
  }

  // 등수 출력
  for(int i = 0; i < n; i++)
    cout << grade[i] + 1 <<" ";

  return 0;
}