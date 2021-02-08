// { Driver Code Starts
//Initial Template for C++

#include "stdc++.h"
using namespace std;
int WordLadderLength(string start, string target, set<string>& D);

 // } Driver Code Ends


//User function Template for C++

int diff(string s1, string s2)
{
    int sum = 0;
    for(int i=0; i<s1.length(); i++)
    {
        if(s1[i] != s2[i])
        {
            sum ++;
        }
    }
    return sum;
}


int getDistance(string start, string target, int n, string S[], int distance[])
{
    if(start == target) return 1;
    int min = INT_MAX;

    // -3 for unvisited
    // -2 visited but value has not been decided yet
    // -1 for not reachable
    //  0 for saying it is same one and other integers as transformation
    cout << endl << "\t\t\tcurrently handling: " << start << endl;
    for(int i=0; i<n; i++)
    {
        string curr = S[i];
        int d = diff(start, curr);
        if(d == 1)
        {
            int dist = INT_MAX;
            if(distance[i] == -3)
            {
                distance[i] = -2;
                // cout << "coming from : " << currIndex << " : " << S[currIndex] << ", " << curr << " : " << i << endl;
                dist = getDistance(curr, target, n, S, distance);
                // cout << endl;
                cout << "----new distance calculated----" << endl;
                // cout << "diff is: " << d << endl;
                cout << "from: " << curr << " to target: " << target << " => " << dist << endl;
                distance[i] = dist;
            } else if(distance[i] != -2 && distance[i] != -1) {
                dist = distance[i];
                cout << "----previous distance used----" << endl;
                cout << "from: " << curr << " to target: " << target << " => " << dist << endl;
            }
            // cout << dist << endl;
            if(dist == -1) {
                continue;
            } else if(min > dist) {
                min = dist;
            }
        }
    }

    cout << "\t\t\texiting: " << start << endl << endl;

    return min == INT_MAX ? min : min + 1;
}

void printS(string S[], int n)
{
    cout << endl;
    for (int i = 0; i < n; ++i)
    {
        cout << S[i] << ", ";
    }
    cout << endl;
}

int WordLadderLength(string start, string target, set<string>& D)
{
    if(start == target) return 1;
    int n = D.size();
    int m = start.length();
    int distance[n];
    string S[n];
    for(int i=0; i<n; i++)
    {
        distance[i] = -3;
    }
    int j=0;
    for (set<string>::iterator itr = D.begin(); itr!=D.end(); itr++)
    {
        S[j] = *itr;
        j++;
    }

    bool found = false;
    int startIndex, targetIndex;
    for(int i=0; i<n; i++)
    {
        if(S[i] == start) {
            distance[i] = -2;
            startIndex = i;
        }
        if(S[i] == target) {
            found = true;
            targetIndex = i;
        }
    }
    if(!found) return 0;
    int min = getDistance(start, target, n, S, distance);
    return min == INT_MAX ? 0 : min;
}

// { Driver Code Starts.

int main()
{
        set <string> D;
        int n;
        cin>>n;
        for (int i = 0; i < n; ++i)
        {
            string str;
            cin>>str;
            //D[i] = str;
            D.insert(str);
        }
        string start,target;
        cin>>start;
        cin>>target;
        cout << WordLadderLength(start, target, D)<<endl;
    // }
    return 0;
}
  // } Driver Code Ends
