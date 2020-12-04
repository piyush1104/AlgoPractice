#include "stdc++.h"

using namespace std;

void DFS(int start, int visited[], vector<int> adj[], int *time) {
    *time = *time + 1;
    visited[start] = *time;
    vector<int> v = adj[start];
    for (vector<int>::iterator i = v.begin(); i != v.end(); i++)
    {
        if(visited[*i] == -1) {
            DFS(*i, visited, adj, time);
        }
    }
}

void DFS_traversal(vector<int> adj[], int n, int m) {
    int visited[n];
    for (int i = 0; i < n; ++i)
    {
        visited[i] = -1;
    }
    // int *time = -1;
    // *time = -1;
    int time = 0;
    DFS(0, visited, adj, &time);
    for (int i = 0; i < n; ++i)
    {
        cout << i << " ==> " << visited[i] << endl;
    }
    cout << endl;
}

int main(int argc, char const *argv[])
{
    int n = 8;
    int m = 8;
    int e[][2] = {{1, 2}, {4, 5}, {3, 7}, {2, 5}, {3, 2}, {6, 5}, {2, 7}, {0, 3}};

    vector<int> adj[n];
    for (int i = 0; i < m; ++i)
    {
        adj[e[i][0]].push_back(e[i][1]);
        adj[e[i][1]].push_back(e[i][0]);
    }
    for (int i = 0; i < n; ++i)
    {
        cout << i << " ==>" << " ";
        for (vector<int>::iterator itr = adj[i].begin(); itr != adj[i].end() ; itr++)
        {
            cout << *itr << " ";
        }
        cout << endl;
    }
    cout << endl;
    DFS_traversal(adj, n, m);
    return 0;
}
