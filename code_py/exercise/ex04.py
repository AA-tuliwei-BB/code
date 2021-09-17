#!/usr/bin/python3
# GuessNumber Game

from random import randint

num = randint(0, 301)
cnt = 0

while True :
	cnt = cnt + 1
	a = eval(input('Guess a number: '))
	if a == num :
		print('bingo!')
		print('%d times in total' % cnt)
		break
	elif a > num : print('Too big!')
	else : print('Too small!')

exit()
