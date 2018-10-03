import sys


def readline():
	return int(input())

fibo = list(range(50002))
fibo[0] = 0
fibo[1] = 1
res = [2,3,4,7,13]

for i in range(2,50002):
	fibo[i] = (2 * fibo[i-1]) + fibo[i-2]

a = 1
while True:
	a = sys.stdin.readline()
	if a != '':
		a = int(a)
	else:
		break
	flag = 0
	for i in res:
		if fibo[a] % i == 0:
			print("Pell's number", a, "is divisible by", i)
			flag += 1
	if flag == 0:
		print(-1)

 	

	
