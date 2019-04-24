arr = list(map(int,input().split()))
arr.sort()
a,b,c = arr

dif1 = b-a
dif2 = c-b

if dif1==dif2: print(c+dif1)
elif dif1>dif2: print(a+dif2)
else: print(b+dif1)