n = int(input())
findNum = int(input())
table = [[0 for _ in range(n)] for _ in range(n)]
moveX = [0,1,0,-1]
moveY = [1,0,-1,0]

def pushTable():
    for a in range(n // 2):
        x = a
        y = a
        k = (n-2*a)*(n-2*a)
        for i in range(4):
            for j in range(n-1-2*a):
                table[y][x] = k
                x += moveX[i]
                y += moveY[i]
                k -= 1
    table[n//2][n//2] = 1

pushTable()
for i in range(n):
    output = ' '.join([str(v) for v in table[i]])
    print(output)

for i in range(n):
    for j in range(n):
        if table[i][j] == findNum:
            print("{} {}".format(i+1,j+1))


