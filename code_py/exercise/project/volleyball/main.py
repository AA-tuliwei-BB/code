#!/usr/bin/python3

import requests
import re

url = ("https://en.volleyballworld.com/"
		"en/vnl/2019/men/resultsandranking/round1")

req = requests.get(url)
assert(req.status_code == 200)
source = req.text

tbody= re.findall(r"<tbody>([\s\S]*?)</tbody>", source)
tbody = tbody[0]

with open('result', 'w') as fw :
	titles = ["Total", "Won", "Lost"]
	title = "Teams"
	fw.write(f'{title:12}')
	for title in titles :
		fw.write(f'{title:8}')
	fw.write('\n')

	trAll = re.findall(r'<tr.*?>([\s\S]*?)</tr>', tbody)
	for tr in trAll :
		name = re.findall(r'<td.+?>([\s\S]+?)</td>', tr)[1]
		name = re.findall(r'<figcaption><a.*?>(.*?)</a>', name)[0]
		fw.write(f'{name:12}')

		tdAll = re.findall(r'<td.+?>(.+?)</td>', tr)
		td = tdAll[1:4]
		for tmp in td :
			fw.write(f'{tmp:8}')
		fw.write('\n')

exit(0)
