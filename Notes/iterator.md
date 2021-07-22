# well this is about iterators in c++ work

you can't access previous iterators. You can't do something like this

```cpp
*(itr - 1)->second;
```

The only way to achieve this, that you need to create a new iterator which keeps track of previous iterator.

More info here - [https://stackoverflow.com/questions/5586377/how-to-access-the-previous-element-in-a-c-list-iterator-loop/5590129](https://stackoverflow.com/questions/5586377/how-to-access-the-previous-element-in-a-c-list-iterator-loop/5590129)
