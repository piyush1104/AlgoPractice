# String Revisited

we have already written about string a lot in *string.md* file. But later I found this link - [https://embeddedartistry.com/blog/2017/07/26/stdstring-vs-c-strings](https://embeddedartistry.com/blog/2017/07/26/stdstring-vs-c-strings), which also told me some nice things.

## Declaration and Assignment

```cpp
std::string str;
```

Assign it like this

```cpp
std::string str("Piyush"); // str = "Piyush"
```

```cpp
std::string str2(str); // str2 = "Piyush"
```

or like this

```cpp
str = "Piyush"; // str = "Piyush"
```

```cpp
str2 = str; // str2 = "Piyush"
```

## Comparing strings

We can directly use comparision operators `=`, `>`, `<` to compare strings.

```cpp
if(str == "Piyush") {
    cout << "string matched!" << endl;
}
```

There is also a .compare() function that we can use. About that is written *string.md* file.

## Concatenating strings

```cpp
//Concatenation is also simple!
my_str = "lip" + name2;
my_str += "lip"; //C-string cat works too
```

We can also use .append() function.
