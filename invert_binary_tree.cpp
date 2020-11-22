#include "stdc++.h"

using namespace std;

struct Node
{
	int data;
	int height;
	int level;
	Node* left;
	Node* right;
};

Node *makeBinaryTree(int A[], int start , int end, int level) {
	int mid = (start + end)/2;
	Node *node = new Node();
	node->data = A[mid];
	node->left = NULL;
	node->right = NULL;
	node->height = 1;
	node->level = level;
	if(mid > start) {
		node->left = makeBinaryTree(A, start , mid-1, node->level + 1);
		node->height = max(node->left->height + 1, node->height);
	}
	if(end > mid) {
		node->right = makeBinaryTree(A, mid + 1, end, node->level + 1);
		node->height = max(node->right->height + 1, node->height);
	}

	return node;

}


void getPositions(Node *head, vector<int> *positions, int height)
{
	if(head == NULL) {
		return;
	}
	positions[head->level].push_back(head->data);
	if(head->left == NULL && head->level + 1 < height) {
		positions[head->level + 1].push_back(-1);
	}
	else {
		getPositions(head->left, positions, height);
	}
	if(head->right == NULL && head->level + 1 < height) {	
		positions[head->level+1].push_back(-1);
	} else {
		getPositions(head->right, positions, height);
	}
}

void coutSpaces(int length) {
    for (int i = 0; i < length; ++i)
    {
        cout << " ";
    }
}

int getDigits(int number) {
	if(number / 10 == 0) {
		return 1;
	}
	return 1 + getDigits(number%10);
}

void printBinaryTree(Node *head) {
	if(head == NULL) {
		return;
	}
	int height = head->height;

	// store level wise elements.
	vector<int> *positions;
	positions = (vector<int> *)malloc(height * sizeof(vector<int>));
	getPositions(head, positions, height);

	for (int i = 0; i < height; ++i)
	{
		for (vector<int>::iterator node = positions[i].begin(); node != positions[i].end(); node++)
		{
			// coutSpaces(pow(2, height - i) + 1);
			coutSpaces(4 * (height - i) - getDigits(*node));
			cout << *node; 
		}
		cout << endl;
	}
	// cout << head->data << endl;
	// cout << head->left->data << endl;
	// printBinaryTree(head->left);
	// printBinaryTree(head->right);
	// cout << endl;
}

void invertBinaryTree(Node *head) {
	if(head == NULL) {
		return;
	}
	Node* temp = head->left;
	head->left = head->right;
	head->right = temp;
	invertBinaryTree(head->left);
	invertBinaryTree(head->right);
}


int main(int argc, char const *argv[])
{
	int A[8] = {1, 2, 4 , 9 , 12 , 112 , 1, 4};
	Node* head = makeBinaryTree(A, 0, 7, 0);
	int height = head->height;
	// cout << height << endl; 
	printBinaryTree(head);

	invertBinaryTree(head);

	printBinaryTree(head);
	return 0;
}