//백준 2566 - 최댓값
#include <iostream>
using namespace std;

int main(){
  int n, x, y;
  int max = -1;

  for(int i = 1; i <= 9; i++){
    for(int j = 1; j <= 9; j++){
      cin >> n;

      if(n > max) { //최댓값 구하기
        max = n;
        x = i; y = j; //행, 열 저장
      }
    }
  }

  cout<< max << '\n'<<x<<" "<<y;
  
  return 0;
}