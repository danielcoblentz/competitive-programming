//getting a subset of content, must define start, end no [1:3] then loop it
for (int i = start; i < end; i++) {...}

// if we dont need acess to idx
for (int x : arr){...}

//if we need access
for (int i = 0; i < arr.size(); i++){...}

//if we want to use a tmp refrence to the item (only use for non primative values, avoid expensive copies)
for (auto& x : arr) {...}