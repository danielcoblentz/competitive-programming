#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int main() {
    // empty dynamic array
    vector<int> v;

    //getting legnth / checking if empty   (vectors have .size(), only strings have .length())
    cout << v.empty() << " " << v.size() << endl;

    //set array with 3 values
    vector<int> v2 = {1, 2, 3};

    //init vector of zeros of size 26 or omit the 0 and put 26 bc the values default to the type specified in the init vector<int> so everything will be zeros
    vector<int> count(26, 0);

    // or

    //this does hte samething but init with 9 zeros and also faster to access then the other version and this is fixed size
    int rows[9] = {0};

    //appending vals to v2
    int val = 4;
    v2.push_back(val);

    //popping values from end
    v2.pop_back();

    //to print every element
    for (int x : v2) {
        cout << x << endl;
    }

    // getting the maximum or minimum element from a array (returns an iterator, deref with *)
    cout << *max_element(v2.begin(), v2.end()) << endl;

    map<int, int> res = {{1, 10}, {2, 20}};
    vector<int> result;
    for (const auto& pair : res) {
        result.push_back(pair.second);
    }

    //getting hte max element without writing a loop, wehre piles an an array of ints
    vector<int> piles = {3, 6, 7, 11};
    cout << *max_element(begin(piles), end(piles)) << endl;

    cout << piles.back() << endl;
    cout << rows[0] << " " << count[0] << endl;

    return 0;
}
