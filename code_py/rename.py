#!/usr/bin/python3

from os import rename

for i in range(1, 10) :
	rename(f'ex{i}.py', f'ex0{i}.py')

exit()
