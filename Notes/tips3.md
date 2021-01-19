## int to string

Two ways-

1. using stringstream
2. using to_string()

**stringstream** method

```cpp
int k=10;
stringstream ss;
ss << k;
string s;
ss >> s; // s = "10"
```

^The above method can be used to convert string into integer also.

**to_string** method

```cpp
int k = 10;
string s = to_string(k); // s = "10"
```

## string to int

One way is using the above `stringstream` method.

Another is to use `stoi` or `atoi`.

`atoi` for `char*` (C type strings) and `stoi` for `std::string` (C++ type strings).

```cpp
int main()
{
    string str1 = "45";
    string str2 = "3.14159";
    string str3 = "31337 geek";

    int myint1 = stoi(str1);  // 45
    int myint2 = stoi(str2);  // 3
    int myint3 = stoi(str3);  // 31337
    return 0;
}
```


## mean, mode and median relation

You should know this.

```
Mean – Mode = 3 (Mean – Median)
```

