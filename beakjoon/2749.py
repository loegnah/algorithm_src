n = int(input())
a = 0
b = 1
if n>749999:
	print("0")
elif n==0:
	print(a)
elif n==1:
	print(b)
else:
	for i in range(n-1):
		tmp = b
		b = a+b
		a = tmp
		if b>1000000:
			b = b%1000000
	print(b%1000000)

