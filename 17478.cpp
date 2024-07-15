//백준 17478 - 재귀함수가 뭔가요?
#include <cstdio>
#include <string>
using namespace std;

void recur(int n, string str){
  printf("%s\"재귀함수가 뭔가요?\"\n", str.c_str());

  if(n == 0){
    printf("%s\"재귀함수는 자기 자신을 호출하는 함수라네\"\n", str.c_str());
    printf("%s라고 답변하였지.\n", str.c_str());
    return;
  }
  else{
    printf("%s\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어.\n", str.c_str());
    printf("%s마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지.\n", str.c_str());
    printf("%s그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\"\n", str.c_str());
  }

  recur(n-1, str + "____");
  printf("%s라고 답변하였지.\n", str.c_str());
}

int main(){
  int n;  // 출력을 원하는 재귀 횟수
  scanf("%d", &n);

  printf("어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다.\n");
  recur(n, "");
  return 0;
}