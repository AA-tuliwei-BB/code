#!/usr/bin/python3

for i in range(111, 1000, 37) :
	s = str(i)
	a = s[0]
	b = s[1]
	c = s[2]
	na = int(b + c + a)
	nb = int(c + a + b)

	if na % 37 or nb % 37 :
		print('No')
		exit()

print('Yes')
exit()
