//백준 17952 - 과제는 끝나지 않아!
#include <cstdio>
#include <stack>
using namespace std;

int main() {
    int n;  // 이번 학기가 몇 분인지
    scanf("%d", &n);
    stack<int> score_stk, time_stk;

    // 과제 정보 입력
    int is, score, time;
    int score_sum = 0;
    while (n--) {
        scanf("%d", &is);  // 과제 여부 입력
        if (is == 1) {
            scanf("%d %d", &score, &time);
            score_stk.push(score);
            time_stk.push(time);
        } 

        // 매 분마다 현재 과제의 남은 시간을 줄임
        if (!time_stk.empty()) {
            int current_time = time_stk.top();
            time_stk.pop();
            current_time--;

            // 남은 시간이 0이면 과제를 완료하고 점수를 합산
            if (current_time == 0) {
                score_sum += score_stk.top();
                score_stk.pop();
            } else {
                time_stk.push(current_time);
            }
        }
    }

    // 받을 과제 점수 출력
    printf("%d\n", score_sum);
    return 0;
}
