import sys
from collections import deque

readline = sys.stdin.readline

dq = deque()
for _ in range(int(readline())):
    inputs = readline().split()
    cmd = inputs[0]

    if cmd == 'push_front':
        dq.appendleft(int(inputs[1]))
    elif cmd == 'push_back':
        dq.append(int(inputs[1]))
    elif cmd == 'pop_front':
        print(dq.popleft() if len(dq) else -1)
    elif cmd == 'pop_back':
        print(dq.pop() if len(dq) else -1)
    elif cmd == 'size':
        print(len(dq))
    elif cmd == 'empty':
        print(1 if not len(dq) else 0)
    elif cmd == 'front':
        print(dq[0] if len(dq) > 0 else -1)
    elif cmd == 'back':
        print(dq[-1] if len(dq) > 0 else -1)
