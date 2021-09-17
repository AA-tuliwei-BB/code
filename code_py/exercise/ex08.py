#!/usr/bin/python3

while True :
	try :
		a = int(input())
		b = int(input())
		print(a / b)
	except Exception as Err :
		print(Err)
	else :
		break

exit()
