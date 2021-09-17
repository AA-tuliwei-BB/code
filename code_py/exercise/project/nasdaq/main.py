#!/usr/bin/python3

import requests
import re

url = 'https://money.cnn.com/data/markets/nasdaq'
req = requests.get(url)

# get thead
head = re.findall(r'<thead>(.*?)</thead>', req.text)
assert len(head) == 1
thead = re.findall(r'>([^<^>]+?)<', head[0])
thead.pop()
thead.pop()
thead.append('YTD Change')

# get tbody
tbody = []
body = re.findall(r'<tbody>(.*?)</tbody>', req.text)
assert len(body) == 1
row_list = re.findall(r'<tr>(.*?)</tr>', body[0])
for row in row_list :
	tmp = re.findall(r'>([^<^>^&]+?)<', row)
	tbody.append(tmp)

with open('result', 'w') as fout :
	for s in thead :
		fout.write(f'{s:<10}')
	fout.write('\n')
	for row in tbody :
		for s in row :
			fout.write(f'{s:<10}')
		fout.write('\n')

exit(0)
