//getting legnth / checking if empty
v.empty()
v.size() or v.length();



// empty dynamic array
vector<int> v;

//set array with 3 values
vector<int> v2 = {1,2,3};

//init vector of zeros of size 26 or omit the 0 and put 26 bc the values default to the type specified in the init vector<int> so everything will be zeros
vector<int> count(26, 0);

or

//this does hte samething but init with 9 zeros and also faster to access then the other version and this is fixed size
int rows[9] = {0};  

//appending vals to v2
v2.push_back(val);

//popping values from end
v2.pop_back();

//to print every element
for (int x : v2) {
    cout << x << endl;
}

// getting the maximum or minimum element from a array
maximum_element(v2.begin(), v2.end());

for (const auto& pair : res) {
            result.push_back(pair.second);
        }