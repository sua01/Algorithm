#백준 10101 - 삼각형 외우기
#a, b, c = map(int, input().split())

a = int(input())
b = int(input())
c = int(input())

if (a + b + c) != 180:
  print("Error")
else:
  if a == b == c :
    print("Equilateral")
  elif a == b or b == c or a == c:
    print("Isosceles")
  else : print("Scalene")