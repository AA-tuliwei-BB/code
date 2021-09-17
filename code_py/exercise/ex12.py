#!/usr/bin/python3

num = int(input())

while num != 1 :
	if num & 1 :
		print(f'{num} * 3 + 1 = {num * 3 + 1}')
		num = num * 3 + 1
	else :
		print(f'{num} / 2 = {num // 2}')
		num = num // 2

exit()
