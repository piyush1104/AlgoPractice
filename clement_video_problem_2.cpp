// the question is the second problem present in - https://www.youtube.com/watch?v=rw4s4M3hFfs

#include "stdc++.h"

using namespace std;

void printA(vector<bool> A[], int n) {
    for (int i = 0; i < n; ++i)
    {
        for (vector<bool>::iterator itr = A[i].begin(); itr!=A[i].end(); itr++)
        {
            cout << *itr << " ";
        }
        cout << endl;
    }
}

int getFalsePosition(vector<bool> A, int i, int j) {
    // wow, made it work in one go.
    if(i > j) {
        return i;
    }
    int mid = (j + i) / 2;
    if(A[mid] == false) {
        if(mid == i || A[mid - 1] == true) {
            return mid;
        }
        return getFalsePosition(A, i, mid-1);
    } else {
        return getFalsePosition(A, mid + 1, j);
    }
}

int getMaxPerc(vector<bool> A[], int n) {
    int maxPerc = INT_MIN;
    for (int i = 0; i < n; ++i)
    {
        int falsePosition = getFalsePosition(A[i], 0, A[i].size() - 1);
        // cout << falsePosition << endl;
        int perc = (falsePosition * 100) / A[i].size();
        if(perc > maxPerc) {
            maxPerc = perc;
        }
    }
    return maxPerc;
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    cin.ignore();
    vector<bool> A[n];
    for (int i = 0; i < n; ++i)
    {
        string s;
        getline(cin,s);
        stringstream ss(s);
        bool value;
        while(ss >> boolalpha >> value) {
            A[i].push_back(value);
        }
    }
    int maxPercentage = getMaxPerc(A, n);
    cout << endl << maxPercentage << endl;
    // printA(A, n);
    return 0;
}
