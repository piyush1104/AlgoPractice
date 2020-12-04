# Map

haha

well they are mapping. key => value. I guess you know about these things from javascript.

Editorial from [hackerrank question](https://www.hackerrank.com/challenges/30-dictionaries-and-maps)

```cpp

#include <iostream>
#include <map>
using namespace std;

int main() {
    std::map<string, string> phoneBook;
    int n;
    cin >> n;

    // Read names and numbers, add to phoneBook:
    for(int i = 0; i < n; i++){
        string name;
        string phone;
        cin >> name;
        cin >> phone;
        phoneBook[name] = phone;
    }

    // Execute queries:
    std::map<string,string>::iterator it;
    string query;
    // cool (cin >> query), I was doing getline() like -
    // while(getline(cin, query)) because that's how I have seen using it.
    while( cin >> query ){
        it = phoneBook.find(query);

        if ( it != phoneBook.end() ){ // key is found in phoneBook
            cout << it->first << "=" << it->second << '\n';
        }
        else{ // the iterator hit the end of the phone book without finding key
            cout << "Not found" << '\n';
        }
    }

    return 0;
}

```

### creating map

```cpp
map<string, int> phonebook;
```

### inserting element

Cool way

```cpp
phonebook[name] = number;
```

[GeeksForGeeks](https://www.geeksforgeeks.org/map-associative-containers-the-c-standard-template-library-stl/) way. For fucks sake, why GOG, why? Why did you make it so difficult?

```cpp
phonebook.insert(pair<string, int>(name, number));
```

### Finding the element.

```cpp

map<string,string>::iterator itr;

itr = phoneBook.find(name);

// the same logic is present in the sets.
if ( it == phoneBook.end() ){
    // the iterator hit the end of the phone book without finding key
    cout << "Not found" << '\n';
}
else{ // key is found in phoneBook
    cout << it->first << "=" << it->second << '\n';
}

```

Interestingly, for finding the element. This also works perfect.

```cpp

int number = phoneBook[name];

```

But, if the name is not found in phoneBook, it returns 0. That can be a problem.
Well now who is missing the `undefined` type, huh?

