#include <iostream>
#include "stdc++.h"

using namespace std;

#define MAX 100
#define NIL -1

int lookup[MAX];

void _initialize(){
	int i = 0;
	for(i=0;i<MAX;i++){
		lookup[i] = NIL;
	}
}

int fib_memorization(int n){
	if(n <= 1) return 1;
	if(lookup[n]!=-1) return lookup[n];
	return fib_memorization(n-1)+fib_memorization(n-2);
}

int main(){
	int n = 40;
	_initialize();
	cout << fib_memorization(n) << endl;
	return 1;
}
