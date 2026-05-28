import subprocess

cases = [
    # (input, expected_answer, description)
    ("5\n0 2\n2 1\n2 3\n1 4", "4",
     "Example: [0,2,1,4] = 0<2>1<4"),

    ("2\n0 1", "2",
     "N=2: trivially zigzag"),

    ("3\n0 1\n1 2", "2",
     "Monotone chain 0-1-2: no zigzag beyond 2"),

    ("3\n0 2\n2 1", "3",
     "Chain 0-2-1: 0<2>1 perfect zigzag"),

    ("6\n3 0\n3 1\n3 2\n3 4\n3 5", "3",
     "Star graph center=3: e.g. [2,3,0]=2<3>0"),

    ("6\n0 5\n5 1\n1 4\n4 2\n2 3", "6",
     "Perfect zigzag chain: 0<5>1<4>2<3"),

    ("4\n0 1\n1 2\n2 3", "2",
     "Monotone chain 0-1-2-3: max zigzag=2"),

    ("6\n3 1\n3 5\n1 0\n1 2\n5 4", "3",
     "Binary tree: [2,1,3] or [4,5,3] = length 3"),

    ("7\n0 2\n2 4\n4 6\n0 1\n2 3\n4 5", "3",
     "Caterpillar: monotone spine blocks long zigzag"),

    ("5\n0 3\n3 1\n1 4\n4 2", "5",
     "Rerooting needed: 0<3>1<4>2 = full path"),
]

passed = 0
failed = 0
for i, (inp, expected, desc) in enumerate(cases, 1):
    result = subprocess.run(
        ["python3", "c.py"],
        input=inp, capture_output=True, text=True
    ).stdout.strip()
    status = "PASS" if result == expected else "FAIL"
    if status == "PASS":
        passed += 1
    else:
        failed += 1
    print(f"TC{i}: {status} (got={result}, expected={expected})  -- {desc}")

print(f"\n{passed}/{passed + failed} passed")
