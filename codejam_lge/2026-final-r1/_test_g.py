import subprocess

cases = [
    # (input, expected_answer, description)
    ("7 2\n1 1 1 2 2 2 2\n1 2\n1 3\n2 4\n2 5\n3 6\n3 7",
     "24", "Example 1: (2,2) split V_P=V_Q -> 24"),

    ("12 2\n2 2 1 1 1 1 1 1 2 1 1 2\n9 8\n5 2\n2 1\n4 5\n8 11\n10 11\n6 12\n10 12\n10 1\n6 7\n5 3",
     "216", "Example 2: mixed tree -> 216"),

    ("4 2\n1 1 1 1\n1 2\n2 3\n3 4",
     "0", "Chain N=4: no 4 incomparable"),

    ("7 3\n1 1 1 2 2 3 3\n1 2\n1 3\n3 4\n3 5\n5 6\n5 7",
     "8", "(1,3) split: V_L=V_L', V_L!=V_L'' -> 8"),

    ("7 1\n1 1 1 1 1 1 1\n1 2\n1 3\n3 4\n3 5\n5 6\n5 7",
     "24", "(1,3) split: all same V -> 24"),

    ("7 7\n1 2 3 4 5 6 7\n1 2\n1 3\n2 4\n2 5\n3 6\n3 7",
     "8", "(2,2) split V_P!=V_Q -> 8"),

    ("15 1\n1 1 1 1 1 1 1 1 1 1 1 1 1 1 1\n1 2\n1 3\n2 4\n2 5\n3 6\n3 7\n4 8\n4 9\n5 10\n5 11\n6 12\n6 13\n7 14\n7 15",
     "4968", "Complete binary tree depth 3, all V=1 -> 207*24=4968"),

    ("5 2\n1 1 1 2 2\n1 2\n1 3\n2 4\n2 5",
     "0", "N=5: only 3 incomparable nodes possible"),
]

passed = 0
failed = 0
for i, (inp, expected, desc) in enumerate(cases, 1):
    result = subprocess.run(
        ["python3", "g.py"],
        input=inp, capture_output=True, text=True, timeout=10
    ).stdout.strip()
    status = "PASS" if result == expected else "FAIL"
    if status == "PASS":
        passed += 1
    else:
        failed += 1
    print(f"TC{i}: {status} (got={result}, expected={expected})  -- {desc}")

print(f"\n{passed}/{passed + failed} passed")
