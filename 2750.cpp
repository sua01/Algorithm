#//백준 27501 - 수 정렬하기
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
  int n;
  cin >> n; // 입력받을 수 개수
  int* num = new int[n];
  for(int i = 0; i < n; i++){
    cin >> num[i];
  }

  sort(num, num + n);

  for(int i = 0; i < n; i++){
    cout << num[i] << '\n';
  }

  return 0;
}