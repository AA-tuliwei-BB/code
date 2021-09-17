#!/usr/bin/python3
#hanno tower

now = 0

def hanno (x, f, t) :
	global now

	if x == 1 :
		now = now + 1
		print(f'Step {now}: {f} -> {t}')
		return

	y = f ^ t
	hanno(x - 1, f, y)
	now = now + 1
	print(f'Step {now}: {f} -> {t}')
	hanno(x - 1, y, t)

x = int(input())
hanno(x, 1, 3)

exit()
