# queue

Just like how we have for vectors, this is quick guide to start using queue

The functions supported by queue are :

    empty() – Returns whether the queue is empty.
    size() – Returns the size of the queue.
    queue::front() and queue::back() in C++ STL– front() function returns a reference to the first element of the queue. back() function returns a reference to the last element of the queue.
    push(g) and pop() – push() function adds the element ‘g’ at the end of the queue. pop() function deletes the first element of the queue.

### Usage

```cpp
int main(int argc, char const *argv[])
{
    queue<int> q;
    q.push(10);
    q.push(11);
    q.push(12);
    q.push(13);
    q.pop(); // returns 10 (unlike stack which will return 13)
    return 0;
}
```


## Dequeue

Another type of queue is dequeue where elements can insert at both ends and come out of both ends.

Similar functions as that of queue with the exception of `push` and `pop` which are relpaced by `push_back`/`push_front` and `pop_back`/`pop_front`.

### Usage

```cpp
int main(int argc, char const *argv[])
{
    deque<int> dq;
    dq.push_back(10);
    dq.push_back(11);
    dq.push_front(9);
    dq.push_front(8);
    dq.pop_back() // returns 11
    dq.pop_front() // returns 8
    return 0;
}
