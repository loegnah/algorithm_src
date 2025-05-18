def calculate_a1(byte_140003000):
    a1 = []
    for i in range(len(byte_140003000)):
        # byte_140003000[i] 값을 이용해 value_at_address를 역으로 계산
        for possible_value in range(256):  # 8비트 값은 0에서 255 사이
            part1 = (16 * possible_value) & 0xFF
            part2 = (possible_value >> 4) & 0xFF
            result = part1 | part2
            if result == byte_140003000[i]:
                a1.append(possible_value)
                break
        else:
            # 만약 0-255 범위에서 값이 없으면 오류 발생
            raise ValueError(f"Value not found for byte_140003000[{i}] = {byte_140003000[i]}")

    return a1


# 주어진 byte_140003000 값
byte_140003000 = [
    0x24, 0x27, 0x13, 0xC6, 0xC6, 0x13, 0x16, 0xE6,
    0x47, 0xF5, 0x26, 0x96, 0x47, 0xF5, 0x46, 0x27,
    0x13, 0x26, 0x26, 0xC6, 0x56, 0xF5, 0xC3, 0xC3,
    0xF5, 0xE3, 0xE3
]

# a1 값을 계산
a1 = calculate_a1(byte_140003000)
print(a1)
print(''.join(chr(x) for x in a1))
