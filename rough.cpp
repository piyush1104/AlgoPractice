#include "stdc++.h"

using namespace std;

void processVector(vector<int> test) {
    test.push_back(10);
    test.push_back(12);
}

int main(int argc, char const *argv[])
{
    // vector<int> test;
    // processVector(test);
    // cout << test.size() << endl;
    // for (vector<int>::iterator itr = test.begin(); itr != test.end(); itr++)
    // {
    //     cout << *itr << endl;
    // }
    for (int i = 0; i < 4; ++i)
    {
        cout << i << endl;
    }
    // above^^ result = 0 1 2 3

    for (int i = 0; i < 4; i++)
    {
        cout << i << endl;
    }
    // above^^ result = 0 1 2 3
    return 0;
}
