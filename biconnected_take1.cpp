#include "stdc++.h"

using namespace std;

// ap refers to articulation point. dfn stands for dfn
// works perfectly.
int DFS(vector<int> adj[], int dfn[], bool ap[], int start, int *curr_dfn) {
    *curr_dfn = *curr_dfn + 1;
    dfn[start] = *curr_dfn;
    int ancestor = start;
    int count = 0;
    for (vector<int>::iterator itr = adj[start].begin(); itr != adj[start].end(); itr++)
    {
        if(dfn[*itr] == -1) {
            count++;
            int childAncestor = DFS(adj, dfn, ap, *itr, curr_dfn);
            if(dfn[childAncestor] >= dfn[start] && dfn[start] != 0) {
                ap[start] = true;
            } else if(dfn[childAncestor] < dfn[ancestor]) {
                ancestor = childAncestor;
            }
        } else {
            if(dfn[*itr] < dfn[ancestor]) {
                ancestor = *itr;
            }
        }
    }
    if(dfn[start] == 0 && count > 1) {
        ap[start] = true;
    }
    return ancestor;
}

bool checkBiconnected(vector<int> adj[], int n, int m) {
    int dfn[n];
    bool ap[n];
    for (int i = 0; i < n; ++i)
    {
        dfn[i] = -1;
        ap[i] = false;
    }
    int curr_dfn = -1;
    DFS(adj, dfn, ap, 0, &curr_dfn);
    int count = 0;
    for (int i = 0; i < n; ++i)
    {
        if(ap[i] == true) {
            count++;
        }
        cout << i << "\tdfn from the start ==> " << dfn[i] << "\tarticulation point ==> " << ap[i] << endl;
    }
    return count > 0 ? false : true;

}

int main(int argc, char const *argv[])
{
    int n = 8;
    // int m = 8;
    // int e[][2] = {{1, 2}, {4, 5}, {3, 7}, {2, 5}, {3, 2}, {6, 5}, {2, 7}, {0, 3}};
    int m = 12;
    int e[][2] = {{1, 2}, {4, 5}, {3, 7}, {2, 5}, {3, 2}, {6, 5}, {2, 7}, {0, 3}, {0, 7}, {4, 7}, {1, 3}, {6, 1}};
    vector<int> adj[n];
    for (int i = 0; i < m; ++i)
    {
        adj[e[i][0]].push_back(e[i][1]);
        adj[e[i][1]].push_back(e[i][0]);
    }

    // cout << *adj[0].begin() << endl;

    bool isBiconnected = checkBiconnected(adj, n, m);

    cout << endl;
    cout << "Is graph biconnected?\t" << isBiconnected << endl;

    return 0;
}
