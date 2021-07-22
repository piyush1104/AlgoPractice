I always forgot about the syntax related to this. And the functions too.cpp

```cpp

unordered_map<int, int> um;

int key = 1, value = 2;
um[key] = value;

cout << um[key] << endl; // 2

// check if key exists?

if(um.find(key) == um.end()) {
    cout << "Nothing found" << endl;
}

// delete a key

um.erase(key); // no idea what will happen if does not exist.

```



### Anything interesting?

Yes, it is kind of efficient map type as it just maps the key to value and retrieve data from them.

There exist another similar datatype => `map`. This one stores data in balanced binary search tree format. It does that so that keys are maintained in sorted manner. Thus normal data retrieval and insertion takes O(logn) on average.
