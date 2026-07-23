# Competitive Programming Repo

Solutions to competitive programming problems from CCSCE contests, Codeforces, LeetCode, and USACO, plus reusable algorithm templates and C++ reference notes.

## File structure

```
contests/ccsce/<year>/   CCSCE contest PDFs, solutions (problem_N.py), and tests/
codeforces/              Codeforces solutions
leetcode/                LeetCode solutions
usaco/                   USACO solutions
templates/               Reusable algorithm templates (DP, trees, sorting, ...)
reference/               C++ language reference notes (arrays, maps, snippets, ...)
scripts/                 Utilities (e.g. PDF text extraction)
usaco-guide/             Fork of the USACO Guide site (merged subtree)
```

Naming convention: snake_case filenames; contest solutions are `problem_N.py` inside their year folder.

## Setup

1. Clone the repository:
   ```bash
   git clone https://github.com/danielcoblentz/Competitive-programming.git
   cd Competitive-programming
   ```
2. C++: builds with the system compiler — open a `.cpp` file in VS Code and press **Cmd+Shift+B** (uses `.vscode/tasks.json`), or manually:
   ```bash
   g++ -std=c++17 -O2 -I .vscode/include -o sol solution.cpp && ./sol < input.txt
   ```
3. Python: no dependencies for solutions; `scripts/extract_pdf.py` needs `PyPDF2`.

To view contest PDFs inside VS Code, install a "PDF viewer" extension (optional).

## Usage

If multiple people are working on the same problem, create a new branch to avoid confusion. Otherwise, feel free to work on any problems you'd like!

## Running tests

Example-based smoke tests live next to their contest year (e.g. `contests/ccsce/2022/tests/`) and use Python's built-in unittest:

```bash
python3 -m unittest discover -v
```

Tests run the solution scripts as subprocesses, feeding example input via stdin and comparing stdout against the expected outputs from the contest PDFs. If you add or modify solutions, add matching tests to keep coverage current. Tests also run automatically in CI on push/PR (`.github/workflows/python-tests.yml`).
