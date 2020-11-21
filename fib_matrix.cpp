#include "stdc++.h"
using namespace std;

#define MOD 7

int* mul(int* A, int* B) {
    int* temp = (int*)malloc(4*sizeof(int));
    temp[0] = (((A[0]%MOD)*(B[0]%MOD))%MOD + ((A[1]%MOD)*(B[2]%MOD))%MOD)%MOD;
    temp[1] = (((A[0]%MOD)*(B[1]%MOD))%MOD + ((A[1]%MOD)*(B[3]%MOD))%MOD)%MOD;
    temp[2] = (((A[2]%MOD)*(B[0]%MOD))%MOD + ((A[3]%MOD)*(B[1]%MOD))%MOD)%MOD;
    temp[3] = (((A[2]%MOD)*(B[1]%MOD))%MOD + ((A[3]%MOD)*(B[3]%MOD))%MOD)%MOD;
    return temp;
}

int getValue(int* A) {
    return A[1];
}

int* powerN(int* A, int n) {
    if(n==1){
        return A;
    }
    int* temp;
    // this will return the pointer to A for n==1.
    // so you might think that manipulating it might change its value but no.
    // because we never modify the value it points to anywhere. We just refrence it to get value.
    temp = powerN(A, n/2);
    // we use pointer to A to get value and then we give new pointer to temp;
    temp = mul(temp, temp);
    if(n%2!=0) {
        // same here. so we are saved
        temp=mul(temp, A);
    }
    return temp;
}

int fib(int n) {
    int A[] = {0, 1, 1, 1};
    return getValue(powerN(A, n));
}

int main(int argc, char const *argv[])
{
    int n;
    while(1) {
        cout << "Enter your Number Here:\t";
        cin >> n;
        cout << "Your answer is:\t" << fib(n) << endl;
    }
    return 0;
}
