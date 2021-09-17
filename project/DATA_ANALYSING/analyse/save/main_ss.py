#!/usr/bin/python3

# id from 2261 to 2661
# data_path => '../data/data{id}.txt'
# result    => '../data/data_result_1.txt

import os

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
a = []
cnt = 0

def calc(x, y) :
	return (y / x - 1) * 100

for fname in os.listdir('../data') :
	if not fname.startswith('data') : continue
	with open('../data/' + fname) as f :
		data = f.readlines()
		for j in range(0, len(data)) :
			now = data[j].split(',')
			ns[j] = eval(now[1])
			nt[j] = eval(now[2])
			nu[j] = (nt[j] / ns[j] - 1) * 100
#			print(nu[j])
			t[j] = str(Map(nu[j]))

		for r in range(width - 1, len(data) - 2) :
			s = ''
			for j in range(r - width + 1, r + 1) :
				s = s + t[j]

			tmpa, tmpb = mp.get(s, (0, 0))
#			print(tmpa, tmpb)
			if tmpb == 0 : a.append(s)
			mp[s] = (tmpa + calc(ns[r + 1], ns[r + 2]), tmpb + 1)
#			print(mp[s])

print('ok')
print(len(a))

with open('result', 'w') as f :
	for i in range(0, len(a)) :
		tmpa, tmpb = mp[a[i]]
#		if tmpb < 10 : continue
		Exp = tmpa / tmpb
#		if Exp < 5 : continue
#		if Exp > 2 : f.write(f'!!!!!!!!! : {a[i]} -> {Exp}\n')
#		else : f.write(str(Exp) + '\n')
		f.write(f': {a[i]} -> {Exp:8.4f} totolly {tmpb} times\n')

exit()
