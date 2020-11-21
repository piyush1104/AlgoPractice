#include "stdc++.h"
using namespace std;

// A O(n) time and O(1) space complexity solution
void majorityElement(int A[], int n)
{
    int count=0;
    int index = -1;
    for (int i = 0; i < n; ++i)
    {
        if(count == 0) {
            index = i;
            count++;
        } else {
            if(A[index] != A[i]) {
                count--;
            } else {
                count++;
            }
        }
    }
    if(count == 0) {
        cout << "No majority element found" << endl;
    } else {
        int sum=0;
        for (int i = 0; i < n; ++i)
        {
            if(A[i] == A[index]) {
                sum++;
            }
        }
        if(sum >= (n/2 + 1)) {
            cout << "Majority Element is:\t" << A[index] << endl;
        } else {
            cout << "No majority element found" << endl;
        }
    }
}

// A O(nlogn) time and O(n) space solution
void majorityElement2(int A[], int n)
{
    sort(A, A+n);
    // only middle element is the possible viable candidate
    int mid = n/2;
    int sum=0;
    for (int i = 0; i < n; ++i)
    {
        if(A[i] == A[mid]) {
            sum++;
        }
    }
    if(sum >= (n/2 + 1)) {
        cout << "Majority Element is:\t" << A[mid] << endl;
    } else {
        cout << "No majority element found" << endl;
    }
}

int main(int argc, char const *argv[])
{
    while(true) {
        int n;
        cout << "Size of the array:\t";
        cin >> n;
        int A[n];
        cout << "Values of array:\t";
        for (int i = 0; i < n; ++i)
        {
            cin >> A[i];
        }
        majorityElement2(A, n);
        cout << endl;
    }
    return 0;
}
