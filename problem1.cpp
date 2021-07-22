#include "stdc++.h"
#include <map>

using namespace std;

map<int, int> stocksDayMapping;
vector<pair<int, int> > pairs;

int stockPurchaseDay(vector <int> A, int xi, int max) {
    if(xi>=max) {
        return A.size();
    }
    if(stocksDayMapping.find(xi) == stocksDayMapping.end()) {
        return -1;
    }
    return stocksDayMapping.find(xi)->second;
}

int main() {
    int n;
    cin >> n;
    vector<int> A(n);
    for(int A_i = 0; A_i < n; A_i++){
        cin >> A[A_i];
    }
    int max = A[0];

    for(int i=0; i< n; i++) {
        pairs.push_back(make_pair(A[i], i+1));
        if(max < A[i]) {
            max = A[i];
        }
    }
    sort(pairs.begin(), pairs.end());
    vector<pair<int, int> >::iterator itr = pairs.begin();
    stocksDayMapping[itr->first] = itr->second;

    vector<pair<int, int> >::iterator prevItr = itr;
    itr++;

    for(; itr != pairs.end(); itr++ ) {
        if(itr->second < prevItr->second) {
            itr->second = prevItr->second;
        }
        stocksDayMapping[itr->first] = itr->second;
        prevItr = itr;
    }
    // for(unordered_map<int, int>::iterator i = stocksDayMapping.begin(); i!= stocksDayMapping.end(); i++) {
    //     cout << i->first << " => " << i->second << endl;
    // }
    // return 0;

    int q;
    cin >> q;
    for(int a0 = 0; a0 < q; a0++){
        int xi;
        cin >> xi;
        int result = stockPurchaseDay(A, xi, max);
        cout << result << endl;
    }
    return 0;
}
