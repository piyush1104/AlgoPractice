#include "stdc++.h"

using namespace std;

struct Node
{
    int data;
    Node* next;
};

void printList(Node* node) {
    while(node) {
        cout << node->data << endl;
        node = node->next;
    }
}

int main(int argc, char const *argv[])
{
    Node* head = new Node();
    Node* second = new Node();
    Node* third = new Node();
    head = new Node();
    second = new Node();
    third = new Node();
    head->data = 1;
    head->next = second;
    second->data = 2;
    second->next = third;
    third->data = 3;
    third->next = NULL;
    printList(head);

    // it will print right (because we are switching pointers in printList function)
    // the real problem starts when we change things refrenced by pointer.
    // Lol it has so many vairants - head->data, (*head).data(wouldn't work without brackets)
    // Node node = *head; cout << node.data << endl; this will also work
    // Node** node = &head;
    // cout << (*node)->data << endl;
    cout << (*head).data << endl;
    return 0;
}
