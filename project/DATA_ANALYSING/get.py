#!/usr/bin/python3

import requests
import os

first_id = 6
Err = []

for i in range(1, 1000) : #003044
	if first_id == 0 :
		pos = ( "http://9.push2his.eastmoney.com/api/qt/stock/kline"
			"/get?cb=jQuery112402823351815161831_1626521459839&"
			f"secid=0.0{str(i).zfill(5)}"
			"&ut=fa5fd1943c7b386f172d6893dbfba10b&"
			"fields1=f1,f2,f3,f4,f5,f6"
			"&fields2=f51,f52,f53,f54,f55,f56,f57,f58,f59,f60,f61"
			"&klt=101&fqt=0&end=20500101&lmt=20000&_=1626521459893" )
	elif first_id == 6 :
		pos = ( "http://65.push2his.eastmoney.com/api/qt/stock/kline/"
		"get?cb=jQuery11240016747656978705838_1626659722944&"
		f"secid=1.6{str(i).zfill(5)}"
		"&ut=fa5fd1943c7b386f172d6893dbfba10b&"
		"fields1=f1,f2,f3,f4,f5,f6&"
		"fields2=f51,f52,f53,f54,f55,f56,f57,f58,f59,f60,f61&"
		"klt=101&fqt=0&beg=0&end=20500101&lmt=20000&_=1626659723079" )

	r = requests.get(pos)
	print(f'{first_id}{str(i).zfill(5)}')

	if r.status_code != 200 :
		Err.append(i)
		continue

	data = r.text
	data = data.split('\",\"')
	with open(f'data/data{first_id}{str(i).zfill(5)}.txt', 'w') as F :
		for i in range(3, len(data) - 1) :
			F.write(data[i] + '\n')

for i in range(0, len(Err)) :
	print(f'fail to get data in {Err[i]}')


exit()
