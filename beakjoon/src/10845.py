n = int(input())
queue = []
length = 0

for _ in range(n):
    a = input().split()
    comm = a[0]

    if comm == "push":
        queue.append(int(a[1]))
        length += 1

    elif comm == "pop":
        if length:
            print(queue[0])
            queue = queue[1:]
            length -= 1
        else:
            print("-1")


    elif comm == "size":
        print(len(queue))

    elif comm == "empty":
        if len(queue) == 0:
            print('1')
        else:
            print('0')
    elif comm == "front":
        if length:
            print(queue[0])
        else:
            print("-1")


    elif comm == "back":
        if length:
            print(queue[len(queue) - 1])
        else:
            print("-1")

