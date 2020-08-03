#include "stdc++.h"

using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

Node* makeBST(int A[], int start, int end) {
    int middle = start + (end-start)/2;
    Node* head = new Node();
    head->data = A[middle];
    head->left = NULL;
    head->right = NULL;
    if(middle > start) {
        head->left = makeBST(A, start, middle-1);
    }
    if(middle < end) {
        head->right = makeBST(A, middle + 1, end);
    }
    return head;
}

void printBST(Node* T) {
    if(T==NULL) {
        return;
    }
    // int printLength = (length / 2) +1;
    // for (int i = 0; i < printLength; ++i)
    // {
    //     cout << " ";
    // }
    // if(flagRightMost) {
    //     cout << endl;
    // }
    printBST(T->left);
    cout << T->data << " ";
    printBST(T->right);
}

void printBSTultra(Node* T, int level, vector<int> store[]) {
    if(T == NULL) {
        store[level].push_back(-1);
        return;
    }
    printBSTultra(T->left, level + 1, store);
    store[level].push_back(T->data);
    printBSTultra(T->right, level + 1, store);
}

void coutSpaces(int length) {
    for (int i = 0; i < length; ++i)
    {
        cout << " ";
    }
}

int main(int argc, char const *argv[])
{
    int length = 10;
    int A[length];
    for (int i = 0; i < length; ++i)
    {
        A[i] = i*i + 1;
        cout << A[i] << " ";
    }
    cout << endl;
    Node* T = NULL;
    T = makeBST(A, 0, length - 1);
    // printBST(T);
    // cout << end;
    int height = log(length)/log(2) + 2;
    vector<int> store[height];
    printBSTultra(T,0, store);
    for (int i = 0; i < height; ++i)
    {
        int div = pow(2, i) +1;
        for (vector<int>::iterator j = store[i].begin(); j != store[i].end(); ++j)
        {
            coutSpaces(length*height/(div));
            cout << *j;
        }
        cout << endl;
    }
    return 0;
}
