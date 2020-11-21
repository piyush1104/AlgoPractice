### Well I always used to think that

the right of keeping the start while creating a pointer in C/C++ is just after the type declaration.

```c
Node* head = new Node();
```

But sadly I learned today that this is actually wrong. Why? because `*` is what makes the variable `head` the pointer, not the `Node*`. The `Node` part in `Node*` is just to tell you that the data the pointer created by this will of the type `Node`. I learnt this the hard way. I was doing something like this.

```c
Node* curr, next, next_next;
```

And because I used to think of `*` the old way, I thought all the variables will be pointer of type `Node*`, but no, only `curr` was a pointer, and all the others `next`, `next_next` were of type `Node`.

Think of it like this.

```c
Node *curr, next, next_next;
```

See? Now it makes you feel like only the `curr` is the pointer and others are `Node` type.

The correct way of making all the pointers would be

```c
Node *curr, *next, *next_next;
```
