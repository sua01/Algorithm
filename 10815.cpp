#//백준 10815 - 숫자 카드
#include <iostream>
using namespace std;

/* 시간 초과 코드
int main(){
  int n, m;
  
  // 상근이가 가지고 있는 숫자 카드 입력
  cin >> n;
  int* have = new int[n];
  for(int i = 0; i < n; i++){
    cin >> have[i];
  }

  // 비교할 카드 입력
  cin >> m;
  int* cards = new int[m];
  int i;
  for(i = 0; i < m; i++){
    cin >> cards[i];

    for(int j = 0; j < n; j++){
      if(have[j] == cards[i]){
        cards[i] = 1;
        break;
      }
      if(j == n-1) cards[i] = 0;
    }
  }

  // 결과 출력
  for(int i = 0; i < m; i++){
    cout << cards[i] << " ";
  }

  return 0;
}*/

#include <algorithm>
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m, num;
  
  // 상근이가 가지고 있는 숫자 카드 입력
  cin >> n;
  int* have = new int[n];
  for(int i = 0; i < n; i++){
    cin >> have[i];
  }

  sort(have, have + n); // 정렬

  // 이진 탐색
  cin >> m;
  for(int i = 0; i < m; i++){
    cin >> num;

    cout << binary_search(have, have+n, num) << " ";
  }
  
  delete[] have;
  return 0;
}