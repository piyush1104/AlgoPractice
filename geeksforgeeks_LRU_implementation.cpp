// { Driver Code Starts
#include "stdc++.h"
#include "unordered_map"
using namespace std;

// it is working fine on my system but for some reason, gives segmentation fault in some cases on gfg.
// https://www.geeksforgeeks.org/lru-cache-implementation/
// also I didn't know but there is already a data type called list which acts as a doubly linked list.
// so all the work I did was useless.


 // } Driver Code Ends
// design the class in the most optimal way

struct Node
{
    int value;
    int key;
    Node* prev;
    Node* next;
};

class LRUCache
{
    private:

    int size;
    Node* head;
    Node* last;
    int capacity;
    unordered_map<int, Node*> hashmap;

    public:
    //Constructor for initializing the cache capacity with the given value.
    LRUCache(int cap)
    {
        capacity = cap;
        size = 0;
        head = NULL;
        last = NULL;
    }

    //Function to return value corresponding to the key.
    int get(int key)
    {
        if(head == NULL) {
            return -1;
        }
        // cout << key << endl;
        if(hashmap.find(key) == hashmap.end()) {
            return -1;
        }
        if(capacity == 1) {
            return hashmap[key]->value;
        }

        // cout << key << endl;
        // cout << hashmap[key]->key << endl;
        // int value = hashmap[key]->value;
        // Node* delNode = hashmap[key];
        // Node* prevNode = delNode->prev;
        // Node* nextNode = delNode->next;
        // prevNode->next = nextNode;
        // nextNode->prev = prevNode;
        // delete delNode;
        int value = hashmap[key]->value;
        this->deleteKey(key);

        Node* temp = new Node();
        temp->prev = NULL;
        temp->next = head;
        temp->key = key;
        temp->value = value;
        head->prev = temp;
        head = temp;
        size++;
        hashmap[key] = head;

        return value;
        // your code here
    }

    void deleteKey(int key)
    {
        // cout << "here" << endl;
        // cout << key << endl;
        Node* delNode = hashmap[key];
        size--;
        Node* prevNode = delNode->prev;
        Node* nextNode = delNode->next;
        if(prevNode == NULL) {
            // it is a head Node
            head = nextNode;
            // cout << head->key << endl;
        } else {
            prevNode->next = nextNode;
        }
        if(nextNode == NULL) {
            // last node
            last = prevNode;
        } else {
            nextNode->prev = prevNode;
        }
        hashmap.erase(key);
        delete delNode;
        // cout << "here" << endl;
    }

    //Function for storing key-value pair.
    void set(int key, int value)
    {
        if(capacity == 0) {
            return;
        }
        if(head == NULL) {
            head = new Node();
            head->value = value;
            head->key = key;
            head->next = NULL;
            head->prev = NULL;
            last = head;
            hashmap[key] = head;
            size++;
            return;
        }
        if(hashmap.find(key) != hashmap.end()) {
            if(size == 1) {
                head->value = value;
                return;
            }
            // cout << endl;
            // cout << key << " , " << size << endl;
            this->deleteKey(key);
            // cout << key << " , " << size << endl;
            // cout << endl;
        }
        if(size == capacity) {
            if(capacity == 1) {
                hashmap.erase(head->key);
                head->value = value;
                head->key = key;
                hashmap[key] = head;
                return;
            }
            Node* prevNode = last->prev;
            prevNode->next = NULL;
            hashmap.erase(last->key);
            delete last;
            last = prevNode;
            size--;

        }

        Node* temp = new Node();
        temp->prev = NULL;
        temp->next = head;
        temp->key = key;
        temp->value = value;
        head->prev = temp;
        head = temp;
        size++;
        hashmap[key] = head;

        // your code here

    }
};

// { Driver Code Starts.

int main()
{
    // int t;
    // cin >> t;
    // while (t--)
    // {

        int capacity;
        cin >> capacity;
        LRUCache *cache = new LRUCache(capacity);

        int queries;
        cin >> queries;
        while (queries--)
        {
            string q;
            cin >> q;
            if (q == "SET")
            {
                int key;
                cin >> key;
                int value;
                cin >> value;
                cache->set(key, value);
            }
            else
            {
                int key;
                cin >> key;
                cout << cache->get(key) << " ";
            }
        }
        cout << endl;
    // }
    return 0;
}
  // } Driver Code Ends
