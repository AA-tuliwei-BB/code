#!/usr/bin/python3

import requests
import os

Err = []

def deal(fi) :
	if fi == 0 : s , t = 2261, 3044
	elif fi == 6 : s, t = 1, 1000

	for i in range(s, t) : #003044
		if fi == 0 :
			pos = ( "http://9.push2his.eastmoney.com/api/qt/stock/kline"
				"/get?cb=jQuery112402823351815161831_1626521459839&"
				f"secid=0.0{str(i).zfill(5)}"
				"&ut=fa5fd1943c7b386f172d6893dbfba10b&"
				"fields1=f1,f2,f3,f4,f5,f6"
				"&fields2=f51,f52,f53,f54,f55,f56,f57,f58,f59,f60,f61"
				"&klt=101&fqt=0&end=20500101&lmt=10&_=1626521459893" )
		elif fi == 6 :
			pos = ( "http://9.push2his.eastmoney.com/api/qt/stock/kline"
				"/get?cb=jQuery112402823351815161831_1626521459839&"
				f"secid=1.6{str(i).zfill(5)}"
				"&ut=fa5fd1943c7b386f172d6893dbfba10b&"
				"fields1=f1,f2,f3,f4,f5,f6"
				"&fields2=f51,f52,f53,f54,f55,f56,f57,f58,f59,f60,f61"
				"&klt=101&fqt=0&end=20500101&lmt=10&_=1626521459893" )

		r = requests.get(pos)
	#	if i % 100 == 0 :
		print(f'{fi}{str(i).zfill(5)}')

		if r.status_code != 200 :
			Err.append(i)
			continue

		data = r.text
		data = data.split('\",\"')
		with open(f'newdata/data{fi}{str(i).zfill(5)}.txt', 'w') as F :
			for i in range(0, len(data)) :
				F.write(data[i] + '\n')

	for i in range(0, len(Err)) :
		print(f'fail to get data in {Err[i]}')

deal(0)
deal(6)

exit()
