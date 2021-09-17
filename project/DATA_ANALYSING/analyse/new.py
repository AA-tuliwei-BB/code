#!/usr/bin/python3

import os

# id from 2261 to 2661
# data_path => '../data/data{id}.txt'
# result    => '../data/data_result_1.txt

# -10 ~  -7   ->   0
# -7  ~  -4   ->   1
# -4  ~  -2   ->   2
# -2  ~  -1   ->   3
# -1  ~   0   ->   4
# 0   ~   1   ->   5
# 1   ~   2   ->   6
# 2   ~   4   ->   7
# 4   ~   7   ->   8
# 7   ~   10  ->   9

width = 4

def Map(x) :
	if -90 <= x < -7 : y = 0
	if -7 <= x < -4  : y = 1
	if -4 <= x < -2  : y = 2
	if -2 <= x < -1  : y = 3
	if -1 <= x <  0  : y = 4
	if  0 <= x <  1  : y = 5
	if  1 <= x <  2  : y = 6
	if  2 <= x <  4  : y = 7
	if  4 <= x <  7  : y = 8
	if  7 <= x < 90  : y = 9

#	return y

	if y <= 2 : return 0
	if y <= 4 : return 1
	if y <= 6 : return 2
	return 3

mp = {}
nu = [0] * 1000000
ns = [0] * 1000000
nt = [0] * 1000000
t = [0] * 1000000
all_sigh = []
a = []
cnt = 0

def calc(x, y) :
	return (y / x - 1) * 100

with open('result') as f :
	all_sigh = f.readlines()

for fname in os.listdir('../newdata/') :
	if not fname.startswith('data') : continue
	with open('../newdata/' + fname) as f :
		data = f.readlines()
		for j in range(3, len(data)) :
			now = data[j].split(',')
			ns[j] = eval(now[1])
			nt[j] = eval(now[2])
			nu[j] = (nt[j] / ns[j] - 1) * 100
			t[j] = str(Map(nu[j]))

		n = len(data) - 1
		s = t[n - 3] + t[n - 2] + t[n - 1] + t[n]

		try :
			for sigh in all_sigh :
				if s + '\n' == sigh :
					print(f'Index {fname[4:10]} is worth purchasing')
		except : continue

exit()
