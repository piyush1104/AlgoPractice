#include "stdc++.h"

using namespace std;

// three kind of data types we have created. Node1, Node2, Node3

struct Node1 {
    int data;
};

struct Node2 {
    int data;
    Node2* next;
};

struct Node3 {
    int data;
    Node3* next;
};

int main(int argc, char const *argv[])
{
    // this also works
    Node1 head1;
    head1.data = 5;
    cout << head1.data << endl;

    // this works
    Node1 head3;
    Node1* head4;
    head4 = &head3;
    head4->data = 5;
    cout << head4->data << endl;


    // this gives the error.
    Node1* head2;
    head2->data = 5;
    cout << head2->data << endl;

    // we need to dynamically allot the memory we are going to use pointers.
    // By default pointers are not given the memory for that type. They are given the memory of pointer

    return 0;
}
