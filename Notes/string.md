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
