//백준 10818 - 최소, 최대
#include <iostream>
using namespace std;

int main(){
  int n;
  cin >> n;

  int result;
  int min = 1000000, max = -1000000;
  for(int i = 0; i < n; i++){
    cin >> result;
    if (result < min) min = result;
    if (result > max) max = result;
  }

  cout <<min << " " << max;
  cin.get(); // 이전 입력의 남은 개행 문자를 읽음
  cin.get(); // 실제 대기

  return 0;
}