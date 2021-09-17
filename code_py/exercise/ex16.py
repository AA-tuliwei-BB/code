#!/usr/bin/python3

isp = [0] * 2 + [1] * 2003
chk = [0] * 2005
pri = list()

for i in range (2, 2001) :
	if isp[i] : pri.append(i)
	for j in range(i + i, 2001, i) :
		isp[j] = 0

n = len(pri)
for i in range (0, n) :
	for j in range(i, n) :
		if pri[i] + pri[j] > 2000 : break
		chk[pri[i] + pri[j]] = 1

for i in range(4, 2001, 2) :
	if not chk[i] :
		print('something\'s wrong')
		print(i)
		exit()

print('ok')
exit()
