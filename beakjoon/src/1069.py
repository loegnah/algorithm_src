import math

X, Y, D, T = map(int,input().split())

dist = math.sqrt(X*X + Y*Y)

if D<T:
    print("{:.10f}".format(dist))
else:
    q = dist//D
    m = dist%D

    q_t1 = q*T
    tot_time1 = q_t1+m

    q_t2 = (q+1)*T
    backwalk_time = (q+1)*D - dist
    tot_time2 = q_t2+backwalk_time
    
    tot_time = min(tot_time1,tot_time2)
    if D>=T*2 and tot_time > T*2:
        tot_time = T*2
    print("{:.10f}".format(tot_time))
