import sys

arr = []
for _ in range(int(sys.stdin.readline())):
    x,y = map(int,sys.stdin.readline().split())
    arr.append((x,y))

arr.sort()
for x,y in arr:
    sys.stdout.write(str(x)+' '+str(y)+'\n')