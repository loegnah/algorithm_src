for _ in range(int(input())):
    r,s = input().split()
    r = int(r)
    opt = ""
    for i in range(len(s)):
        opt += s[i]*r
    print(opt)
