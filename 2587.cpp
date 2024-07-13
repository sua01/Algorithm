//백준 2587 - 대표값2
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
  int num[5];
  int sum = 0;

  for(int i = 0; i < 5; i++){
    cin >> num[i];
    sum += num[i];
  }

  sort(num, num + 5);

  cout << sum / 5 << endl;  // 평균 출력
  cout << num[2]; // 중앙값 출력

  return 0;
}