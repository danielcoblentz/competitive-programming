# STL operations by container

What you can call on each container, what it costs, and what bites. Complexities are for
`n` elements unless noted.

## vector

`#include <vector>` — dynamic array, contiguous memory.

| operation | does | cost |
|---|---|---|
| `v.push_back(x)` | append | O(1) amortized |
| `v.emplace_back(a, b)` | append, constructed in place, no temporary | O(1) amortized |
| `v.pop_back()` | remove last, returns **void** | O(1) |
| `v.back()` / `v.front()` | last / first element, as a reference | O(1) |
| `v[i]` | element, no bounds check | O(1) |
| `v.at(i)` | element, throws `out_of_range` | O(1) |
| `v.size()` / `v.empty()` | count / is it empty | O(1) |
| `v.clear()` | remove everything, capacity kept | O(n) |
| `v.resize(n)` / `v.resize(n, val)` | grow or shrink to n | O(n) |
| `v.reserve(n)` | pre-allocate capacity, avoids reallocation | O(n) |
| `v.insert(v.begin() + i, x)` | insert at index i | O(n) |
| `v.erase(v.begin() + i)` | erase index i | O(n) |
| `v.erase(first, last)` | erase a range | O(n) |
| `v.assign(n, val)` | replace contents with n copies | O(n) |
| `v.begin()` / `v.end()` / `v.rbegin()` | iterators, forward and reverse | O(1) |

```cpp
int x = v.back();          // pop_back returns void, read the value first
v.pop_back();

swap(v[i], v.back());      // O(1) erase when order does not matter
v.pop_back();
```

Gotchas: `v.size()` is **unsigned**, so `v.size() - 1` on an empty vector wraps to a huge
number. `pop_back` and `back` on an empty vector are undefined behavior, not an exception.
`push_back` can reallocate and invalidate every pointer, reference and iterator into `v`.
`vector<bool>` is bit-packed and hands out proxies, so `auto&` will not bind to an element.

## string

`#include <string>` — behaves like `vector<char>` plus text operations.

| operation | does |
|---|---|
| `s += "abc"` / `s.push_back(c)` / `s.pop_back()` | append, append one char, drop last |
| `s.substr(pos, len)` | copy of a slice, `len` optional |
| `s.find(sub)` | first index, or `string::npos` if absent |
| `s.size()` / `s.empty()` / `s[i]` / `s.back()` | as with vector |
| `stoi(s)`, `stoll(s)`, `stod(s)` | parse to number |
| `to_string(x)` | number to text |
| `c - '0'`, `c - 'a'` | char digit to int, letter to index 0..25 |

Gotcha: `find` returns `string::npos` (a huge unsigned), never `-1`, so test with
`if (s.find(sub) != string::npos)`.

## deque

`#include <deque>` — double-ended queue, random access, not contiguous.

| operation | cost |
|---|---|
| `dq.push_back(x)` / `dq.push_front(x)` | O(1) |
| `dq.pop_back()` / `dq.pop_front()` | O(1), both **void** |
| `dq.front()` / `dq.back()` / `dq[i]` | O(1) |
| `dq.size()` / `dq.empty()` / `dq.clear()` | O(1) / O(1) / O(n) |

The container behind sliding-window minimum and maximum, where you push indices on the back
and pop stale ones off the front.

## stack

`#include <stack>` — LIFO adapter over a deque.

| operation | does |
|---|---|
| `st.push(x)` / `st.emplace(x)` | add on top |
| `st.pop()` | remove top, returns **void** |
| `st.top()` | top element |
| `st.size()` / `st.empty()` | count / is it empty |

No iteration, no indexing. Read `top()` before `pop()`.

## queue

`#include <queue>` — FIFO adapter.

| operation | does |
|---|---|
| `q.push(x)` / `q.emplace(x)` | add at the back |
| `q.pop()` | remove from the front, returns **void** |
| `q.front()` / `q.back()` | oldest / newest element |
| `q.size()` / `q.empty()` | count / is it empty |

BFS pattern, cache the level size before the inner loop:

```cpp
while (queue.size()) {
    int queueLength = queue.size();
    for (int i = 0; i < queueLength; i++) {
        ...
    }
    length++;
}
```

## priority_queue (heap)

`#include <queue>` — binary heap, **max-heap by default**.

| operation | does | cost |
|---|---|---|
| `pq.push(x)` / `pq.emplace(a, b)` | insert | O(log n) |
| `pq.pop()` | remove the top, returns **void** | O(log n) |
| `pq.top()` | largest element, or smallest for a min-heap | O(1) |
| `pq.size()` / `pq.empty()` | count / is it empty | O(1) |
| `priority_queue<int> pq(v.begin(), v.end())` | heapify an existing range | O(n) |

```cpp
priority_queue<int> maxHeap;                                  // largest on top
priority_queue<int, vector<int>, greater<int>> minHeap;       // smallest on top

// heap of pairs, ordered by first then second, the dijkstra shape
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
pq.push({dist, node});
```

Gotchas: there is **no iteration, no search, no erase of an arbitrary element, and no
decrease-key**. The standard workaround is to push the improved entry again and skip stale
entries when they come off the top, which is what `templates/graphs/dijkstras.cpp` does with
its `shortest.count(n1)` check. If you need to delete arbitrary elements, use a `set` instead.

## set and multiset

`#include <set>` — balanced tree, **sorted**, unique keys (`multiset` allows duplicates).

| operation | does | cost |
|---|---|---|
| `s.insert(x)` | insert, returns `pair<iterator, bool>` | O(log n) |
| `s.erase(x)` | erase by value, returns how many were removed | O(log n) |
| `s.erase(it)` | erase by iterator | O(log n) |
| `s.find(x)` | iterator, or `s.end()` if absent | O(log n) |
| `s.count(x)` | 0 or 1 for `set`, the multiplicity for `multiset` | O(log n) |
| `s.lower_bound(x)` | first element `>= x` | O(log n) |
| `s.upper_bound(x)` | first element `> x` | O(log n) |
| `*s.begin()` / `*s.rbegin()` | smallest / largest | O(1) |
| `s.size()` / `s.empty()` / `s.clear()` | count / is it empty / wipe | O(1), O(1), O(n) |

```cpp
if (s.find(x) != s.end()) { ... }        // membership
auto it = s.lower_bound(x);              // member version, O(log n)
                                         // std::lower_bound(s.begin(), s.end(), x) is O(n) here
```

Gotchas: always use the **member** `lower_bound`, the free `std::lower_bound` degrades to
linear on a tree. On a `multiset`, `s.erase(x)` removes **every** copy, use
`s.erase(s.find(x))` to remove one. Elements are const, you cannot edit one in place, erase
and reinsert.

## unordered_set

`#include <unordered_set>` — hash table, no ordering.

Same calls as `set` for `insert`, `erase`, `find`, `count`, `size`, `empty`, `clear`, all
O(1) average and O(n) worst case. **No `lower_bound`, no `rbegin`, no sorted iteration.**
Extra: `s.reserve(n)` and `s.max_load_factor(f)` to cut rehashing.

## map

`#include <map>` — balanced tree of key/value pairs, **sorted by key**.

| operation | does | cost |
|---|---|---|
| `mp[key]` | value reference, **inserts a default if missing** | O(log n) |
| `mp.at(key)` | value, throws if missing, works on a const map | O(log n) |
| `mp.count(key)` | 0 or 1 | O(log n) |
| `mp.find(key)` | iterator, or `mp.end()` | O(log n) |
| `mp.insert({k, v})` / `mp.emplace(k, v)` | insert, keeps the existing value on a clash | O(log n) |
| `mp.erase(key)` / `mp.erase(it)` | remove | O(log n) |
| `mp.lower_bound(k)` / `mp.upper_bound(k)` | first entry `>= k` / `> k` | O(log n) |
| `mp.begin()` / `mp.rbegin()` | smallest / largest key | O(1) |

```cpp
mp[x]++;                                   // counting, missing keys start at 0
for (auto& [key, val] : mp) { ... }        // iterates in sorted key order
```

Gotchas: `mp[key]` **inserts**, so a lookup with `[]` can silently grow the map, and it does
not compile on a `const map`. Use `count` or `find` to test membership. The key inside the
map is const, you cannot edit it. Any key type with `operator<` works, so
`map<vector<int>, T>` and `map<pair<int,int>, T>` are fine out of the box.

## unordered_map

`#include <unordered_map>` — hash table of key/value pairs, no ordering.

Same calls as `map` for `[]`, `at`, `count`, `find`, `insert`, `emplace`, `erase`, `size`,
`empty`, `clear`, all O(1) average and O(n) worst case. **No `lower_bound`, no `rbegin`, no
sorted iteration.** Extra: `mp.reserve(n)`, `mp.max_load_factor(f)`.

Gotchas: there is no `std::hash` for `pair` or `vector`, so those key types need a custom
hash while `map` takes them as they are. On Codeforces the integer hash is the identity
function and can be attacked with colliding keys, so either use `map` or supply a randomized
hash.

## which one to reach for

| you need | use |
|---|---|
| index access, append at the end | `vector` |
| append at both ends | `deque` |
| last in first out | `stack` |
| first in first out | `queue` |
| repeatedly pull the min or max | `priority_queue` |
| membership only, order irrelevant | `unordered_set` |
| membership plus sorted order or `lower_bound` | `set` |
| key to value, order irrelevant | `unordered_map` |
| key to value, sorted or needs range queries | `map` |
| counting small dense integer keys | `vector<int> cnt(n + 1, 0)`, faster than any map |

## algorithms used with them

`#include <algorithm>`, and `<numeric>` for `accumulate`.

| call | does | cost |
|---|---|---|
| `sort(v.begin(), v.end())` | ascending sort | O(n log n) |
| `sort(v.begin(), v.end(), greater<int>())` | descending | O(n log n) |
| `sort(v.begin(), v.end(), [](A a, A b){ return a.x < b.x; })` | custom order | O(n log n) |
| `reverse(v.begin(), v.end())` | reverse in place | O(n) |
| `max_element(v.begin(), v.end())` | iterator to the largest, deref it | O(n) |
| `accumulate(v.begin(), v.end(), 0LL)` | sum, seed with `0LL` to avoid overflow | O(n) |
| `count(v.begin(), v.end(), x)` | how many equal x | O(n) |
| `lower_bound(v.begin(), v.end(), x)` | first `>= x` in a **sorted** vector | O(log n) |
| `upper_bound(v.begin(), v.end(), x)` | first `> x` in a **sorted** vector | O(log n) |
| `v.erase(unique(v.begin(), v.end()), v.end())` | drop adjacent duplicates, sort first | O(n) |
| `next_permutation(v.begin(), v.end())` | next permutation, false when it wraps | O(n) |
| `__builtin_popcount(x)` / `__builtin_popcountll(x)` | count set bits | O(1) |

```cpp
int idx = lower_bound(v.begin(), v.end(), x) - v.begin();   // iterator to index
```
