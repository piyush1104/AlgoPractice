#include <iostream>
#include </Users/piyushbansal/AlgoPractice/stdc++.h>

using namespace std;

int fib(int n);
int main(){
	int n = 40;
	cout << fib(n) << endl;
	return 1;
}

int fib(int n){
	if(n <=1 ){
		return 1;
	}
	return fib(n-1) + fib(n-2);
}
