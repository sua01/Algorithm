//백준 7795 - 먹을 것인가 먹힐 것인가
#include <cstdio>

int main(){
  int t, n, m;  // 테스트 개수 t, A의 수 n, B의 수 m
  scanf("%d", &t);

  int i = 0;
  while(i < t){
    scanf("%d", &n);
    scanf("%d", &m);

    int* a = new int[n];
    for(int j = 0; j < n; j++){
      scanf("%d", &a[j]);
    }

    int b, val = 0;

    for(int k = 0; k < m; k++){
      scanf("%d", &b);
      for(int j = 0; j < n; j++){
        if(b < a[j])  val++;
      }
    }
    printf("%d\n", val);
    i++;
    
    delete[] a;
  }
  
  return 0;
}