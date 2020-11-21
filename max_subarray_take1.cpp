#include "stdc++.h"
using namespace std;
#define ll long long int

void maxSum(int A[], int n) {
    ll max = A[0];
    int negativeIndex = -1;
    int start=0;
    int end=0;
    ll sum=0;
    for (int i = 0; i < n; ++i)
    {
        sum = sum + A[i];
        if(sum > max) {
            max = sum;
            start = negativeIndex + 1;
            end = i;
        }
        if(sum < 0) {
            sum = 0;
            negativeIndex = i;
        }
    }
    cout << "\tSum: " << max << " Start: " << start << " End: " << end << endl;
}

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
        maxSum(A, n);
    }
    return 0;
}
