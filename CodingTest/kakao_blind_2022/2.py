import math

digits = "0123456789"
def convert(num, base) :
    q, r = divmod(num, base)
    if q == 0 :
        return digits[r] 
    else :
        return convert(q, base) + digits[r]
    
def is_prime_number(x):
    if x == 1: return False
    for i in range(2, int(math.sqrt(x))+1):   
        if x % i == 0:
            return False
    return True
    
def solution(n, k):
    a = str(convert(n, k))
    answer = 0
    
    for b in a.split('0'):
        if not b: 
            continue
        if is_prime_number(int(b)):
            answer += 1
    return answer