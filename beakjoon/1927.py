import heapq

n = int(input())
heap = []
size = 0
for _ in range(n):
    tmp = int(input())

    if tmp==0:
        if size==0: print("0")
        else:
            print(heapq.heappop(heap))
            size -= 1
    else:
        heapq.heappush(heap,tmp)
        size += 1