# string in c++

Some of other important details are also available in other md files like "tips.md"

Let's start.

### Assigning

Assigning a string in c++ is simple. Just do this. [StackOverflow](https://stackoverflow.com/questions/2894006/how-to-assign-a-string-value-to-a-string-variable-in-c)

```cpp

string s;
s = "some string";

```

### Comparing two strings.

We have compare function which is used like this

```cpp
str1.compare(str2);
```

    0 : if both strings are equal.
    < 0 : if str1 is shorter than str2 or, first character that doesn't match is smaller than str2.
    > 0 : if str1 is longer than str2 or, first character that doesn't match is greater than str2.

Refer: [GeeksForGeeks](https://www.geeksforgeeks.org/stdstringcompare-in-c/)

### Converting an integer to string.

1. You can use stringstream and read the integer from stream. Like

```cpp
int n = 5;
stringstream ss(n);
string s;
ss >> s;
```

2. Another way to do this is using `to_string()` function defined in `string.h`.

```cpp
int n = 5;
string s = to_string(n);
```

simple, huh?

### Removing characters from string.

Use `erase()`.

```cpp

string s = '<tag1>'
// now we are going to remove the "<" and ">" from the above string.
s.erase(s.begin(), s.begin() + 1); // deletes the s.begin() position character (not the s.being()+1 character)
s.erase(s.end()-1, s.end()) // deletes the s.end()-1 position character
cout << s << endl; // tag1
```

Refer [stackoverflow](https://stackoverflow.com/questions/5891610/how-to-remove-certain-characters-from-a-string-in-c) for more.

Look at this stackoverflow [answer](https://stackoverflow.com/a/10532428/6236710)-

You can use erase for removing symbols:

```cpp
str.erase(start_position_to_erase, number_of_symbols);
```

And you can use find to find the starting position:

```cpp
start_position_to_erase = str.find("smth-to-delete");
```


### Clearing stringstream and filling it with other value

See [this question](https://stackoverflow.com/questions/20731/how-do-you-clear-a-stringstream-variable?rq=1) on stackoverflow.
Here are some good and interesting ones.

```cpp
std::stringstream m;
m.str("");
```

But I am reading some comments about the above one that it will not work.
I will have to do something called `m.clear()`. Also see this [link](https://stackoverflow.com/questions/2848087/how-to-clear-stringstream) for better answers on this.

```cpp
std::stringstream m;
m.str("");
m.clear();
```

Here is another one which is said to work only for c+11 and after compilers

```cpp
std::stringstream().swap(m); // swap m with a default constructed stringstream
```

Another interesting one (no idea whether it will work or not?)

```cpp
m=std::stringstream();
```

This one is a quick get away. Here we are using scoping so that we can create as many variables we want

```cpp
{
    std::stringstream ss;
    ss << "what";
}

{
    std::stringstream ss;
    ss << "the";
}

{
    std::stringstream ss;
    ss << "heck";
}
```

### General

Lean more about strings here - [https://www.javatpoint.com/cpp-strings](https://www.javatpoint.com/cpp-strings)

```cpp
#include <iostream>
using namespace std;
int main( ) {
    string s1 = "Hello";
    char ch[] = { 'C', '+', '+'};
    string s2 = string(ch);
    cout<<s1<<endl;
    cout<<s2<<endl;
}
```

## Note

In C and C++ the single quote is used to identify the single character, and double quotes are used for string literals.
A string literal “x” is a string, it is containing character ‘x’ and a null terminator ‘\0’.
So “x” is two-character array in this case.

In C++ the size of the character literal is char. In C the type of character literal is integer (int). So in C the sizeof(‘a’) is 4 for 32bit architecture, and CHAR_BIT is 8. But the sizeof(char) is one byte for both C and C++.

