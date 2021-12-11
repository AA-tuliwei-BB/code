#!/usr/bin/python3
#coding:UTF-8

import re

cnt = {}

with open('data') as fin, open('result', 'w') as f:
	Data = fin.read()
	Data = Data.split('--------')
	for data in Data:
		data = list(set(re.findall(r'《(.*?)》', data)))
		for d in data:
			if len(d) < 20:
				if d in cnt:
					cnt[d] = cnt[d] + 1
				else:
					cnt[d] = 1

	tmp = []
	for x in cnt:
		tmp.append((cnt[x], x))
	tmp = reversed(sorted(tmp))
	for x, y in tmp:
		ylen = len(y)
		f.write(f'{y:30}')
		f.write(' ' * (10 - ylen))
		f.write(f'{x:<} times\n')
