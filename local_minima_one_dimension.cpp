#include "stdc++.h"
using namespace std;

bool checkLocalMinima(int A[], int n, int mid) {
    if(mid == 0 && A[mid + 1] > A[mid]) {
        return true;
    }
    if(mid == n-1 && A[mid - 1] > A[mid]) {
        return true;
    }
    if(A[mid - 1] > A[mid] && A[mid + 1] > A[mid]) {
        return true;
    }
    return false;
}

int localMinima(int A[], int n) {
    int left = 0, right = n;
    int mid = (left + right) / 2;
    cout << "left:  " << left << "\t right:  " << right << "\t mid:  " << mid << "\t value: " << A[mid] << endl;
    while( !checkLocalMinima(A, n, mid) ) {
        if(mid < n-1 && A[mid + 1] < A[mid]) {
            left = mid + 1;
        }
        else if(mid > 0 && A[mid - 1] < A[mid]) {
            right = mid - 1;
        }
        mid = (left + right)/2;
        cout << "left:  " << left << "\t right:  " << right << "\t mid:  " << mid << "\t value: " << A[mid] << endl;
    }
    cout << "Your Answer is:\t" << A[mid] << endl;
    return A[mid];
}

int main(int argc, char const *argv[])
{
    while(1) {
        cout << "Everything starts from here:" << endl;
        int n;
        cin >> n;
        int A[n];
        for (int i = 0; i < n; ++i)
        {
            cin >> A[i];
        }
        localMinima(A, n);
        // cout << "Your answer is:\t" << localMinima(A, n) << endl;
        cout << endl;
    }
    return 0;
}
