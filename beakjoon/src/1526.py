arr = [4,7]
idx = 0
for i in range(1,6):
    for j in range(pow(2,i)):
        a = arr[idx]
        arr.append(a*10+4)
        arr.append(a*10+7)
        idx += 1
arr.append(1000001)

ipt = int(input())
for i in range(len(arr)):
    if ipt < arr[i]:
        print(arr[i-1])
        break