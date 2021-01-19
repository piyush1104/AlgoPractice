#include "stdc++.h"
using namespace std;

// The following code is fastest median calculation. It does it in O(n) time but the problem
// with it is that it takes O(n) space. And that sucks man. What is the use then.
// I was thinking of using this to create O(nlogn) time and O(logn) space quick sort algo. Can't do anything in this world man.
// Now the quick sort algo will take O(n) space. Fuck

void swap(int A[], int i, int j) {
    int temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}

void printArray(int A[], int l, int r) {
    for (int i = l; i <= r; ++i)
    {
        cout << A[i] << " ";
    }
    cout << endl;
}

int getMedian(int A[], int l, int r) {
    // printArray(A, l, r);
    sort(A+l, A+r+1);
    // printArray(A, l, r);
    // cout << "l: " << l << "\tr: " << r << endl;
    // printArray(A, l, r);
    return A[(r+l)/2];
}

// int getPivotLocation(int A[], int l, int r) {
//     int totalMedians = (r - l + 1 + 4)/5;
//     int medians[totalMedians];
//     for (int i = 0; i < totalMedians; ++i)
//     {
//         medians[i] = getMedian(A, l + i*5, min( l-1+(i+1)*5, r ));
//     }
//     // printArray(medians, 0, totalMedians-1);
//     return medians[0];
// }

int kSmallest(int A[], int l, int r, int k) {
    if(r-l <5) {
        sort(A+l, A+r+1);
        return A[l];
    }
    int n = r-l+1;
    int totalMedians = (n + 4)/5;
    // cout << "l: " << l << "\tr: " << r << "\tn: " << n << "\ttotalMedians: " << totalMedians << endl;
    int medians[totalMedians];
    for (int i = 0; i < totalMedians; ++i)
    {
        medians[i] = getMedian(A, l + i*5, min( l-1+(i+1)*5, r ));
    }
    // printArray(medians, 0, totalMedians-1);
    // cout << "inloop" << endl;
    int pivotValue = kSmallest(medians, 0, totalMedians-1, (totalMedians-1)/2);
    // cout << "outloop" << endl;
    // cout << pivotValue << endl;
    //get position of the element pivotValue.
    int pos=l;
    while(A[pos] != pivotValue) {
        pos++;
    }
    // cout << pos << endl;
    int p=l;
    for(int i=l; i<=r ; i++) {
        if(A[i]<pivotValue) {
            p++;
        }
    }
    // cout << p << endl;
    swap(A, pos, p);
    int left = l;
    int right = r;
    while(left!=p) {
        if(A[left] < pivotValue) {
            left++;
        } else {
            swap(A, left, right);
            right--;
        }
    }
    // printArray(A, l, r);
    // printArray(A, r);
    // cout << "p: " << p << "\tk: " << k << endl;
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
    int n = 11;
    int A[] = {8 , 2 , 4, 6, 5 ,5 ,7 , 1, 0, -1, 2};
    int k = (n-1) / 2;
    // cout << k;
    // printArray(A, 0, n-1);
    // cout << "start" << endl;
    int result = kSmallest(A, 0, n-1, k);
    // cout << "end" << endl;
    cout << "Result:" << endl;
    printArray(A, 0, n-1);
    cout << result << endl;
    sort(A, A+n);
    printArray(A, 0, n-1);
    return 0;
}

// -1 0 1 2 2 5 5 5 6 7 8
