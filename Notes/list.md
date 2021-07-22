# doubly linked list

this is a doubly linked list dataype present in c++

For single linked list we have something called - `forward list`.

```cpp

list<int> dl;

dl.push_back(12);
dl.push_front(1);

cout << dl.front() << endl;
cout << dl.back() << endl;

dl.pop_front();
dl.pop_back();

dl.reverse();
dl.sort();

// other functions are
// begin(), end(), empty(),
// erase(itr), insert(itr), size() ,etc.

```


> reference - https://www.geeksforgeeks.org/list-cpp-stl/
