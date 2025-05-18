k1_addr = 0x2400
k2_addr = 0x2420
k1_len = 0x12
k2_len = 0x0000000140003120 - 0x0000000140003020

ans = []
with open("/Users/loegnah/sec/wargame/rev/rev-basic-6/chall6.exe", "rb") as f:
    data = f.read()
    k1 = data[k1_addr:k1_addr + k1_len]
    k2 = data[k2_addr:k2_addr + k2_len]
    for i in range(k1_len):
        target = k1[i]
        idx = k2.find(target)
        if idx == -1:
            print('nono')
            break
        else:
            ans.append(chr(idx))
print(ans)
print(''.join(ans))
