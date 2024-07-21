//백준 1158 - 요세푸스 문제
#include <cstdio>
#include <queue>
using namespace std;

int main(){
  int n, k;
  scanf("%d %d", &n, &k);
  queue<int> q; // 큐 생성

  for(int i = 1; i <= n; i++) // 큐에 정수 push
    q.push(i);
  
  // 요세푸스 순열 출력
  printf("<");
  while(!q.empty()){  // 큐가 empty일 때까지 반복
    for(int i = 0; i < k-1; i++){
      q.push(q.front());
      q.pop();
    }
    
    if(q.size() == 1){
      printf("%d>", q.front());
    }
    else {
      printf("%d, ", q.front());
    }
    q.pop();
  }
  
  return 0;
}