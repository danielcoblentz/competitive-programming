// unordered_map<KeyType, ValueType> = c++'s hashmap (avg O(1) insert/lookup, no ordering)

// init empty map or populate it on creation
unordered_map<string, int> m;
unordered_map<string, int> m2 = {{"a", 1}, {"b", 2}, {"c", 3}};

map<vector<int>, vector<string>> count; // --> this allows us to use vectors as keys!


//adding/updating a single key (creates it if missing, overwrites if present)
m["d"] = 4;

//adding without overwriting an existing key
m.insert({"e", 5});

//checking if a key exists (count is 0 or 1 since keys are unique)
if (m.count("a")) { /* exists */ }

//safer existence check + fetch without inserting a default entry (find returns an iterator)
auto it = m.find("a");
if (it != m.end()) { /* it->first = key, it->second = value */ }

//removing a key
m.erase("a");

//size / empty
m.size();
m.empty();

//looping over every key/value pair
for (auto& [key, val] : m) {
    // key, val
}

//bumping a counter for each element, classic frequency map (like python's Counter)
unordered_map<char, int> freq;
for (char c : someString) {
    freq[c]++;
    // if c isn't in freq yet, operator[] inserts it with value 0 first, then ++ makes it 1
}

// searching for a value
if (prevMap.find(diff) != prevMap.end()) { /* found */ }




// max_element returns an ITERATOR to the max entry, not the key/value directly
auto maxIt = max_element(freq.begin(), freq.end(), [](auto& a, auto& b) { return a.second < b.second; });
// maxIt->first  = the key  (the most frequent char)
// maxIt->second = the value (how many times it showed up) this gets the value associated with the second position in the tupel <char, int> longest repeating char replacement problem

//checking if two maps are equal checks the length first, keys then the values
return count1 == count2