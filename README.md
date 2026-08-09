# Competitive Programming Repo

Solutions to competitive programming problems from CCSCE contests, Codeforces, and LeetCode, plus reusable algorithm templates and C++ reference notes.

## File structure

```
contests/ccsce/<year>/   CCSCE contest PDFs, solutions (problem_N.py), and tests/
contests/CF/             Codeforces solutions
leetcode/                LeetCode solutions
leetcode/nc150/          NeetCode 150, grouped by topic
templates/               Reusable algorithm templates, grouped by topic
reference/               C++ language reference notes (arrays, maps, snippets, ...)
usaco-guide/             Fork of the USACO Guide site (merged subtree)
```

`templates/` covers arrays, backtracking, bits, DP (top-down and bottom-up), graphs,
heaps, linked lists, matrices, searching, sorting, and trees. Each file is a
standalone reference: it compiles on its own but has no `main()`, so it's meant to
be read and copied from rather than run.

Naming convention: contest solutions are `problem_N.py` inside their year folder.
Templates use kebab-case (`sliding-window.cpp`); older files use snake_case.

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
3. Python: no dependencies, the solutions use the standard library only.

### Shell shortcuts (`comp` / `run` / `build`)

Terminal helpers for compiling C++ without the full `g++` incantation. They live in `~/.zshrc`; the filename works with or without the `.cpp` extension, and the repo's `bits/stdc++.h` shim is picked up automatically from any subdirectory.

| Command          | Does                                              |
| ---------------- | ------------------------------------------------- |
| `comp <file>`    | compile only (`foo.cpp` → `foo.out`)              |
| `run <file>`     | run the compiled `foo.out` binary                 |
| `build <file>`   | compile, then run                                 |

```bash
build solution            # compile + run
build solution < in.txt   # feed input from a file
run solution arg1 arg2    # extra args forwarded to the program
```

Compiles with `g++ -std=c++20 -O2 -Wall -Wextra`. The `*.out` binaries are gitignored.

<details>
<summary>Install (paste into <code>~/.zshrc</code>, then <code>source ~/.zshrc</code>)</summary>

```zsh
_cp_src() { [[ "$1" == *.cpp ]] && print -r -- "$1" || print -r -- "$1.cpp"; }
_cp_bin() { local s; s=$(_cp_src "$1"); print -r -- "${s%.cpp}.out"; }

comp() {
  [[ -z "$1" ]] && { print -u2 "usage: comp <file>"; return 2; }
  local src; src=$(_cp_src "$1")
  [[ -f "$src" ]] || { print -u2 "comp: no such file: $src"; return 1; }
  local inc=() root
  root=$(git rev-parse --show-toplevel 2>/dev/null)
  [[ -n "$root" && -d "$root/.vscode/include" ]] && inc=(-I "$root/.vscode/include")
  g++ -std=c++20 -O2 -Wall -Wextra $inc -o "$(_cp_bin "$1")" "$src"
}

run() {
  [[ -z "$1" ]] && { print -u2 "usage: run <file> [args...]"; return 2; }
  local bin; bin=$(_cp_bin "$1")
  [[ -x "$bin" ]] || { print -u2 "run: not compiled: $bin (try 'comp $1' or 'build $1')"; return 1; }
  [[ "$bin" == */* ]] || bin="./$bin"
  "$bin" "${@:2}"
}

build() {
  [[ -z "$1" ]] && { print -u2 "usage: build <file> [args...]"; return 2; }
  comp "$1" || return $?
  run "$@"
}
```

</details>

To view contest PDFs inside VS Code, install a "PDF viewer" extension (optional).

## Usage

If multiple people are working on the same problem, create a new branch to avoid confusion. Otherwise, feel free to work on any problems you'd like!

## Running tests

Example-based smoke tests live next to their contest year (e.g. `contests/ccsce/2022/tests/`) and use Python's built-in unittest:

```bash
python3 -m unittest discover -v
```

Tests run the solution scripts as subprocesses, feeding example input via stdin and comparing stdout against the expected outputs from the contest PDFs. If you add or modify solutions, add matching tests to keep coverage current.
