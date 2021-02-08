// the question is present in this video - https://www.youtube.com/watch?v=JHzX-57dgn0&t=0s

#include "stdc++.h"

using namespace std;

#define ARR_SIZE 94

bool isSame(int smallStringCounts[], int bigStringCounts[]) {
    for (int i = 0; i < ARR_SIZE; ++i)
    {
        if(smallStringCounts[i] != bigStringCounts[i]) {
            return false;
        }
    }
    return true;
}

void printArray(int arr[]) {
    for (int i = 0; i < ARR_SIZE; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// This solution takes O(n * k) = O(n) space where k is the constant equals to
// the number of characters in the whole world. Because in the end, they are going to be constant right.
// if we are talking about real world.
// Also space complexity = O(k) = O(1), because k should be constant.
int solution1(string bigString, string smallString) {
    int n = bigString.length();
    int m = smallString.length();

    // we can take a space of 1, by creating an arrya of length - (126 - 33 + 1) = 94
    // by using ascii tables. 33 is code for "!" and 126 is code for "-".
    int smallStringCounts[ARR_SIZE];
    for (int i = 0; i < ARR_SIZE; ++i)
    {
        smallStringCounts[i] = 0;
    }

    for(int i = 0; i < m; i++)
    {
        int index = smallString[i] - '!';
        smallStringCounts[index]++;
    }

    int bigStringCounts[ARR_SIZE];
    for (int i = 0; i < ARR_SIZE; ++i)
    {
        bigStringCounts[i] = 0;
    }


    for (int i = 0; i < m; ++i)
    {
        int index = bigString[i] - '!';
        bigStringCounts[index]++;
    }

    int count = 0;

    if(isSame(smallStringCounts, bigStringCounts)) {
        count++;
    }

    for (int i = 1; i < n - m + 1; ++i)
    {
        int leftIndex = bigString[i - 1] - '!';
        bigStringCounts[leftIndex]--;

        int rightIndex = bigString[i + m - 1] - '!';
        bigStringCounts[rightIndex]++;

        if(isSame(smallStringCounts, bigStringCounts)) {
            count++;
        }
    }
    return count;
}

int solution2(string bigString, string smallString){

}

int main(int argc, char const *argv[])
{
    string bigString;
    string smallString;

    cin >> bigString;
    cin >> smallString;


    cout << solution2(bigString, smallString) << endl;


    return 0;
}
