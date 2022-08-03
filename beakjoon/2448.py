N = int(input())
ans = ["" for _ in range(N)]

def pointingStars(sy):
    ans[sy]   += "  *  "
    ans[sy+1] += " * * "
    ans[sy+2] += "*****"

def paint(n,sy):
    if n == 3: 
        pointingStars(sy)
        return
    
    nxt = n//2

    front_blank = " "*nxt
    for y in range(sy,sy+nxt):
        ans[y] += front_blank
    paint(nxt,sy)
    for y in range(sy,sy+nxt):
        ans[y] += front_blank

    paint(nxt,sy+nxt)
    for y in range(sy+nxt,sy+n):
        ans[y] += " "
    paint(nxt,sy+nxt)

paint(N,0)
for line in ans:
    print(line)
