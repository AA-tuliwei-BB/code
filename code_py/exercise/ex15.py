#!/usr/bin/python3

from math import sqrt
from math import floor

def chk(num) :
	s = 1
	MAX = floor(sqrt(num))
	for i in range(2, MAX + 1) :
		if num % i == 0 :
			s += i + num // i
	return s == num


print(1)
for i in range(2, 1001) :
	if chk(i) : print(i)

exit()
