T = int(input())
for _ in range(T):
    s1 = input()
    s2 = input()

    ans = 0
    for i in range(len(s1)):
        if s1[i] != s2[i]: ans += 1
    
    print("Hamming distance is {}.".format(ans))