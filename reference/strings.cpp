// define a string and add ot it (must be same type)
string s = ""
s += "the text " + to_string(3) + "all done";


//getting a substring (start idx, (int)length we want to grab up to)
s.substr(1, 4)
// s.substr(start, length);
//            ^      ^
//            │      └── how many chars to grab (not an end index)
//            └───────── idx to begin at


// if we pass in one value it scans the entire string for it from idx 0, if we pass in a second value it tart only from that idx scans forward
s.find('#', 2)
// s.find(target, from);
//          ^      ^
//          │      └── idx to start scanning from (optional, defaults to 0)
//          └───────── char/substring being searched for

//string to int
stoi()

