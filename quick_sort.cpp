#include "stdc++.h"
using namespace std;

// we have created three partition algos all having O(n) time complexity and
// O(1) space complexity. We recommend using the third algo - partitionAdvancedAndSimple

void swap(int* A, int i, int j) {
    int temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}

// has left element has the pivot. Not that useful though
int partitionSimple(int* A, int l, int r) {
    int p=l, left=l, right=r, iter=l;
    // solution using only one single loop
    while(left < right) {
        if(iter==p){
            iter++;
        }
        if(A[iter] < A[p])
        {
            swap(A, iter, p);
            p++;
            iter++;
            left++;
        } else {
            swap(A, iter, right);
            right--;
        }
    }
    return p;
}

// it is advanced because it containse only single loop but too many if conditions
int partitionAdvanced(int* A, int l, int r, int p) {
    int left=l, right=r, iter=l;
    while(left<right) {
        if(iter == p) {
            iter++;
        }
        if(A[iter] < A[p]) {
            if(iter<p) {
                left++;
                iter++;
            } else {
                swap(A, iter, p);
                iter++;
                left++;
                p++;
            }
        } else {
            if(p == right) {
                swap(A, p, p-1);
                p--;
            }
            swap(A, iter, right);
            right--;
        }
    }
    return p;
}

// this is a good way and simple one. It does have two O(n) loops but that doesn't matter
// In exams this approach is better as it is faster
int partitionAdvancedAndSimple(int* A, int l, int r, int p) {
    int min=0;
    for (int i = l; i <= r; ++i)
    {
        if(A[i] < A[p]) {
            min++;
        }
    }
    swap(A, p , l + min);
    p = l + min;
    int left=l, right=r, iter=l;
    while(left < right) {
        if(iter == p) {
            iter++;
        }
        if(A[iter] < A[p]) {
            left++;
            iter++;
        } else {
            swap(A, iter, right);
            right--;
            // here we don't need to worry if p==right because once that happens the programm will basically stop because all the elements are arranged properly now
        }
    }
    return p;
}


// quicksort with average O(nlogn) time complexity and O(logn) space complexity
void QuickSort(int* A, int l, int r) {
    if(l>=r) {
        return;
    }
    // int p = partitionAdvanced(A, l, r, l);
    int p = partitionAdvancedAndSimple(A, l, r, l);
    // int p = partitionSimple(A, l, r);
    QuickSort(A, l, p-1);
    QuickSort(A, p+1, r);
}

int main(int argc, char const *argv[])
{
    while(true) {
        int n;
        cout << "Enter the size of array:\t";
        cin >> n;
        int A[n];
        cout << "Enter values of the array:\t";
        for (int i = 0; i < n; ++i)
        {
            cin >> A[i];
        }
        QuickSort(A, 0, n-1);
        cout << "Your sorted array is:\t";
        for (int i = 0; i < n; ++i)
        {
            cout << A[i] << " ";
        }
        cout << endl << endl;
    }
    return 0;
}
