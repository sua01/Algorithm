//백준 10866 - 덱
#include <iostream>
#include <deque>
#include <string>
using namespace std;

int main(){
  int n;
  cin >> n;  // 명령어 개수 입력

  string cmd;
  deque<int> d; // 덱 생성

  while(n--){
    cin >> cmd; // 명령어 입력

    if(cmd == "push_front"){  
      int num;
      cin >> num;
      d.push_front(num);
    }
    else if(cmd == "push_back"){
      int num;
      cin >> num;
      d.push_back(num);
    }
    else if(cmd == "pop_front"){  
      if(d.empty()) 
        cout << "-1\n";
      else  {
        cout << d.front() << "\n";
        d.pop_front();
      }
    }
    else if(cmd == "pop_back"){
      if(d.empty()) // 들어있는 정수가 없는 경우
        cout << "-1\n";
      else  {
        cout << d.back() << "\n";
        d.pop_back();
      }
    }
    else if(cmd == "size"){ // 들어있는 정수 개수 출력
      cout << d.size() << "\n";
    }
    else if(cmd == "empty"){  // 비어있으면 1, 아니면 0
      if(d.empty()) cout << "1\n";
      else cout << "0\n";
    }
    else if(cmd == "front"){
      if(d.empty()) // 들어있는 정수가 없는 경우
        cout << "-1\n";
      else cout << d.front() << "\n";
    }
    else if(cmd == "back"){
      if(d.empty()) // 들어있는 정수가 없는 경우
        cout << "-1\n";
      else cout << d.back() << "\n";
    }
  }
  return 0;
}