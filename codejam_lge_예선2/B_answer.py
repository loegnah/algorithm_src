MAXLEN = 60
MAXVAL = 2000
ARSIZE = MAXLEN * MAXVAL + 1
 
def fold(a, b, offset, tot):
    for i in range(tot + 1 - offset):
        a[i] += b[i + offset]
 
# Mark 1 at every odd number
oddbase = [0] * ARSIZE
for i in range(ARSIZE):
    number = i
    isodd = False
    while number:
        if number % 2:
            isodd = not isodd
        number //= 10
    if isodd:
        oddbase[i] = 1
 
# Main
for i in range(int(input())):
    n = int(input())
    A = [int(j) for j in input().split()]
    tot = sum(A)
    A.sort()
    oddarr = list(oddbase)
    prev = -1
    for j in A:
        if prev != j:
            snapshot = list(oddarr)
            prev = j
            mult = 1
        else:
            mult += 1
        fold(oddarr, snapshot, j * mult, tot)
    print(oddarr[0])