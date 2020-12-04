#include "stdc++.h"

using namespace std;

// yo, very simple algo for maximum sum in a subarray. Yo fuck off.
int main(int argc, char const *argv[])
{
    int count = 10;
    int A[] = {1, 2, 3 , -2 , 6 , 7, - 15, 8, 9 , -4};
    int curr = 0;
    int max = A[0];
    for (int i = 0; i < count; ++i)
    {
        curr = curr  + A[i];
        // if curr becomes negative, nayia doob gayi. dobara start karo.
        if(curr < 0) {
            curr = 0;
            continue;
        }
        if(curr > max) {
            max = curr;
        }
    }
    cout << "max sum:\t" << max << endl;
    return 0;
}
