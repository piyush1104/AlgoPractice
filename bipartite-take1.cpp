#include "stdc++.h"

using namespace std;


// sahi hai bhai, bakchod kaam kar raha
bool findBipartiteUsingBFS(vector<int> adjacency_list[], int n, int m) {
    queue<int> q;
    int distance[n];
    for (int i = 0; i < n; ++i)
    {
        distance[i] = -1;
    }
    q.push(0);

    while(!q.empty()) {
        int element = q.front();
        q.pop();
        vector<int> v = adjacency_list[element];
        for (vector<int>::iterator i = v.begin(); i != v.end(); i++)
        {
            if(distance[*i] == -1) {
                distance[*i] = distance[element] + 1;
                q.push(*i);
            } else if(distance[*i] == distance[element]) {
                return false;
            }
        }
    }

    return true;
}

int main(int argc, char const *argv[])
{
    int n = 8;
    int m = 9;
    int e[][2] = {{1, 2}, {4, 5}, {3, 7}, {2, 5}, {3, 2}, {6, 5}, {0, 3}, {0, 1}, {1, 5}};

    vector<int> adjacency_list[n];

    for (int i = 0; i < m; ++i)
    {
        adjacency_list[e[i][0]].push_back(e[i][1]);
        adjacency_list[e[i][1]].push_back(e[i][0]);
    }

    bool isBapartite = findBipartiteUsingBFS(adjacency_list, n, m);

    cout << "Is the graph bipartite?\t" << isBapartite << endl;

    return 0;
}
