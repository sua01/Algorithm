#//백준 10815 - 숫자 카드
#include <iostream>
using namespace std;

int main(){
  int n, m, have[5000000], cards[500000];

  // 상근이가 가지고 있는 숫자 카드 입력
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> have[i];
  }

  // 비교할 카드 입력
  cin >> m;
  int i;
  for(i = 0; i < m; i++){
    cin >> cards[i];

    for(int j = 0; j < n; j++){
      if(have[j] == cards[i])
        cards[i] = 1;
      else {
        if(j == n-1)  cards[i] = 0;
      }
    }
  }

  // 결과 출력
  for(int i = 0; i < m; i++){
    cout << cards[i] << " ";
  }

  return 0;
}