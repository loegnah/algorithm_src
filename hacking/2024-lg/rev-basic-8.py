def calculate_param_1(K):
    param_1 = []
    for k in K:
        for i in range(0x200):
            if k == (i * (-5)) & 0xff:
                param_1.append(chr(i))
                break
    return param_1


# 주어진 K 배열 값
K = [0xAC, 0xF3, 0x0C, 0x25, 0xA3, 0x10, 0xB7, 0x25, 0x16, 0xC6, 0xB7, 0xBC, 0x07, 0x25,
     0x02, 0xD5, 0xC6, 0x11, 0x07,
     0xC5, ]

# param_1 값을 계산합니다.
param_1 = calculate_param_1(K)
print(''.join(param_1))  # 결과 출력
