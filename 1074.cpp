//백준 1074 - Z
#include <cstdio>
#include <vector>
using namespace std;

int r, c;

// r행 c열을 몇 번째로 방문했는지 출력
int visit(int n, int x, int y){
  int cnt = 0;
  
  if(x == r && y == c){ // r행 c열을 방문했을 경우
    return cnt;
  }
  else{
    cnt++;
    visit(n/2, x, y);
    visit(n/2, x+n/2, y);
    visit(n/2, x, y+n/2);
    visit(n/2, x+n/2, y+n/2);
  }
  return -1;
}

int main(){
  int n;
  scanf("%d %d %d", &n, &r, &c);

  // r행 c열을 몇 번째로 방문했는지 출력
  printf("%d", visit(1<<n, 0, 0));
  return 0;
}