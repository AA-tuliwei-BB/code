#!/usr/bin/python3

import requests
import os

Err = []

os.system('mkdir data')

for i in range(1000, 1001) :
	pos = ( "http://9.push2his.eastmoney.com/api/qt/stock/kline"
			"/get?cb=jQuery112402823351815161831_1626521459839&"
			f"secid=0.00{i}"
			"&ut=fa5fd1943c7b386f172d6893dbfba10b&"
			"fields1=f1,f2,f3,f4,f5,f6"
			"&fields2=f51,f52,f53,f54,f55,f56,f57,f58,f59,f60,f61"
			"&klt=101&fqt=0&end=20500101&lmt=120000&_=1626521459893" )

	r = requests.get(pos)

	if r.status_code != 200 :
		Err.append(i)
		continue

	data = r.text
	data = data.split('\",\"')
	with open(f'data/data{i}.txt', 'w') as F :
		for i in range(3, len(data) - 1) :
			F.write(data[i] + '\n')

for i in range(0, len(Err)) :
	print(f'fail to get data in {Err[i]}')


exit()
