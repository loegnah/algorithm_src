tc = 1
while True:
    L, P, V = map(int,input().split())
    
    if L==0: break

    ans = (V//P)*L
    ans += L if L <= V%P else V%P

    print("Case {0}: {1}".format(tc,ans))
    tc += 1