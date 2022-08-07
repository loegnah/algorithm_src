import sys

while True:
    n = sys.stdin.readline().rstrip()
    if n == '0': break
    print('yes' if n == n[::-1] else 'no')
