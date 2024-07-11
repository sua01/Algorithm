//백준 5597 - 과제 안 내신 분..?
#include <iostream>
using namespace std;

int main(){

  int arr[30] = {0};
  int num;

  for (int i = 0; i < 28;i++){  // 제출한 출석번호 1로 바꾸기
    cin >> num;
    num -=1;
    arr[num] = 1; 
  }

  for(int i = 0 ; i < 30;i++){
    if(arr[i] == 0)
      cout << i+1<<'\n';
  }
  
  return 0;
}