#!/usr/bin/python3
# file: ex1

score = int(input('please input your score:'))

if score < 0 or score > 100 : print('Impossible')
elif score < 60 : print('D')
elif 60 <= score < 70 : print('C')
elif 70 <= score < 90 : print('B')
else : print('A')

exit()
