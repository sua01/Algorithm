//백준 4344 - 평균은 넘겠지
#include <iostream>
using namespace std;

int main(){
  int c, n;
  int sum, avg, num;

  cin >> c; //테스트 케이스 개수 입력받기

  int score[1000];
  for(int i = 0 ; i < c; i++){
    sum = 0, avg = 0, num = 0;

    cin >> n; // 학생 수 입력받기
    
    for (int i = 0; i < n; i++){
      cin >> score[i];  // 점수 입력받기
      sum += score[i];
    }
    avg = sum / n;  // 평균 구하기
    
    // 평균 넘는 학생 비율 구하기
    for (int i = 0; i < n; i++){
      if(score[i] > avg){
        num+=1;
      }
    }

    double result = (double)num / n * 100;
    //소수점 이하 3자리 출력하기
    cout << fixed;
    cout.precision(3);
    cout<< result << "%" << endl;
  }
  return 0;
}
