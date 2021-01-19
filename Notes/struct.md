# notes regarding `struct`

if you write your struct as follows

```cpp

struct Node
{
	int data;
	Node next;
}

```

It will not work. The error is that you can not create a variable of type Node before the type has been defined.

But you can definitely do this.

```cpp

struct Node
{
	int data;
	Node *next;
};

```

Means you can easily create the pointer of that type.

Another confusion I always had is the use of malloc vs directly filling the variable. Well I was a fool, I knew that malloc is needed for dynamically allotting the space for a type if you have created a pointer for that. (Malloc is needed when pointer is being used - you can think of like this.)

Either you do this-

```cpp

// this is pefectly fine. Why? because compiler will give a memory of size(Node) for the variable "head" on the "stack". When the function will end. That part of the stack will be also clearted.
Node head;
head.data = 5;
head.next = NULL:

```

But for pointer, you need to give memory by your own. This is created on run time and is created on heap. This memory is permanent, i.e. will only get cleared when the program will end. So for high end systems, you should clear them as this is a memory leak.

```cpp

Node *head;
// this will assign some memory of the size of node in the heap and will return the corresponding pointer to be assigned to head.
head = (Node *) malloc(sizeof(Node));

```


A great tutorial explaining all this is - [https://www.programiz.com/c-programming/c-structures-pointers](https://www.programiz.com/c-programming/c-structures-pointers)

