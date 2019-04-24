s = ['' for i in range(15)]
for _ in range(5):
    ipt = input()
    for i in range(len(ipt)):
        s[i] = s[i] + ipt[i]
for i in range(15):
    print(s[i],end='')