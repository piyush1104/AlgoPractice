# Merge

From [GeeksForGeeks](https://www.geeksforgeeks.org/merge-in-cpp-stl/)

```
C++ offers in its STL library a merge() which is quite useful to merge sort two containers into a single container.
```

#### Sample Code

```cpp
// C++ code to demonstrate the working of
// merge() implementation 1

#include <bits/stdc++.h>
using namespace std;

int main()
{
    // initializing 1st container
    vector<int> arr1 = { 1, 4, 6, 3, 2 };

    // initializing 2nd container
    vector<int> arr2 = { 6, 2, 5, 7, 1 };

    // declaring resultant container
    vector<int> arr3(10);

    // sorting initial containers
    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());

    // using merge() to merge the initial containers
    merge(arr1.begin(), arr1.end(), arr2.begin(), arr2.end(), arr3.begin());

    // printing the resultant merged container
    cout << "The container after merging initial containers is : ";

    for (int i = 0; i < arr3.size(); i++)
        cout << arr3[i] << " ";
    return 0;
}

```

Above copied shamelessly from [GeeksForGeeks](https://www.geeksforgeeks.org/merge-in-cpp-stl/).

There is also compare function that goes in the input parameter of merge function that can be used to tell the function to use a kind of merge strategy.

#### Example Applicatoin

This code merges two sorted stacks in the sorted order.

```cpp
// C++ code to demonstrate the application of
// merge() stacking notes

#include <bits/stdc++.h>
using namespace std;

int main()
{
    // initializing 1st container
    // containing denominations
    vector<int> stack1 = { 50, 20, 10, 100, 2000 };

    // initializing 2nd container
    // containing demonitions
    vector<int> stack2 = { 500, 2000, 10, 100, 50 };

    // declaring resultant stack
    vector<int> stack3(10);

    cout << "The original 1st stack : ";
    for (int i = 0; i < 5; i++)
        cout << stack1[i] << " ";

    cout << endl;

    cout << "The original 2nd stack : ";
    for (int i = 0; i < 5; i++)
        cout << stack2[i] << " ";

    cout << endl;

    // sorting initial stacks of notes
    // in descending order
    sort(stack1.begin(), stack1.end());
    sort(stack2.begin(), stack2.end());

    // using merge() to merge the initial stacks
    // of notes
    merge(stack1.begin(), stack1.end(), stack2.begin(), stack2.end(), stack3.begin());

    // printing the resultant stack
    cout << "The resultant stack of notes is : ";

    for (int i = 0; i < stack3.size(); i++)
        cout << stack3[i] << " ";
    return 0;
}
```



