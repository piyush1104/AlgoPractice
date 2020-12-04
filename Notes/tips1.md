# Some tips that I keep collecting from here and there.

### Round in c++

provided to us by standard library (std). Actually by cmath,ctgmath

**Returns**: The value of x rounded to the nearest integral (as a floating-point value).

Things to notice is that return type of round is not integer, but same as that the input.

```cpp

int x = 12.5;
int y = 13.3;

cout << round(x) << endl; // 13
cout << round(y) << endl; // 13

```



### Getline function in c++

provided in std, uses `string.h`.

Definition

```cpp
istream& getline (istream&  is, string& str, char delim);
```


From the website itself

    Extracts characters from is and stores them into str until the delimitation character delim is found (or the newline character, '\n', for (2)).

    The extraction also stops if the end of file is reached in is or if some other error occurs during the input operation.

    If the delimiter is found, it is extracted and discarded (i.e. it is not stored and the next input operation will begin after it).

    Note that any content in str before the call is replaced by the newly extracted sequence.

    Each extracted character is appended to the string as if its member push_back was called


`is` refers to the stream.

Example

```cpp

// extract to string
#include <iostream>
#include <string>

int main ()
{
  std::string name;

  std::cout << "Please, enter your full name: ";
  std::getline (std::cin,name);
  std::cout << "Hello, " << name << "!\n";

  return 0;
}

```

Complexity of this algo is O(n) ,i.e. length of the string.

