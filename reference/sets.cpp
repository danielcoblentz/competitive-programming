// populating a set w/o loop

unordered_set<int> seen(nums.begin(), nums.end());

//get current size of set or use window calculation l - r + 1
(int)seen.size()

//adding specific values and removing them
seen.erase(s[l])
seen.insert(s[i])
seen.contains(s[i]) // returns true if s[i] is in the set, false otherwise
