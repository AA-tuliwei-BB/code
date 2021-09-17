#!/usr/bin/python3

# id from 2261 to 2661
# data_path => '../data/data{id}.txt'
# result    => '../data/data_result_1.txt

import os

st_year = 2021

def calc(x, y) :
	return (y / x - 1) * 100

with open('result', 'w') as f : pass # clear result

for fname in os.listdir('../data') :
	if not fname.startswith('data') : continue
	with open('../data/' + fname) as f, open('result', "a+") as fw :
		data = f.readlines()
		st = -1
		for j in range(0, len(data)) :
			if int(data[j][0:4]) >= st_year:
				st = j
				break
		if st == -1 : continue

		sm, cnt = 0, 0
		for i in range(st, len(data)) :
			a = data[i].split(',')
			high = eval(a[3])
			low = eval(a[4])
			d = 0.9 * calc(low, high)
			sm += d
			cnt += 1

		Exp = sm / cnt;
		if Exp < 7 : continue
		fw.write(fname[4:10] + ' : ' + str(Exp) + '\n')

print('ok')

exit()
