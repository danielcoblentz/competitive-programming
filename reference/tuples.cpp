// this is specifically for holding 2 elemetns no more
 pair<int, int> p = {3,5}
 .first, p.second

 or

 //diff being the make_pair dtermines the typ without being explicit abt it
 make_pair(thing1, thing2)


 //anything more than 2 we need a tuple which we need to import
 tuple<int, string, bool> t = {42, "hello", true};
auto [num, str, flag] = t;
// num = 42, str = "hello", flag = true


auto [vars] = thing;
^     ^       ^
│     │       └── must be pair, tuple, array, or struct
│     └────────── variables always inside brackets
└──────────────── auto always outside brackets