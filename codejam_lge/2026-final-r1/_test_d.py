import subprocess

cases = [
    # (input, expected_answer, description)
    ("5\n3 -2 5 1 -3", "2",
     "Example 1: [1..4] sum=7, max=5, ans=2"),

    ("4\n2 -1 -1 2", "0",
     "Example 2: best is 0"),

    ("2\n1 2", "1",
     "N=2: max=2, remaining=1"),

    ("5\n1 2 3 4 5", "10",
     "All positive: full range 15-5=10"),

    ("3\n-5 -3 -1", "0",
     "All negative: best is 0 (single element)"),

    ("5\n10 -1 10 -1 10", "18",
     "Large positives with small negatives: 28-10=18"),

    ("5\n5 5 -100 5 5", "5",
     "Large negative in middle: [0,1] gives 10-5=5"),

    ("4\n3 3 3 3", "9",
     "All same: 12-3=9"),

    ("5\n1 1 100 1 1", "4",
     "One large element: 104-100=4"),

    ("6\n-10 -10 5 3 -10 -10", "3",
     "Positive cluster in middle: [2,3] gives 8-5=3"),
]

passed = 0
failed = 0
for i, (inp, expected, desc) in enumerate(cases, 1):
    result = subprocess.run(
        ["python3", "d.py"],
        input=inp, capture_output=True, text=True
    ).stdout.strip()
    status = "PASS" if result == expected else "FAIL"
    if status == "PASS":
        passed += 1
    else:
        failed += 1
    print(f"TC{i}: {status} (got={result}, expected={expected})  -- {desc}")

print(f"\n{passed}/{passed + failed} passed")
