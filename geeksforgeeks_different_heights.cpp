// https://www.geeksforgeeks.org/microsoft-full-time-interview-experience-on-campus/?ref=rp
// the author's comment -

// Question 2: Students of different heights are attending an assembly. The problem is that if a student has less or equal height than the student standing above him  then he/she cannot see the assembly. Task was to find the minimum number of students randomly such that maximum number of students can see the assembly.

// Ex: 9 1 2 3 1 5

// output : 2 students i.e. 9 and 1 has to be removed so that 4 students can see the assembly.

// I saw a pattern that its an implementation of LIS.


// nice problem, let's see how can we solve it.

#include "stdc++.h"

int main(int argc, char const *argv[])
{
    int n = 6;
    int A[] = {9, 1, 2, 3 , 1, 5};
    // simple solution is O(n*n)
    vector<pair<int, int>>
    for(int i=0; i<n; i++) {

    }
    return 0;
}
