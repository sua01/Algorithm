//백준 5576 - 콘테스트
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
  int score_w[10], score_k[10];

  for(int i = 0; i < 20; i++){
    if(i <10) cin >> score_w[i];
    else cin >> score_k[i-10];
  }

  sort(score_w, score_w + 10, greater<int>());
  sort(score_k, score_k + 10, greater<int>());

  cout << score_w[0] + score_w[1] + score_w[2] << " ";
  cout << score_k[0] + score_k[1] + score_k[2];

  return 0;
}
