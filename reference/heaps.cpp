// priority_queue<T, container, compare>, max heap unless compare is greater<T>
// push and pop are O(log n), top is O(1)

#include <bits/stdc++.h>
using namespace std;
#define vvi vector<vector<int>>
// max heap, top() is the largest
void maxHeapDemo() {
    priority_queue<int> maxH;

    maxH.push(3);
    maxH.push(10);
    maxH.push(1);
    maxH.push(7);

    // pops in descending order
    while (!maxH.empty()) {
        cout << maxH.top() << " ";     // peek largest
        maxH.pop();                    // remove it
    }
    cout << "\n";
}

// min heap, needs greater<T> since the default is a max heap
void minHeapDemo() {
    priority_queue<int, vector<int>, greater<int>> minH;

    minH.push(3);
    minH.push(10);
    minH.push(1);
    minH.push(7);

    // pops in ascending order
    while (!minH.empty()) {
        cout << minH.top() << " ";     // peek smallest
        minH.pop();
    }
    cout << "\n";
}

// heap of pairs, compares .first then .second
void pairHeapDemo() {
    // min-heap of pairs: smallest .first on top
    priority_queue<
        pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>
    > minH;

    minH.push({2, 100});
    minH.push({1, 200});
    minH.push({2, 50});

    // top is {1, 200}, ties go to the smaller second
    cout << minH.top().first << "," << minH.top().second << "\n";
}

// top k frequent, keep a min heap of size k and pop when it grows past k
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

// custom comparator, max heap by absolute value
void customCompDemo() {
    auto cmp = [](int a, int b) { return abs(a) < abs(b); };  // larger |x| on top
    priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);

    pq.push(-10);
    pq.push(3);
    pq.push(-2);

    cout << pq.top() << "\n";  // -10
}

int main() {
    maxHeapDemo();     // 10 7 3 1
    minHeapDemo();     // 1 3 7 10
    pairHeapDemo();    // 1,200
    customCompDemo();  // -10
    return 0;
}
