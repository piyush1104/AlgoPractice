#include "stdc++.h"
using namespace std;

struct Node {
    int data;
    int size;
    Node *left;
    Node* right;
};

Node* newNode(int value) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = value;
    node->left = NULL;
    node->right = NULL;
    node->size = 1;
    return node;
}

Node* insert(Node* root, int value) {
    Node* node = newNode(value);
    if(root == NULL) {
        return node;
    }
    if(root->data > value) {
        root->left = insert(root->left, value);
        root->size += 1;
    } else {
        root->right = insert(root->right, value);
        root->size += 1;
    }
    return root;
}

Node* insertPerfect(Node* root, int value) {
    root = insert(root, value);
    root = verifyAndFix(root);
}

// do it later.
int verifyAndFix(Node* root) {
    int leftLevel = verifyAndFix(root->left);
    int rightLevel = verifyAndFix(root->right);
    if(leftLevel < rightLevel - 1) {
        // Node* node = newNode(root->right->value);
        Node* node = root->left;
        node->left = root;
        root->right = root->right->left;
        node->right = root->right->right;
    } else if(rightLevel < )
}

void printLevelTraversal(Node* root) {
    queue<Node*> q;
    q.push(root);
    while(!q.empty()) {
        Node* curr = q.front();
        q.pop();
        cout << curr->data << " ";
        if(curr->left != NULL) q.push(curr->left);
        if(curr->right != NULL) q.push(curr->right);
    }
    cout << endl;
}

int main(int argc, char const *argv[])
{
    int input;
    // Node* head = new Node(); C++ way to do it
    Node* root = NULL;
    while(1) {
        cout << "1: Insert element in binary tree" << endl;
        cout << "2: Create a new binary tree" << endl;
        cout << "3: Print Traversal" << endl;
        cout << "4: Exit" << endl;
        cout << "Enter your input here:\t";
        cin >> input;
        switch(input) {
            case 1:
                int n;
                cout << "Enter the element\t";
                cin >> n;
                root = insert(root, n);
                break;
            case 3:
                printLevelTraversal(root);
                break;
            case 4:
                exit(0);
                break;
            default:
                cout << "No option found for this input, try again" << endl;
                break;
        }
    }
    return 0;
}
