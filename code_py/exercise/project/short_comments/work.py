#!/usr/bin/python3
# encoding:utf-8

cnt = 1
flag = False
s = 0
c = 0

with open('source') as fin, open('result', 'w') as fout :
	text = fin.readlines()
	for line in text :
		line = line.lstrip()

		p = line.find('allstar')
		if p == -1 : pass
		else :
			a = int(line[p + 7])
			s += a
			c += 1
			fout.write(f'第{cnt}条，' + str(a) + '星 : ')
			flag = True

		if line.startswith(r'<span class="short">') :
			if flag == False :
				fout.write(f'第{cnt}条，?星 : ')
			line = line.split('>')[1]
			line = line.split('<')[0]
			fout.write(line + '\n\n')
			cnt = cnt + 1
			flag = False
	
	fout.write(f'\n 平均: {s / c :.2f}星')

exit()
