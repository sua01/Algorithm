//백준 10871 - x보다 작은 수
#include <iostream>
using namespace std;

int main(){
  int n, x;
  cin >> n >> x;

  int arr[10000];
  for(int i = 0; i < n ; i++){
    cin >> arr[i]; 
  }

  for (int i = 0; i < n; i++){
    if(arr[i] < x){
      cout << arr[i] << " ";
    }
  }
  cin.get(); // 이전 입력의 남은 개행 문자를 읽음
  cin.get(); // 실제 대기
  return 0;
}