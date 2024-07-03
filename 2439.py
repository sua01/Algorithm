#백준 2439 - 별 찍기2

n = int(input())

for i in range(1,n+1):
  for j in range(i, n):
    print(" ", end='')
  for j in range(n-i,n):
    print("*", end='')
  print("")