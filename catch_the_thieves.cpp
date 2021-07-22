// this problem is the first problem discussed here - https://www.youtube.com/watch?v=MFkqnGiCCiU

#include "stdc++.h"

using namespace std;

// for(int i=n-1; i >=0 ; i--) {
//         if(A[i] == 'T') {
//             if( lastIndex - i >= k) {
//                 lastIndex--;
//             }
//             if(A[lastIndex] == 'P') {
//                 lastIndex = i;
//             }
//         }
//         else {
//             if(A[lastIndex] == 'P') {
//                 lastIndex--;
//             } else {
//                 max++;
//                 lastIndex--;
//             }
//         }
//         cout << i << "  " << lastIndex << endl;
//     }

int main(int argc, char const *argv[])
{

    // https://www.geeksforgeeks.org/policemen-catch-thieves/
    // see the solution in this link also. They have solution with O(1) space complexity and O(n) (or more like O(2n)) time complexity
    int n =12;
    char A[] = {'P', 'T', 'P', 'P', 'T', 'P', 'T', 'P', 'T', 'T', 'T', 'T'};
    // int lastIndex = n - 1;
    int max = 0;
    int k = 3;
    deque<int> police;
    deque<int> thief;

    // working fine bro

    for(int i = n - 1; i >= 0; i--) {
        if(!police.empty() && police.front() - i > k) {
            police.pop_front();
        }
        if(!thief.empty() && thief.front() - i > k) {
            thief.pop_front();
        }
        if(A[i] == 'T') {
            if(!police.empty()) {
                max++;
                police.pop_front();
            } else {
                thief.push_back(i);
            }
        } else {
            if(!thief.empty()) {
                max++;
                thief.pop_front();
            } else {
                police.push_back(i);
            }
        }
    }
    cout << max << endl;
    return 0;
}
