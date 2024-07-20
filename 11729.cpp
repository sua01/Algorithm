//백준 11729 - 하노이 탑 이동 순서

#include <cstdio>
using namespace std;

// 원판 이동 횟수 cnt 반환
int hanoi_tower(int n, int from, int tmp, int to){
  int cnt = 0;
  if(n == 1){
    cnt++;
  }
  else{
    cnt = hanoi_tower(n-1, from, to, tmp);
    cnt++;
    cnt = cnt + hanoi_tower(n-1, tmp, from, to);
  }
  return cnt;
}

// 원판 이동 과정 출력
void hanoi_tower_print(int n, int from, int tmp, int to){
  if(n == 1){
    printf("%d %d\n", from, to);
  }
  else{
    hanoi_tower_print(n-1, from, to, tmp);
    printf("%d %d\n", from, to);
    hanoi_tower_print(n-1, tmp, from, to);
  }
}

int main(){
  int n;  // 첫 번째 장대에 쌓인 원판의 개수
  scanf("%d", &n);

  // 옮긴 횟수 출력
  printf("%d\n", hanoi_tower(n, 1,2,3));
  // 수행 과정 출력
  hanoi_tower_print(n, 1, 2, 3);
  return 0;
}