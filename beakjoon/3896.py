MX = 1299709
arr = [True for _ in range(MX+1)]
def pre_calc():
    for i in range(2,MX+1):
        if not arr[i]: continue

        p = i+i
        while p<=MX:
            arr[p] = False
            p += i

pre_calc()
T = int(input())

for _ in range(T):
    k = int(input())
    if arr[k]: print("0")
    else:
        a = b = k
        while not arr[a]: a -= 1
        while not arr[b]: b += 1
        print(b-a)