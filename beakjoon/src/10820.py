for i in range(100):
	str = input()
	a=0
	b=0
	c=0
	d=0
	for j in range(len(str)):
		ch = str[j]
		chnum = ord(ch)
		if ch==' ': d += 1
		elif chnum < 0x40: c +=1
		elif chnum < 0x60: b +=1
		else: a +=1
	print("%d %d %d %d" % (a,b,c,d))