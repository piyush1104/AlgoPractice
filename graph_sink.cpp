#include "stdc++.h"

using namespace std;

int main(int argc, char const *argv[])
{
    int n = 7;
    int v[] = {0, 1, 2, 3, 4 ,5 ,6};
    int m = 7;
    int e[][2] = {{0,1}, {0,6}, {1, 6}, {3,6}, {4,6}, {5,6}, {2,6}};
    int A[n][n];

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            A[i][j] = 0;
        }
    }
    for (int i = 0; i < m; ++i)
    {
        A[e[i][0]][e[i][1]] = 1;
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }

    // finding the sink

    int s=0;
    for (int i = 1; i < n; ++i)
    {
        // if there is not any edge from i to s, it means that s is invalid and since there is no
        // edge coming from i(to s) we can think that it is a viable candidate. (all the others 0 to i-1)
        // were having edge to s, so they are already invalid, all the remaining elements (i to n-1)
        // are left that can be viable candidate.
        // also to note is that there can only be one sink.
        if(A[i][s] == 0) {
            s = i;
        }
    }
    // verifying that the candidate we recieved from the top is really the sink or not.
    bool isSink = true;
    // we need to check until s-1 only. After that we have already verified in the loop above.
    for (int i = 0; i < s; ++i)
    {
        // if there is no edge from i to s, that means we don't have a viable candidate.
        if(A[i][s] == 0) {
            isSink = false;
        }
    }
    for (int i = 0; i < n; ++i)
    {
        // if there is any edge going from s to i, it means our candidate is wrong.
        if(A[s][i] == 1) {
            isSink = false;
        }
    }

    if(isSink) {
        cout << "Yes we have a sink and its value is-\t" << s << endl;
    } else {
        cout << "No we don't have the sink" << endl;
    }


    return 0;
}
