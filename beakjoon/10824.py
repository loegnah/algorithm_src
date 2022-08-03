(a,b,c,d) = map(int,input().split())

mult = 10
while b//mult!=0:
	mult = mult*10
a = a*mult
mult = 10
while d//mult!=0:
	mult = mult*10
c = c*mult
print(a+b+c+d)