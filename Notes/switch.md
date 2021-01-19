# Switch Statement

Today we will get a peek on switch statement in C/C++ language.

One thing that you might have encountered in your life is why the hell can't we declare an variable inside switch statement.

[https://stackoverflow.com/questions/92396/why-cant-variables-be-declared-in-a-switch-statement](https://stackoverflow.com/questions/92396/why-cant-variables-be-declared-in-a-switch-statement)

```cpp
switch (val)
{
case VAL:
  // This won't work
  int newVal = 42;
  break;
case ANOTHER_VAL:
  ...
  break;
}
```

You will get following error `initialization of 'newVal' is skipped by 'case' label`. This is also present in other languages.

*An explanation from [stackoverflow](https://stackoverflow.com/a/92439/6236710)*

Case statements are only labels. This means the compiler will interpret this as a jump directly to the label. In C++, the problem here is one of scope. Your curly brackets define the scope as everything inside the switch statement. This means that you are left with a scope where a jump will be performed further into the code skipping the initialization.

The correct way to handle this is to define a scope specific to that case statement and define your variable within it:

```cpp
switch (val)
{
case VAL:
{
  // This will work
  int newVal = 42;
  break;
}
case ANOTHER_VAL:
...
break;
}
```


