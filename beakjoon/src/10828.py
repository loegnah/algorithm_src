n = int(input())
stack = []
length = 0

for _ in range(n):
	a = input().split()
	comm = a[0]


	if comm == "push":
		stack.append(int(a[1]))
		length += 1

	elif comm == "pop":
		if length:
			print(stack.pop())
			length -= 1
		else: print("-1")
		

	elif comm == "size":
		print(len(stack))

	elif comm == "empty":
		if len(stack) == 0:
			print('1')
		else:
			print('0')

	elif comm == "top":
		if length: print(stack[len(stack)-1])
		else: print("-1")