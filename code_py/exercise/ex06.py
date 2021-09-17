#!/usr/bin/python3

from math import sqrt

a = int(input())
print('%d =' %(a), end = ' ')

flag = True
MAX = int(sqrt(a))
for i in range(2, MAX + 1) :
	while a % i == 0:
		a //= i
		if a == 1 :
			print('* %d' %(i))
			break
		if flag :
			print(i, end = ' ')
			flag = False
		else : print('* %d' %(i), end = ' ')
	if a == 1 : break

exit()
