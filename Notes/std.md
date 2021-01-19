# Standard Template Library

## Sort

By default, sort() function sorts in ascending order.

```cpp
// n is the length of array. But you can use any length to sort upto that length.
// i.e. you can
std::sort(arr, arr+n);
```

**Sorting in descending order**

```cpp
std::sort(arr, arr + n, greater<int>());
```

Greater is a function that does a comparison in a way that puts greater element before.
We can write our own functions too.
