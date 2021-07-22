#include "stdc++.h"

// The problem can be found here -
// https://leetcode.com/discuss/explore/april-leetcoding-challenge-2021/1178719/Power-of-Three-or-JS-Python-Java-C%2B%2B-or-Easy-Logarithm-and-Modulo-Solutions-w-Explanation
// This is an interesting problem.
// I mean you can easily do it in O(logn) time using while/recursion method.
// But you can do it in constant time.
// The problem statement is that we have been given a number n. We need to find that this number is of the form 3^k.
// The constant time solution is take a big number of the form 3^k. Like - 1162261467
// Now check if n divides that. If n divides that then yeah it is true or false.

class Solution {
public:
    bool isPowerOfThree(int n) {
        return n > 0 && 1162261467 % n == 0;
    }
};

// Other classic, constant time solution is find the logarithm of n base to 3. If the log is an integer then good. otherwise bad.
class Solution {
public:
    bool isPowerOfThree(int n) {
        double a = log(n) / log(3);
        return abs(a - round(a)) < 1e-10;
    }
};
