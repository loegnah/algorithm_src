H = 0
L = 1

kk = [0] * 1000
pp: int = 0


def high32Bit(a: int):
    return a >> 32


def low32Bit(a: int):
    return a & 0xFFFFFFFF


def main():
    global kk, pp
    my_aa = [0] * 26  # 104 // 4
    # ipt = input("input: ")
    ipt = "12345671234567"
    if len(ipt) > 14:  # 0xE
        print("no hack")
        return
    func_1(my_aa, ipt)
    # if my_aa[96][L] > 0:
    #     v3 = func_4()
    #     v4 = pp
    #     pp += 1
    #     kk[v4] = v3


def func_1(my_aa: list[int], ipt):
    my_aa[24] = 0
    vv1 = [0, 0]
    for i in range(0, 7):
        a, b = int(ipt[i * 2]), int(ipt[i * 2 + 1])
        if a > 9 or b > 9:
            print("exit 1")
            exit(0)
        vv1 = [a, (i + 1)]
        func_2(my_aa, vv1, b)


def func_2(my_aa: list[int], vv1: int, odd_num: int):
    my_aa[24] += 1
    v8: int = my_aa[24]  # 1,2,3,4,5,6,7
    v9: int = v8 // 2  # 0,1,1,2,2,3,3,4
    v3 = 3 * v8  # 3,6,9,12,,,
    my_aa[v3] = low32Bit(vv1)
    my_aa[v3 + 2] = odd_num  # 5,8,11,

    while v9 > 0 and func_3(my_aa[v3], my_aa[12 * v8][0], my_aa[3 * v9]):
        v4 = 3 * v8
        v10 = my_aa[v4 + 1] << 32 + my_aa[v4]
        v11 = my_aa[v4 + 2]
        v6 = 3 * v9
        my_aa[v4] = my_aa[v6]
        my_aa[v4 + 1][1] = my_aa[v6 + 1][1]
        my_aa[v6] = v10
        my_aa[v6 + 1][1] = v11
        v8 = v9
        v9 //= 2


def func_3(a1: int, a2, a3: int):
    return a1 > a3


def func_4(my_aa: list[int]):
    v10 = my_aa[3]
    v12 = ((my_aa[4] - my_aa[5]) << 32) + v10


main()
