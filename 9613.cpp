//백준 9613 - GCD 합
#include <cstdio>
#include <vector>
using namespace std;

// 최대공약수 구하기
int gcd(int a, int b){
  if(b == 0) return a;
  return gcd(b, a%b);
}

int main(){
  int t;
  scanf("%d", &t);  // 테스트 케이스 개수 입력

  while(t--){
    int n;
    scanf("%d", &n);

    vector<int> arr;
    int num;
    for(int i = 0; i < n; i++){ // 정수 입력
      scanf("%d", &num);
      arr.push_back(num);
    }

    long long sum = 0;  // 가능한 모든 쌍의 GCD 합 구하기
    for(int i = 0; i < n; i++){
      for(int j = i+1; j < n; j++){
        sum += gcd(arr[i], arr[j]);
      }
    }

    printf("%lld\n", sum);

  }

  return 0;
}