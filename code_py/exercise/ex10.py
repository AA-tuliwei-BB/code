#!/usr/bin/python3
#BMI calculator

w = eval(input())
h = eval(input())

BMI = w / ( h * h)
print(f'your BMI is {BMI}')

if BMI < 18.5 :
	print('you are too thing')
elif BMI < 24 :
	print('you are normal')
elif BMI < 28 :
	print('you are overweight')
else :
	print('you are fat')

exit()
