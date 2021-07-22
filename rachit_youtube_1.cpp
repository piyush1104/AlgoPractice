// https://www.youtube.com/watch?v=or6zCRq3tFo&list=PLfBJlB6T2eOsuNCYu1jXEuD68423Xpsyy&index=1

// so this question is good. I thought of nlogn solution and I was being happy. Fuck I was stupid.
#include "stdc++.h"

using namespace std;

deque<int> req;

// This is in total O(n) solution. Why? Because in total we are oing to pop out total n elements at max.
int ping(int t) {
    req.push_back(t);
    while(req.front() < t - 3000) {
        req.pop_front();
    }
    return req.size();
}

int main(int argc, char const *argv[])
{
    int t;
    while(cin >> t) {
        cout << ping(t) << endl;
    }
    return 0;
}
