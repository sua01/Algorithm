//백준 5430 - AC
#include <string>
#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t, n;
    string p, arr;

    cin >> t;  // 테스트 케이스 입력

    while (t--) {
        cin >> p; // 수행할 함수 p
        cin >> n; // 배열에 들어갈 수의 개수 n
        cin >> arr; // 배열에 들어있는 정수 입력
        deque<int> arr_num;
        string s = "";

        // 입력한 값 중 정수만 받기
        for (int i = 0; i < arr.length(); i++) {
            if (isdigit(arr[i])) {
                s += arr[i];
            } else {
                if (!s.empty()) {
                    arr_num.push_back(atoi(s.c_str()));
                    s = "";
                }
            }
        }

        bool reverse_flag = false;
        bool error_flag = false;

        // 명령어 수행
        for (int i = 0; i < p.length(); i++) {
            if (p[i] == 'R') {
                reverse_flag = !reverse_flag; // reverse 플래그 토글
            } else if (p[i] == 'D') {
                if (arr_num.empty()) {
                    error_flag = true; // 에러 발생한 경우
                    break;
                }
                if (reverse_flag) {
                    arr_num.pop_back(); // 역순일 경우 뒤에서 삭제
                } else {
                    arr_num.pop_front(); // 순차일 경우 앞에서 삭제
                }
            }
        }

        // 결과 출력
        if (error_flag) {
            cout << "error\n";
        } else {
            cout << "[";
            while (!arr_num.empty()) {
                if (reverse_flag) {
                    cout << arr_num.back();
                    arr_num.pop_back();
                } else {
                    cout << arr_num.front();
                    arr_num.pop_front();
                }
                if (!arr_num.empty()) {
                    cout << ",";
                }
            }
            cout << "]\n";
        }
    }

    return 0;
}
