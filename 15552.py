#백준 15552 - 빠른 A+B
#input 대신 sys.stdin.readline 사용하기
import sys
t = int(input())

for i in range(t):
  a, b = map(int, sys.stdin.readline().split())
  print(a+b)