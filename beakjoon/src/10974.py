import itertools

N = int(input())
arr = [i for i in range(1,N+1)]

for prm in itertools.permutations(arr):
    print(' '.join(map(str,prm)))