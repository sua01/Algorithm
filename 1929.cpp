//백준 1929 - 소수 구하기
#include <cstdio>
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
    scanf("%d %d", &m, &n);

    // m 이상 n 이하의 자연수 중 소수 출력
    for (int i = m; i <= n; i++) {
        if (isPrime(i)) {
            printf("%d\n", i);
        }
    }
    return 0;
}
