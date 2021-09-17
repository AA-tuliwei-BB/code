#!/usr/bin/python3

from random import randint

a = randint(1, 1000000000)
b = randint(1, 1000000000)
print(a, b)

res = int(input())

if res == a + b:
	print("Accept")
else :
	print("Wrong Answer")
exit()
