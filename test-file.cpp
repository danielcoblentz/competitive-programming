#include <iostream>
#include <string>
#include <vector>




using namespace std;


int main (){
//make an array / set and hashmap
vector<int> nums = {1,2,3,4,5,6};
unordered_map<int,int> count;

for (int i = 0; i < nums.size(); i++) {
    cout << "the current number is " << nums[i] << "and the next is " << nums[i + 1] <<  endl;
    count[nums[i]]++;

    cout << "map populated! with element " << nums[i] << endl;
}


//testing the results added to the map

for (auto& [key, val] : count) {
    cout << "the key is " << key << "and the value is " << val << endl;
}





// making heaps normal and min heap
    return 0;
}