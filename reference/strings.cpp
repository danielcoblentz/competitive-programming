#include <iostream>
#include <string>
using namespace std;

int main() {
    // define a string and add ot it (must be same type)
    string s = "";
    s += "the text " + to_string(3) + " all done";
    cout << s << endl;

    // iterating through a string  (chars are char, not string)
    for (char c : s)
        cout << c;
    cout << endl;

    //getting a substring (start idx, (int)length we want to grab up to)
    cout << s.substr(1, 4) << endl;
    // s.substr(start, length);
    //            ^      ^
    //            │      └── how many chars to grab (not an end index)
    //            └───────── idx to begin at

    // if we pass in one value it scans the entire string for it from idx 0, if we pass in a second value it tart only from that idx scans forward
    cout << (int)s.find('t', 2) << endl;   // returns string::npos if not found
    // s.find(target, from);
    //          ^      ^
    //          │      └── idx to start scanning from (optional, defaults to 0)
    //          └───────── char/substring being searched for

    //int to string  (stoi goes the other way: string -> int)
    int n = 5;
    string myString = to_string(n);
    cout << myString << endl;
    cout << stoi("42") << endl;   // string -> int

    //checking length of a string
    string t = "abc";
    cout << (s.length() != t.length()) << endl;

    // chars are ints in c++
    int tmp[26] = {0};
    char character = 'c';
    tmp[character - 'a']++;
    cout << tmp[2] << endl;

    return 0;
}
