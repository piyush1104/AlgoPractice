#include "stdc++.h"
using namespace std;
#define ll long long int
int main() {
    //code
    int t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll a[n];
        ll s=0;
        ll s1=-1e7;
        for(ll i=0;i<n;i++)
        {
            cin>>a[i];
            s=s+a[i];
            if(s1<s)
            s1=s;
            if(s<0)
            s=0;
        }
        cout<<s1<<"\n";
    }
    return 0;
}
