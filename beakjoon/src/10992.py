n = int(input())
opt = ''
blk = ' '
star = '*'
for _ in range(n-1): opt += blk
opt += (star + '\n')
for i in range(1,n-1):
    for _ in range(i,n-1): opt += blk
    opt += star
    for _ in range(i*2-1) : opt += blk
    opt += star + '\n'
if n != 1:
    for _ in range(n*2-1): opt += star
print(opt)