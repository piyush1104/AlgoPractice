#include "stdc++.h"
using namespace std;

void Merge(int* A, int i, int k, int mid, int* C) {
    int p=i, q=mid+1, r=0;
    while(p<=mid && q<=k) {
        if(A[p] <= A[q]){
            C[r] = A[p];
            p++;
            r++;
        } else {
            C[r] = A[q];
            q++;
            r++;
        }
    }
    while(p<=mid) {
        C[r] = A[p];
        p++;
        r++;
    }
    while(q <= k) {
        C[r] = A[q];
        q++;
        r++;
    }
    return;
}

void MergeSort(int* A, int i, int k) {
    if(i==k) {
        return;
    }
    int mid = (i+k)/2;
    MergeSort(A, i, mid);
    MergeSort(A, mid+1, k);
    int C[k - i + 1];
    Merge(A, i, k, mid, C);
    for (int j = i; j <= k; ++j)
    {
        A[j] = C[j-i];
    }
    return;
}

int main(int argc, char const *argv[])
{
    while(true) {
        cout << "Enter the size of array:\t";
        int n;
		cin >> n;
		int A[n];
		cout << "Enter values of the array:\t";
		for(int i=0;i<n;i++){
            cin >> A[i];
		}
        MergeSort(A, 0, n-1);
        cout << "Your sorted array:\t";
        for(int i=0;i<n;i++){
            cout << A[i] << " ";
        }
        cout << endl << endl;
    }
    return 0;
}
