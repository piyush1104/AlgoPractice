#include "stdc++.h"

using namespace std;

// wrote the whole code in one go, can't believe myself
// It is O(n^2) worst case time and O(n) worst case space complexity.
// But we can leverage this pattern and create a O(n) solution. One is using a random pivot
// which gives us O(n) amortized time complexity. and O(logn) amortized space complexity.
// Another way is finding the pivot by dividing the array in chunks of 5. See k-smallest-fastest.cpp

void swap(int A[], int i, int j) {
    int temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}

void printArray(int A[], int n) {
    for (int i = 0; i < n; ++i)
    {
        cout << A[i] << " ";
    }
    cout << endl;
}


int kSmallest(int A[], int l, int r, int k) {
    if(l == r) {
        return A[l];
    }
    int p = l; //pivot.
    int x = A[l];
    for(int i=l; i<=r ; i++) {
        if(A[i]<x) {
            p++;
        }
    }
    swap(A, l, p);
    int left = l;
    int right = r;
    while(left!=p) {
        if(A[left] <p) {
            left++;
        } else {
            swap(A, left, right);
            right--;
        }
    }
    // printArray(A, r);
    if(p==k) {
        return A[p];
    }
    if(p<k) {
        return kSmallest(A, p+1, r, k);
    }
    return kSmallest(A, l, p-1, k);
}

int main(int argc, char const *argv[])
{
    int n = 10;
    int A[] = {8 , 2 , 4, 6, 5 ,5 ,7 , 1, 0, -1};
    int k = (n-1) / 2;

    int result = kSmallest(A, 0, n-1, k);
    printArray(A, n);
    cout << result << endl;
    return 0;
}

// -1 0 1 2 5 5 5 6 7 8
