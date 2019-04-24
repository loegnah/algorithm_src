n = int(input())
opt = ''
blk = ' '
star = '*'
for i in range(n):
    for _ in range(i,n-1): opt += blk
    opt += star
    for _ in range(i) : opt += (blk + star)
    opt += '\n'
print(opt)

