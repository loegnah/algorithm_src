bi = ['{0:0>3}'.format(bin(i)[2:]) for i in range(8)]
ipt = input()
if ipt == '0':
    print('0')
else:
    ans = ''
    for i in range(len(ipt)):
        ans += bi[int(ipt[i])]

    print(ans.lstrip('0'))