//백준 26152 - 플래피 버드 스코어링
#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
  int n;  // 장애물 개수 입력
  scanf("%d", &n);

  int* a = new int[n];  // 상단 장애물 위치 입력
  for(int i = 0; i < n; i++){
    scanf("%d", &a[i]);
  }
  
  int b;  // 하단 장애물 위치 입력
  int* dis = new int[n];  // 장애물 틈새
  for(int i = 0; i < n; i++){
    scanf("%d", &b);
    dis[i] = a[i] - b;
  }

  int q;  // 플래피 버드 개수
  scanf("%d", &q);

  int w;  // 플래피 버드 크기
  int* score = new int[q];  // 점수 저장
  
  for(int i = 0 ; i < q; i++){
    score[i] = 0;
    scanf("%d", &w);
    for(int j = 0; j < n; j++){
      if(w <= dis[j])  score[i]++;
      else break; 
    }
    
  }

  for(int i = 0 ; i < q; i++){  // 최대 게임 스코어 출력
    printf("%d\n", score[i]);
  }

  delete[] a;
  delete[] dis;
  return 0;
}