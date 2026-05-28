import subprocess

cases = [
    # (input, expected_answer, description)
    ("3 3\n1 3 3\n4 2 2\n3 2 6\n#..\n.#.\n.##",
     "7", "Example 1: probe (1,1) then worst-case branches"),

    ("1 1\n5\n.", "0", "1x1 clean: position known"),

    ("1 1\n5\n#", "0", "1x1 dirty: contaminated"),

    ("1 2\n3 7\n..", "3", "1x2 both clean: probe cheaper cell"),

    ("1 2\n3 7\n.#", "3", "1x2 one clean one dirty"),

    ("1 2\n3 7\n##", "0", "1x2 both dirty: contaminated"),

    ("1 3\n5 2 8\n...", "2", "1x3 all clean: probe middle"),

    ("2 2\n1 1\n1 1\n..\n..", "3", "2x2 all clean: 3 probes worst case"),

    ("3 3\n1 2 3\n4 5 6\n7 8 9\n###\n###\n###",
     "0", "3x3 all dirty"),

    ("2 1\n3\n7\n.\n.", "3", "2x1 both clean: probe cheaper cell"),
]

passed = 0
failed = 0
for i, (inp, expected, desc) in enumerate(cases, 1):
    result = subprocess.run(
        ["python3", "e.py"],
        input=inp, capture_output=True, text=True, timeout=10
    ).stdout.strip()
    status = "PASS" if result == expected else "FAIL"
    if status == "PASS":
        passed += 1
    else:
        failed += 1
    print(f"TC{i}: {status} (got={result}, expected={expected})  -- {desc}")

print(f"\n{passed}/{passed + failed} passed")
