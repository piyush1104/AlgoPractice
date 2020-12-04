#include "stdc++.h"
using namespace std;
#define ll long long int

// You don't need to define these while developing in local development
// but you need them in GeeksForGeeks
#define INT_MAX 2147483647
#define INT_MIN -2147483648

// woah I made it work in one try. Lol I am on fire.
// yo, later edit - you stupid human. This is O(n) time and O(n) space algorithm. You could have done it in O(1) space. - Later Piyush
// check max_subarray_again.cpp

ll maxSumContain(int A[], int start, int end, int index) {
    ll sum = A[index];
    ll max = sum;
    for (int i = index+1; i <= end; ++i)
    {
        sum += A[i];
        if(max < sum ) {
            max = sum;
        }
    }
    sum = max;
    for (int i = index-1; i >= start; --i)
    {
        sum += A[i];
        if(max < sum) {
            max = sum;
        }
    }
    return max;
}

ll maxSum(int A[], int start, int end) {
    if(start >= end) {
        return A[start];
    }
    int middle = start + (end-start)/2;
    return max(max(maxSum(A, start, middle-1), maxSumContain(A, start, end, middle)),maxSum(A, middle+1, end));
}

// this will take O(logn) time and O(logn) space.
int main(int argc, char const *argv[])
{
    int n;
    while(1) {
        cout << "Enter the size of array:\t";
        cin >> n;
        cout << "Start Entering the values of the array:\t";
        int A[n];
        for (int i = 0; i < n; ++i)
        {
            cin >> A[i];
        }
        cout << "Your Result is:       ";
        cout << maxSum(A, 0, n-1) << endl;
    }
    return 0;
}
