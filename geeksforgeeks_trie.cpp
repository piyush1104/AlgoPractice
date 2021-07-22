// The fuck is happening. I solved this problem in three tries and that without any compilator error
// I mean, I just read the definition of what trie structure is, opened the gfg practice and solved it in 15 mins
// maybe I am ready to code more and move into some good job.

// Here is the link for the practice
// https://practice.geeksforgeeks.org/problems/trie-insert-and-search0651/1

// { Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>

using namespace std;

// Alphabet size (# of symbols)
#define ALPHABET_SIZE (26)

// Converts key current character into index
// use only 'a' through 'z' and lower case
#define CHAR_TO_INDEX(c) ((int)c - (int)'a')

// trie node
struct TrieNode {
    struct TrieNode *children[ALPHABET_SIZE];

    // isLeaf is true if the node represents
    // end of a word
    bool isLeaf;
};

// Returns new trie node (initialized to NULLs)
struct TrieNode *getNode(void) {
    struct TrieNode *pNode = NULL;

    pNode = (struct TrieNode *) malloc(sizeof(struct TrieNode));

    if (pNode) {
        int i;

        pNode->isLeaf = false;

        for (i = 0; i < ALPHABET_SIZE; i++) pNode->children[i] = NULL;
    }

    return pNode;
}

void insert(struct TrieNode *, string);

bool search(struct TrieNode *, string);

// Driver
int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while (t--) {
        // Input keys (use only 'a' through 'z' and lower case)
        int n;
        cin >> n;
        string keys[n];

        for (int i = 0; i < n; i++) {
            cin >> keys[i];
        }

        struct TrieNode *root = getNode();
        // Construct trie
        for (int i = 0; i < n; i++) insert(root, keys[i]);

        string abc;

        cin >> abc;
        // Search for different keys

        if (search(root, abc))
            cout << "1\n";
        else
            cout << "0\n";
        // char ex;
        // cin >> ex;
        // cout << ex << "\n";
    }
    return 0;
}// } Driver Code Ends


// User function template for C++

// root : root node of the trie
// key : string to be inserted into the trie
// If not present, inserts key into trie
// If the key is prefix of trie node, just marks leaf node

void insert(struct TrieNode *root, string key) {
    struct TrieNode *temp;
    temp = root;
    int m = key.length();
    for(int i=0; i<m; i++){
        if(temp->children[CHAR_TO_INDEX(key[i])] == NULL) {
            struct TrieNode *child = getNode();
            if(i == m-1) {
                child->isLeaf = true;
            }
            temp->children[CHAR_TO_INDEX(key[i])] = child;
            temp = child;
        } else {
            temp = temp->children[CHAR_TO_INDEX(key[i])];
        }
    }
}

// root : root node of the trie
// key : string to search in the trie
// Returns true if key presents in trie, else false

bool search(struct TrieNode *root, string key) {
    int m = key.length();
    struct TrieNode *temp;
    temp = root;
    for(int i=0; i<m; i++) {
        if(temp->children[CHAR_TO_INDEX(key[i])] == NULL) {
            return false;
        } else if(i != m-1 && temp->children[CHAR_TO_INDEX(key[i])]->isLeaf) {
            return false;
        }
        temp = temp->children[CHAR_TO_INDEX(key[i])];
    }
    return true;
}
