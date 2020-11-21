#include "stdc++.h"
using namespace std;

// this is O(nlogn) solution. O(n) solution is also possible. Find other file like this which has it.

bool checkMinimaItem(int** A, int m, int n, int i, int j) {
    if(j==n) {
        if(i == 0) {
            if(A[i][j] < A[i][j-1] && A[i][j] < A[i+1][j]) {
                return true;
            }
        } else if(i == m - 1) {
            if(A[i][j] < A[i][j-1] && A[i][j] < A[i-1][j]) {
                return true;
            }
        }
        else {
            if(A[i][j] < A[i][j-1] && A[i][j] < A[i-1][j] && A[i][j] < A[i+1][j]) {
                return true;
            }
        }
    } else if (j==0) {
        if(i == 0) {
            if(A[i][j] < A[i][j+1] && A[i][j] < A[i+1][j]) {
                return true;
            }
        } else if(i == m - 1) {
            if(A[i][j] < A[i][j+1] && A[i][j] < A[i-1][j]) {
                return true;
            }
        }
        else {
            if(A[i][j] < A[i][j+1] && A[i][j] < A[i-1][j] && A[i][j] < A[i+1][j]) {
                return true;
            }
        }
    } else {
        if(i == 0) {
            if(A[i][j] < A[i][j-1] && A[i][j] < A[i][j+1] && A[i][j] < A[i+1][j]) {
                return true;
            }
        } else if(i == m - 1) {
            if(A[i][j] < A[i][j-1] && A[i][j] < A[i][j+1] && A[i][j] < A[i-1][j]) {
                return true;
            }
        }
        else {
            if(A[i][j] < A[i][j-1] && A[i][j] < A[i][j+1] && A[i][j] < A[i-1][j] && A[i][j] < A[i+1][j]) {
                return true;
            }
        }
    }
    return false;
}

int checkLocalMinima(int** A, int m, int n, int mid) {
    int index = -1;
    for (int i = 0; i < m; ++i)
    {
        if(checkMinimaItem(A, m, n, i, mid)) {
            return i;
        }
    }
    return index;
}

int getMinimum(int** A, int m, int n, int mid) {
    int index = 0;
    int min = A[0][mid];
    for (int i = 0; i < m; ++i)
    {
        if(A[i][mid] < min) {
            min = A[i][mid];
            index = i;
        }
    }
    return index;
}

int localMinima(int** A, int m, int n) {
    int left = 0, right = n;
    int mid = (right + left ) / 2;
    int localMinimaIndex = checkLocalMinima(A, m, n, mid);
    cout << "left: " << left << "\t right: " << right << "\t mid: " << mid << endl;
    while(localMinimaIndex == -1) {
        int minIndex = getMinimum(A, m, n, mid);
        if(mid < n - 1 && A[minIndex][mid + 1] < A[minIndex][mid]) {
            left = mid + 1;
        }
        else if(mid > 0 && A[minIndex][mid - 1] < A[minIndex][mid]) {
            right = mid - 1;
        }
        cout << "min: " << A[minIndex][mid] << endl;
        mid = (right + left ) / 2;
        cout << "left: " << left << "\t right: " << right << "\t mid: " << mid << endl;
        localMinimaIndex = checkLocalMinima(A,m, n, mid);
    }
    cout << "row Index for last mid is: " << localMinimaIndex << endl;
    cout << "Your answer is:\t" << A[localMinimaIndex][mid] << endl;
    return A[localMinimaIndex][mid];
}

int main(int argc, char const *argv[])
{
    while(1) {
        cout << "Everything starts here:" << endl;
        int m,n;
        cin >> m >> n;
        int** A;
        A = (int**) malloc(m * sizeof(int*));
        for (int i = 0; i < m; ++i)
        {
            A[i] = (int*) malloc(n * sizeof(int));
            for (int j = 0; j < n; ++j)
            {
                cin >> A[i][j];
            }
        }
        localMinima(A, m, n);
        cout << endl;
    }
    return 0;
}
