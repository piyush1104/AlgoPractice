#include "stdc++.h"

using namespace std;

struct Node
{
    int data;
    Node* next;
};

void printList(Node* head) {
    if(head == NULL) {
        cout << "No element in the list" << endl;
        return;
    }
    while(head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
    return;
}

Node* insertNode(Node* head, int data, int index) {
    int curr = 0;
    Node* iter;
    iter = head;
    while(curr < index-1) {
        if(iter == NULL || iter->next == NULL) {
            cout << "Could not insert as cannot access this index" << endl;
            return head;
        }
        iter = iter->next;
        curr++;
    }
    Node* node;
    node = new Node();
    node->data = data;
    if(index==0) {
        node->next = head;
        return node;
    } else if(iter == NULL) {
        cout << "Could not insert as cannot access this index" << endl;
        return head;
    }
    node->next = iter->next;
    iter->next = node;
    return head;
}

int main(int argc, char const *argv[])
{
    Node* head;
    head = NULL;
    int choice;
    while(1) {
        cout << "1: Print Linked List" << endl;
        cout << "2: Insert at index" << endl;
        cout << "3: Delete at index" << endl;
        cout << "4: End this program" << endl;
        cout << "Enter your choice:\t";
        cin >> choice;
        int data, index;
        switch(choice) {
            case 1:
                printList(head);
                break;
            case 2:
                cin >> data >> index;
                head = insertNode(head, data, index);
                break;
            case 3:
                cin >> index;
                // deleteNode(head, index);
                break;
            case 4:
                exit(0);
                break;
            default:
                cout << "Incorrect Choice" << endl;
                break;
        }
    }
    return 0;
}
