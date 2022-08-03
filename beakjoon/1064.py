import math

xy = list(map(int,input().split()))

if abs((xy[1]-xy[3])*(xy[4]-xy[2])-(xy[5]-xy[3])*(xy[0]-xy[2])) < 1e-9:
    print(-1)
else:
    lens = []

    for i in range(0,6,2):
        xa = xy[i]; ya = xy[i+1]
        xb = xy[(i+2)%6]; yb = xy[(i+3)%6]
        xc = xy[(i+4)%6]; yc = xy[(i+5)%6]

        lens.append(
            2*math.sqrt((xa-xb)*(xa-xb)+(ya-yb)*(ya-yb)) +
            2*math.sqrt((xb-xc)*(xb-xc)+(yb-yc)*(yb-yc))
        )

    lens.sort()
    print("{:.10f}".format(lens[2]-lens[0]))
