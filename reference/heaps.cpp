// =====================================================================
//  C++ HEAPS (priority_queue) — quick reference
// =====================================================================
//
//  priority_queue<T, Container, Compare> name;
//                 ^   ^          ^
//                 |   |          └── comparator that decides heap order
//                 |   └───────────── underlying storage (almost always vector<T>)
//                 └───────────────── element type (must match Container's element type)
//
//  Core operations (all the same for max/min heap):
//      pq.push(x)   // insert            O(log n)
//      pq.top()     // peek at "best"    O(1)   -- does NOT remove
//      pq.pop()     // remove "best"     O(log n)
//      pq.size()    // number of elems   O(1)
//      pq.empty()   // true if size==0   O(1)
//
//  KEY IDEA: C++ gives you a MAX-heap by default (largest value on top).
//            To get a MIN-heap you must pass greater<T> as the comparator.
// =====================================================================

#include <bits/stdc++.h>
using namespace std;

// ---------------------------------------------------------------------
// 1. MAX-HEAP (default) — top() is always the LARGEST element
// ---------------------------------------------------------------------
void maxHeapDemo() {
    priority_queue<int> maxH;          // default = max-heap

    maxH.push(3);
    maxH.push(10);
    maxH.push(1);
    maxH.push(7);

    // Drains in DESCENDING order: 10, 7, 3, 1
    while (!maxH.empty()) {
        cout << maxH.top() << " ";     // peek largest
        maxH.pop();                    // remove it
    }
    cout << "\n";
}

// ---------------------------------------------------------------------
// 2. MIN-HEAP — top() is always the SMALLEST element
//    Need greater<T> because cpp defaults to a max-heap.
// ---------------------------------------------------------------------
void minHeapDemo() {
    priority_queue<int, vector<int>, greater<int>> minH;

    minH.push(3);
    minH.push(10);
    minH.push(1);
    minH.push(7);

    // Drains in ASCENDING order: 1, 3, 7, 10
    while (!minH.empty()) {
        cout << minH.top() << " ";     // peek smallest
        minH.pop();
    }
    cout << "\n";
}

// ---------------------------------------------------------------------
// 3. HEAP OF PAIRS — ordering compares .first, then .second
//    Handy for "value + index" or "distance + node" style problems.
// ---------------------------------------------------------------------
void pairHeapDemo() {
    // min-heap of pairs: smallest .first on top
    priority_queue<
        pair<int,int>,               // T:         element stored
        vector<pair<int,int>>,       // Container: underlying storage
        greater<pair<int,int>>       // Compare:   greater = min-heap
    > minH;

    minH.push({2, 100});
    minH.push({1, 200});
    minH.push({2, 50});

    // top() == {1, 200}  (smallest first, ties broken by second)
    cout << minH.top().first << "," << minH.top().second << "\n";
}

// ---------------------------------------------------------------------
// 4. CLASSIC USE CASE: "Top K frequent elements"
//    Keep a min-heap of size k. Whenever it grows past k, pop the
//    smallest — so the k LARGEST always survive.
// ---------------------------------------------------------------------
vector<int> topKFrequent(unordered_map<int,int>& count, int k) {
    // pairs are (frequency, value); min-heap keeps the k highest freqs
    priority_queue<
        pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>
    > minH;

    for (auto& entry : count) {
        minH.push({entry.second, entry.first});  // (freq, value)
        if ((int)minH.size() > k) {
            minH.pop();                           // drop lowest freq
        }
    }

    vector<int> res;
    while (!minH.empty()) {
        res.push_back(minH.top().second);         // collect the values
        minH.pop();
    }
    return res;
}

// ---------------------------------------------------------------------
// 5. CUSTOM COMPARATOR (lambda) — order by any rule you want
//    Example: max-heap by absolute value.
// ---------------------------------------------------------------------
void customCompDemo() {
    auto cmp = [](int a, int b) { return abs(a) < abs(b); };  // larger |x| on top
    priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);

    pq.push(-10);
    pq.push(3);
    pq.push(-2);

    cout << pq.top() << "\n";  // -10  (largest magnitude)
}

int main() {
    maxHeapDemo();     // 10 7 3 1
    minHeapDemo();     // 1 3 7 10
    pairHeapDemo();    // 1,200
    customCompDemo();  // -10
    return 0;
}
