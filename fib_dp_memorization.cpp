#include <iostream>
#include "stdc++.h"

using namespace std;

#define MAX 1000000
#define NIL -1

int lookup[MAX];

void _initialize(){
	int i = 0;
	for(i=0;i<MAX;i++){
		lookup[i] = NIL;
	}
}

// This is decently efficient as it takes O(n)
// But we can also optimize it further by using matrices to have(O(logn)).
int fib_memorization(int n){
	if(n <= 1) return 1;
	if(lookup[n]!=-1) return lookup[n];
	return fib_memorization(n-1)+fib_memorization(n-2);
}

int main(){
	int n = 32343242;
	_initialize();
	cout << fib_memorization(n) << endl;
	return 1;
}
