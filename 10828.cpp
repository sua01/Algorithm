//백준 10828 - 스택
#include <stack>
#include <iostream>
#include <string>
using namespace std;

int main(){
  int n;
  cin >> n;  // 명령 수 입력

  stack<int> stk;

  string command;
  int num;

  while(n--){
    cin >> command;;
    
    if(command == "push"){  // 스택에 정수 넣기
      cin >> num;
      stk.push(num);
    }
    else if(command == "top"){  // 스택의 가장 위에 있는 정수 출력
      if(stk.empty()) // 스택에 들어있는 정수가 없는 경우
        cout << "-1\n";
      else
        cout << stk.top() << "\n";
    }
    else if(command == "size"){ // 스택에 들어있는 정수 개수 출력
      cout << stk.size() << "\n";
    }
    else if(command == "empty"){  // 스택 비어있으면 1, 아니면 0
      if(stk.empty()) cout << "1\n";
      else cout << "0\n";
    }
    else if(command == "pop"){  // 스택에서 가장 위에 있는 정수 빼고 출력
      if(stk.empty()) // 스택에 들어있는 정수가 없는 경우
        cout << "-1\n";
      else  {
        cout << stk.top() << "\n";
        stk.pop();
      }
    }
  }

  return 0;
}