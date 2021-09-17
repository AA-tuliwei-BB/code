#!/usr/bin/python3

n = int(input())
now = 1
s = 0

for i in range(1, n + 1) :
	now = now * i
	s = s + now
	print(now, s)

print(s)
exit()
