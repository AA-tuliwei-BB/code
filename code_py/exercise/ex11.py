#!/usr/bin/python3

def trans(f) :
	return (f - 32) * 5 / 9

def list(s, t, d) :
	print('     F   |      C')
	for i in range(s, t + 1, d) :
		print(f'  {i:4}   |    {trans(i):6.2f}')

while True :
	order = input()

	if order[0] == 'l' :
		tmp, s, t, d = order.split()
		s, t, d = map(int, [s, t, d])
		list(s, t, d)
		continue

	if order[0] == 't' :
		print(trans(eval(order.split(' ')[1])))
		continue

	if order[0] == 'e' :
		break

exit()
