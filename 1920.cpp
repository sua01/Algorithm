//백준 1920 - 수 찾기
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n; // 자연수 개수 입력받기

  int* num = new int[n];
  for(int i = 0; i < n; i++)
    cin >> num[i];

  sort(num, num + n);
  
  int m, find;
  cin >> m;
  for(int i = 0; i < m; i++){
    cin >> find;
    cout << binary_search(num, num+n, find) << '\n';
  }

  delete[] num;

  return 0;
}