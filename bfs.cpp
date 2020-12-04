#include "stdc++.h"

using namespace std;

// no need to implement the queue. std library already has the queue.
// though it can easily be done,
// struct queue
// {
//     int max_size;
//     int size;
//     int start;
//     int end;
//     int *data;
// };

// void insert(queue *Q, int value) {

// }

void bfs(int start, int distance[], vector<int> adj[]) {
    queue<int> q;
    distance[start] = 0;
    q.push(start);
    while(!q.empty()) {
        int ele = q.front();
        q.pop();
        vector<int> v = adj[ele];
        for (vector<int>::iterator i = v.begin(); i != v.end(); i++)
        {
            if(distance[*i] == -1) { // this means that it has not been visited before.
                distance[*i] = distance[ele] + 1;
                q.push(*i);
            }
        }
    }
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

    // cout << "wow" << endl;

    int distance[n];
    for (int i = 0; i < n; ++i)
    {
        distance[i] = -1;
    }
    int start = 0;
    // cout << "here" << endl;
    bfs(start, distance, adj);
    // cout << "here here" << endl;
    for (int i = 0; i < n; ++i)
    {
        cout << distance[i] << endl;
    }
    return 0;
}
