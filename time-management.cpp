#include "stdc++.h"

using namespace std;

/*
So this problem that we see coming mostly where we have multiple tasks with starting time and ending time.
and we have to do most number of tasks. So I think this will solve these kind of problems.
 */

void printArray(int **A, int n) {
    for (int i = 0; i < n; ++i)
    {
        cout << A[i][0] << " " << A[i][1] << endl;
    }
    cout << endl;
}

// void merge(int **A, int i, int j) {
//     int C[j-i+1][2];
//     while
// }

void sortArray(int **A, int i, int j) {
    if(i >= j) {
        return;
    }
    int mid = (j + i) / 2;
    sortArray(A,  i,  mid);
    sortArray( A,  mid+1,  j);
    // merge(**A, int i, int j);
    int C[j-i+1][2];
    int l=i, r = mid+1;
    int k=0;
    while(l<=mid && r <= j) {
        if(A[l][1] <= A[r][1]) {
            C[k][0] = A[l][0];
            C[k][1] = A[l][1];
            l++;
            k++;
        } else {
            C[k][0] = A[r][0];
            C[k][1] = A[r][1];
            r++;
            k++;
        }
    }
    while(l<=mid) {
        C[k][0] = A[l][0];
        C[k][1] = A[l][1];
        l++;
        k++;
    }
    while(r<=j) {
        C[k][0] = A[r][0];
        C[k][1] = A[r][1];
        r++;
        k++;
    }
    for (int p = 0; p < j-i+1; ++p)
    {
        A[i+p][0] = C[p][0];
        A[i+p][1] = C[p][1];
    }
}

int countJobs(int **A, int n) {
    int curr=1;
    int prev = 0;
    int count = 1;
    while(curr<n) {
        if(A[curr][0] <= A[prev][1]) {
            curr++;
        } else {
            count++;
            prev = curr;
            curr++;
        }
    }
    return count;

}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    // int A[n][2];
    int **A = (int **)malloc((n) * sizeof(int *));
    for (int i = 0; i < n; ++i)
    {
        A[i] = (int *)malloc(2 * sizeof(int));
        cin >> A[i][0] >> A[i][1];
    }
    // printArray(A, n);
    cout << endl;
    sortArray(A, 0, n-1);
    printArray(A, n);
    cout << countJobs(A, n) << endl;

    return 0;
}
