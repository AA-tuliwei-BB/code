#!/usr/bin/python3

with open('data.txt') as f :
	data = f.read()
	data = data.split('\",\"')
	with open('try.out', 'w') as F :
		for i in range(3, len(data) - 1) :
			F.write(data[i] + '\n')

exit()
