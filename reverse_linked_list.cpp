#include "stdc++.h"
using namespace std;

struct Node
{
    int data;
    Node *next;
};

// a->b->c->d->NULL
// b->a->NULL c->d->NULL
// c->b->a->NULL d->NULL
// d->c->b->a->NULL

// void reverseList(head) {
// psuedo code
//     curr = head
//     next = head->next
//     next_next = next->next
//     head->next = NULL
//     while(next != NULL) {
//         next->next = curr
//         curr = next
//         next = next_next
//         next_next = next->next
//     }
// }

Node *reverseList(Node *head) {
    if(head->next == NULL) {
        return head;
    }
    Node *curr, *next, *next_next;
    curr = head;
    next = head->next;
    head->next = NULL;
    while(next->next != NULL) {
        next_next = next->next;
        next->next = curr;
        curr = next;
        next = next_next;
    }
    next->next = curr;
    return next;
}

void printList(Node *head) {
    while(head) {
        cout << head->data << endl;
        head = head->next;
    }
}

int main(int argc, char const *argv[])
{
    // this approach creates the linked list in right->left order
    // i.e. first a node is created completely and then another node is created which points to the
    // previous node.
    // Node* node = new Node();
    // node->data = 1;
    // node->next = NULL;
    // Node* head;
    // for (int i = 2; i < 10; ++i)
    // {
    //     head = new Node();
    //     head->data = i;
    //     head->next = node;
    //     node = head;
    // }

    // two ways to create a linked list, this creates the linked list in left->right order.
    // i.e. head is created first then its element is appended and their data is changed later.
    Node *head = new Node();
    Node *node = new Node();
    head->data = 1;
    head->next = node;
    int i=2;
    while(i<10) {
        Node *node2 = new Node();
        node->data = i;
        node->next = node2;
        node = node2;
        i++;
    }
    node->data = 10;
    node->next = NULL;
    // creation of linked list ended

    printList(head);
    head = reverseList(head);
    printList(head);

    return 0;
}
