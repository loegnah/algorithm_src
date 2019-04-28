pw = [2,1,0]
ipt = input().lstrip('0')
ipt = '0'*((3-len(ipt)%3)%3) + ipt
ans = ''
for i in range(0,len(ipt),3):
    oc = 0
    for j in range(3):
        oc += int(ipt[i+j])*pow(2,pw[j])
    ans += str(oc)
print(ans)