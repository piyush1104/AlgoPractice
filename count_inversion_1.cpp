#include "stdc++.h"
using namespace std;

// simple one having time O(n*n)
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

        int count = 0;
        for (int i = 1; i < n; ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                if(A[j] > A[i]) {
                    count++;
                }
            }
        }

        cout << count << endl << endl;

    }
    return 0;
}
