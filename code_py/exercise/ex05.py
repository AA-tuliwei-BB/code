#!/usr/bin/python3

a = int(input())
b = 0

while a > 0 :
	c = a % 10
	a = a // 10
	b = b * 10 + c

print(b)
exit()
