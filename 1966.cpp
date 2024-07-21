//백준 1966 - 프린터 큐
#include <cstdio>
#include <queue>
using namespace std;

int main(){
  int t;
  scanf("%d", &t);  // 테스트 개수 입력

  while(t--){
    // 문서 개수 n, 몇 번째로 인쇄되었는지 궁금한 문제가 현재 큐에서 몇 번째에 놓여 있는지 m
    int n, m, p;  // 우선순위 p
    scanf("%d %d", &n, &m);  

    queue<pair<int, int>> q;
    // 문서의 중요도 1이상 9이하
    for(int i = 0; i < n; i++){
      scanf("%d", &p);
      q.push({i, p});

    }

  }
  return 0;
}