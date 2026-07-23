 //need to specify this if we want a min heap bc cpp implements a max heap by default
 priority_queue
        <pair<int,int>,          // 1. T: the type of element stored
        vector<pair<int, int>>,  // 2. Container: underlying storage (always vector here)
        greater<pair<int, int>>  // 3. Compare: flips ordering to min-heap instead of default max-heap
        > minH;
// priority_queue<T, Container, Compare> name;
//                ^              ^
//                │              └── comparator that decides heap order (greater = min-heap)
//                └───────────────── element type, must match Container's element type


for (auto& entry : count) {
            minH.push({entry.second, entry.first});
            if (minH.size() > k) {
                minH.pop();
            }
        } 

        vector<int> res;
        for (int i = 0; i < k; i++){
            res.push_back(minH.top().second);
            minH.pop();
        }