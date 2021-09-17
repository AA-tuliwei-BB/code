#!/usr/bin/python3

import requests

with open('source', 'w') as f : pass
headers = { 'User-Agent': 'Mozilla/5.0 (X11; Ubuntu; Linux x86_64; rv:90.0) Gecko/20100101 Firefox/90.0' }

for i in range(0, 60, 20) :
	url = ( "https://book.douban.com/subject/6082808/comments"
			f"/?start={i}&limit=20&status=P&sort=new_score" )
	p = requests.get(url, headers = headers)
	with open('source', 'a+') as f :
		f.write(p.text)

exit(0)
