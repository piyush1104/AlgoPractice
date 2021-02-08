// this is my solution for a geeks for geeks problem.
// https://practice.geeksforgeeks.org/contest-problem/maximum-sum-component/1/
// { Driver Code Starts
//Initial Template for C++

#include "stdc++.h"
using namespace std;

 // } Driver Code Ends


//User function Template for C++

class Solution{
public:
    // vector< vector<int> > adj;
    // vector<int> vis;
    // long long dfs(int node,vector<int> &Values)
    // {
    //   long long sum=Values[node-1];
    //   vis[node]=1;
    //   for(auto i:adj[node])
    //   {
    //     if(!vis[i])
    //       sum+=dfs(i,Values);
    //   }
    //   return sum;
    // }
    // long long solve2(int V,int E,vector<int> Values,vector< vector<int> > Edges){
    //   long long answer=0;
    //   adj=vector< vector<int> >(V+1);
    //   vis=vector<int>(V+1);
    //   for(auto i:Edges)
    //   {
    //     adj[i[0]].push_back(i[1]);
    //     adj[i[1]].push_back(i[0]);
    //   }
    //   for(int i=1;i<=V;i++)
    //   {
    //     if(!vis[i]){
    //        long long x=dfs(i,Values);
    //        if(answer<x)
    //           answer=x;
    //     }
    //   }
    //   return answer;
    // }
    void printAdjacentList(vector<int> A[], int V) {
        for(int i=0; i<V; i++) {
            cout << i + 1 << ": ";
            for(vector<int>::iterator itr = A[i].begin(); itr!=A[i].end(); itr++) {
                cout << (*itr) + 1 << ", ";
            }
            cout << endl;
        }
    }

    // for some reason my solution is not working while submitting on geeksforgeeks
    // though it is working on every case in my normal terminal
    long long solve(int V,int E,vector<int> Values,vector< vector<int> > Edges){
        // create an adjacency matrix
        vector<int> A[V];
        for(int i=0; i<E; i++) {
          A[Edges[i][0] - 1].push_back(Edges[i][1] - 1);
          A[Edges[i][1] - 1].push_back(Edges[i][0] - 1);
        }
        // printAdjacentList(A, V);
        // initialise the visited array to keep tracks of the visited element
        bool visited[V];
        for(int i=0; i<V; i++) {
          visited[i] = false;
        }

        long long maxSum = LONG_LONG_MIN;

        for(int i=0; i<V; i++) {
            if(visited[i]) { // those visited are not to be counted again.
              continue;
            }

            long long sum=0;

            queue<int> q;
            q.push(i);
            while(!q.empty()) {
              int el = q.front();
              q.pop();
              visited[el] = true;
              // get all the adjacent connected (and not visited) vertices of el and put them in the queue to be processed further
              for(vector<int>::iterator itr = A[el].begin(); itr!=A[el].end(); itr++) {
                 if(!visited[*itr]) {
                     q.push(*itr);
                 }
              }

              sum += Values[el];
            }
            // cout << sum << endl;
            if(sum > maxSum) {
              maxSum = sum;
            }
        }
        return maxSum;
    }
};


// { Driver Code Starts.
signed main()
{
  int t;
  cin>>t;
  while(t--)
  {
      int V,E;
      cin>>V>>E;
      vector<int> Values(V);
      for(int i=0;i<V;i++)
        cin>>Values[i];
      vector< vector<int> > Edges(E,vector<int>(2));
      for(int i=0;i<E;i++)
        cin>>Edges[i][0]>>Edges[i][1];
      Solution obj;
      long long answer=obj.solve(V,E,Values,Edges);
      cout<<answer<<endl;
  }
}  // } Driver Code Ends
