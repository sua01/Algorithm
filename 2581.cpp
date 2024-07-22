//백준 2581 - 소수
#include <cstdio>
#include <vector>
#include <algorithm>
#include <numeric>  //accumulate 함수 사용
#include <cmath>    // sqrt 함수 사용

using namespace std;

bool isPrime(int num) {
    if (num < 2) return false;
    for (int j = 2; j <= sqrt(num); j++) {
        if (num % j == 0) return false;
    }
    return true;
}

int main() {
    int m, n; 
    scanf("%d", &m);
    scanf("%d", &n);

    // m 이상 n 이하의 자연수 중 소수 찾기
    vector<int> prime;
    for (int i = m; i <= n; i++) {
        if (isPrime(i)) {
            prime.push_back(i);
        }
    }

    if (prime.empty()) {
        printf("-1\n");
    } else {
        // 소수의 합 출력
        int sum = accumulate(prime.begin(), prime.end(), 0);
        printf("%d\n", sum);
        // 소수 중 최솟값 출력
        printf("%d\n", prime[0]);
    }

    return 0;
}
