# Coding Competition Solutions

## Code Style
- Minimize comments — only add when logic is non-obvious
- Separate concerns into functions (e.g. BFS, DP, rerooting as distinct functions)
- Input parsing goes in `if __name__ == "__main__":` block, not inside solve()
- `solve()` receives parsed data as arguments and returns the answer

## File Structure Per Problem
- `{problem}_solve.md` — algorithm analysis and explanation
- `{problem}_testcases.md` — test cases with input/output and explanations
- `{problem}.py` — solution code
- `_test_{problem}.py` — test runner script
