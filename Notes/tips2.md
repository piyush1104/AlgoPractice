# cin and getline in c++ from hackerrank

People starting to learn C++ might suffer if they aren't familiar with cin >> and getline() and what happens if you use both of them together. Using cin leaves an end of line character which is then read by your getline(); It is best not to mix different types of input.

The solution one could use to overcome this problem is to use a different input method. On the other hand, it is always nice to get familiar with problems one might come across while coding, so take a look. It is possible to overcome this problem while keeping all of your code and just adding a single line.

Here is an excerpt from the input code:

```cpp

cin >> doubleNumber;
cin.ignore();  //ignores an end of line character
getline(cin, stringName);

```

This will read you string correctly, it will also read the whole line. It will just ignore a character and continue from that.

I could be wrong, I'm still a complete novice myself but this is the way I understand it. Cheers.


# printing floating numbers in c++ using cout.

**Woah no printf**, huh?

```cpp

// Declare second integer, double, and String variables.
int i2;
double d2;
string s2;

// Read and save an integer, double, and String to your variables.
cin >> i2;
cin >> d2;
getline(cin >> ws, s2); // eat whitespace (first they eat whitespace.)
// You can do the above thing also (cin.ignore())

// Print the sum of both integer variables on a new line.
cout << i + i2 << endl;

// Print the sum of the double variables on a new line.
cout << fixed << setprecision(1) << d + d2 << endl;

// Concatenate and print the String variables on a new line
// The 's' variable above should be printed first.
cout << s + s2 << endl;
// I did it this way => cout << s << s2 << endl;

```

^^^ above content copied shamelessly from https://www.hackerrank.com/challenges/30-data-types/editorial


## More from the same hackerrank post

Link - https://www.hackerrank.com/challenges/30-data-types/tutorial

### C++

You may find this information helpful when completing this challenge in C++.

To consume the whitespace or newline between the end of a token and the beginning of the next line:

```cpp
// eat whitespace
getline(cin >> ws, s2);
```

where s2 is a string. In addition, you can specify the scale of floating-point output with the following code:

```cpp
#include <iostream>
#include <iomanip>

using namespace std;
int main(int argc, char *argv[]) {
    double pi = 3.14159;

    // Let's say we wanted to scale this to 2 decimal places:
    cout << fixed << setprecision(2) << pi << endl;
    printf("%.2f", pi);
}
```

which produces this output:

```
3.14
3.14
```

Still unclear? Take some time to review the documentation on these topics:

- [ws](http://www.cplusplus.com/reference/istream/ws/)
- [setprecision](http://www.cplusplus.com/reference/iomanip/setprecision/)
- [fixed](http://www.cplusplus.com/reference/ios/fixed/)
- [printf](http://www.cplusplus.com/reference/cstdio/printf/)

