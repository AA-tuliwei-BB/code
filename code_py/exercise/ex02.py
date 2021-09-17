#!usr/bin/python3

from math import sqrt

a = int(input())
b = int(input())
c = int(input())
d = b * b - 4 * a * c

if d < 0 : print('no real solution')
elif d == 0 :
	x = -b / (a * 2)
	print('x = {:.1f}'.format(x))
else :
	x1 = (-b + sqrt(d)) / (a * 2)
	x2 = (-b - sqrt(d)) / (a * 2)
	print('x1 = {:.1f}, x2 = {:.1d}'.format(x1, x2))

exit()
