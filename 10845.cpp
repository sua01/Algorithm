//백준 10845 - 큐
#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main(){
  int n;
  cin >> n;  // 명령어 개수 입력

  string cmd;
  queue<int> q; // 큐 생성

  while(n--){
    cin >> cmd; // 명령어 입력

    if(cmd == "push"){  
      int num;
      cin >> num;
      q.push(num);
    }
    else if(cmd == "pop"){  
      if(q.empty()) 
        cout << "-1\n";
      else  {
        cout << q.front() << "\n";
        q.pop();
      }
    }
    else if(cmd == "size"){ // 들어있는 정수 개수 출력
      cout << q.size() << "\n";
    }
    else if(cmd == "empty"){  // 비어있으면 1, 아니면 0
      if(q.empty()) cout << "1\n";
      else cout << "0\n";
    }
    else if(cmd == "front"){
      if(q.empty()) // 들어있는 정수가 없는 경우
        cout << "-1\n";
      else cout << q.front() << "\n";
    }
    else if(cmd == "back"){
      if(q.empty()) // 들어있는 정수가 없는 경우
        cout << "-1\n";
      else cout << q.back() << "\n";
    }
  }
  return 0;
}