//백준 24460 - 특별상이라도 받고 싶어
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> chair;

int getNum(int x, int y, int n){
  int val[4];

  if(n == 1){
    return chair[x][y];
  }
  val[0] = getNum(x, y, n/2); 
  val[1] = getNum(x + n/2, y, n/2);
  val[2] = getNum(x, y+ n/2, n/2);
  val[3] = getNum(x + n/2, y + n/2, n/2);

  sort(val, val+4); // 오름차순으로 정렬
  return val[1];  // 2번째로 작은 값 반환
}

int main(){
  int n;
  scanf("%d", &n);

  // 추첨번호 입력받기
  chair.resize(n, vector<int>(n)); // 2차원 벡터 n*n 초기화
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      scanf("%d", &chair[i][j]);
    }
  }

  // 결과 출력
  printf("%d", getNum(0,0,n));
  return 0;
}