# Vector Practice

Vectors are same as dynamic arrays with the ability to resize itself automatically when an element is inserted or deleted, with their storage being handled automatically by the container.

	begin() – Returns an iterator pointing to the first element in the vector
	end() – Returns an iterator pointing to the theoretical element that follows the last element in the vector

refer - https://www.geeksforgeeks.org/vector-in-cpp-stl/ for more.

## How to use Vectors?

#### How to declare vectors

```cpp

std::vector<int> v;

```


#### How to fill the elements in a vector

or how to iterate.

```cpp

for (int i = 0; i < 5; ++i)
{
	v1.push_back(i*10+1);
}

```

or you can iterate this way.

```cpp

// i is of type iterator.
for (vector<int>::iterator i = v1.begin(); i != v1.end(); ++i)
{
	cout << *i << ' ';
}
// 1 11 21 31 41

```

you can also print your vector this way

```cpp

// this method of printing vector is also very good.
for (int i = 0; i < v.size(); ++i)
{
	cout << '\t' << v[i];
}

```

#### Some other operations

```cpp

cout << "Size: " << v1.size() << endl; // Size: 5
cout << "Capacity: " << v1.capacity() << endl; // Capacity: 8
cout << "Max Size: " << v1.max_size() << endl; // Max Size: 4611686018427387903

```

Though the size of vector is dynamic, it does not mean it is infinite. It increases with the power of 2. This way amortized cost is reduced.

*You can resize your vector also.*

```cpp

v1.resize(4);
for (vector<int>::iterator i = v1.begin(); i != v1.end(); ++i)
{
	cout << *i << ' ';
}
// 1 11 21 31

```

*Check if vector is empty with empty()*

```cpp

if(v1.empty())
{
	cout << "Vector is Empty." << endl;
} else {
	cout << "Vector is not empty" << endl;
}

```

*reduce the vector to its current size.*

```cpp

v1.shrink_to_fit();

```

**Get values at different positions of a vector**

```cpp

v1.front(); // 1
v1.back(); // 31
v1.at(2); // 12

```


#### Some other cool and important functions

```cpp

// removes last element
v.pop_back();

// inserts 5 at the beginning
v.insert(v.begin(), 5);

cout << "\nThe first element is: " << v[0];

// removes the first element
v.erase(v.begin());

```

creating an array of vectors

```cpp

vector<int> A[length];

```

or creating an vector of arrays;

```cpp

vector<int *> A;
// while creating an element you can do
A.push_back((int *)malloc(length * sizeof(int)));
// remember to delete the allocated memory after work is done.

```

**See this**

![important-stuff]("Web capture_22-11-2020_192929_stackoverflow.com.jpg")


**swap**

swap() – It is used to swap the contents of one vector with another vector of same type. Sizes may differ.

```cpp
 
// Swaps v1 and v2
v1.swap(v2);

```
