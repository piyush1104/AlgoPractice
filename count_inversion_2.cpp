#include "stdc++.h"
using namespace std;


// a way better algorith, why because it does the job in O(nlogn)
int SortAndMerge(int* A, int i, int k, int mid, int*C) {
    int p=i, q=mid+1, r=0, count=0;
    while(p <= mid && q <= k) {
        if(A[p] <= A[q]) {
            C[r] = A[p];
            r++;
            p++;
        } else {
            C[r] = A[q];
            q++;
            r++;
            count = count + mid - p + 1;
        }
    }
    while(p <= mid) {
        C[r] = A[p];
        p++;
        r++;
    }
    while(q <= k) {
        C[r] = A[q];
        r++;
        q++;
    }
    return count;
}

int SortAndCountInversion(int* A, int i, int k) {
    if(i==k) {
        return 0;
    }
    int mid = (i+k)/2;
    int count1 = SortAndCountInversion(A, i, mid);
    int count2 = SortAndCountInversion(A, mid+1, k);
    int C[k - i + 1];
    int count3 = SortAndMerge(A, i, k, mid, C);
    for (int j = i; j <= k; ++j)
    {
        A[j] = C[j-i];
    }
    return count1 + count2 + count3;
}

int main(int argc, char const *argv[])
{
    while(true) {
        cout << "Enter the size of array:\t";
        int n;
        cin >> n;
        cout << "Enter the values of array:\t";
        int A[n];
        for (int i = 0; i < n; ++i)
        {
            cin >> A[i];
        }
        cout << "Total number of inversions are:\t";
        cout << SortAndCountInversion(A, 0, n-1);
        cout << endl << endl;
    }
    return 0;
}
