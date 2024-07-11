//백준 8958 - OX퀴즈
#include <iostream>
using namespace std;

int main(){
  int n, sum, flag;
  cin >> n; // 테스트 케이스 개수 입력받기
  string ox;

  for(int i = 0; i < n; i++){
    cin >> ox;  //ox 입력받기
    sum = 0;
    flag = 0;

    for(int i = 0; i < ox.length(); i++){
      if(ox[i] == 'O'){ //O인 경우
        if(flag){ //O가 연속된 경우
          flag +=1;
          sum+=flag;
        }
        else{ 
          flag = 1;
          sum+=1;
        }
      }
      else  flag = 0; //X인 경우
    }

    cout << sum << endl;
  }
  return 0;
}