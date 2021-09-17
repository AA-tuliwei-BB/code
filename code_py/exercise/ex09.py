#!/usr/bin/python3

while True :
	try :
		a = int(input())
		b = int(input())
	except Exception as Err :
		if Err == ValueError :
			print('please input a number')
		else :
			print('something\'s wrong:')
			print(f'    {Err}')
	else :
		print(a * b)
		break

exit()
