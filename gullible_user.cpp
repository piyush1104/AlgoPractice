#include "stdc++.h"

using namespace std;

int main(int argc, char const *argv[])
{
	// #ifndef ONLINE_JUDGE
	//     // for getting input from input.txt
	//     freopen("input.txt", "r", stdin);
	//     // for writing output to output.txt
	//     freopen("output.txt", "w", stdout);
	// #endif
	int m = 0;
	cout << "Enter any number other than " << m << "." << endl;
	int n;
	cin >> n;

	while(n!=m){
		m++;
		cout << "Enter any number other than " << m << "." << endl;
		cin >> n;
	}
	cout << "Hey! you weren't supposed to enter " << m << "!" << endl;
	return 0;
}
