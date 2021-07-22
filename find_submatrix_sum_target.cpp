#include "stdc++.h"

using namespace std;

int main() {
    int m=4, n=4;
    int mat[m][n];
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            mat[i][j] = 4 * i + j + 1;
        }
    }
    int k;
    cin >> k;
    
    int dp[m][n];
    dp[0][0] = mat[0][0];
    
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            dp[i][j] = mat[i][j];
            if(i> 0 && j>0) {
                dp[i][j] += dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1];
            } else if (i>0) {
                dp[i][j] += dp[i-1][j];
            } else if (j>0) {
                dp[i][j] += dp[i][j-1];
            }
        }
    }
    
    int found = false;
    for(int i=0; i<m; i++) {
        for(int j=0; j<=i; j++) {
            for(int p=0; p<n; p++) {
                for(int q=0; q<=p; q++) {
                    int sum = dp[i][p];
                    if(j>0 && q>0) {
                        sum = sum - dp[j-1][p] - dp[i][q-1] + dp[j-1][q-1];
                    } else if(j>0) {
                        sum = sum - dp[j-1][p];
                    } else if(q > 0) {
                        sum = sum - dp[i][q-1];
                    }
                    // cout << sum << endl;
                    if(sum == k) {
                        found = true;
                        break;
                    }
                }
            }
        }
    }
    cout << found << endl;
    return 0;
}
