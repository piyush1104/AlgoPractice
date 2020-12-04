#include "stdc++.h"

using namespace std;

// int convertToBinary(int n) {
//     if(n == 0) {
//         return 0;
//     }
//     if(n == 1) {
//         return 1;
//     }
//     return convertToBinary(n/2)*10 + n%2;
// }

void processBinary(string binary) {
    // string s = to_string(binary);
    int count = 0;
    int max = 0;
    for (int i = 0; i < binary.length(); ++i)
    {
        if(binary[i] == '1') {
            count++;
        } else {
            count = 0;
        }
        if(count > max) {
            max = count;
        }
    }
    cout << max << endl;
}

string convertToBinary(int n) {
    if(n == 0) {
        return "0";
    }
    if(n == 1) {
        return "1";
    }
    return convertToBinary(n/2) + to_string(n%2);
}

int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string binary = convertToBinary(n);
    // cout << binary << endl;
    processBinary(binary);
    return 0;
}
