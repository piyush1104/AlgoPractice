#include "stdc++.h"

using namespace std;

int main(int argc, char const *argv[])
{
	#ifndef ONLINE_JUDGE
	    // for getting input from input.txt
	    freopen("input.txt", "r", stdin);
	    // for writing output to output.txt
	    freopen("output.txt", "w", stdout);
	#endif
	int n;
	cin >> n;
	string msg;
	if(n < 0 || n > 100){
		msg = "The score should be between 0 and 100.";
	}
	else if(n==100) {
		msg = "You got a perfect score and A.";
	}
	else if( 90 <= n && n <= 99) {
		msg = "You got an A.";
	}
	else if( 80 <= n && n <= 89) {
		msg = "You got a B.";
	}
	else if( 70 <= n && n <= 79) {
		msg = "You got a C.";
	}
	else if( 60 <= n && n <= 69) {
		msg = "You got a D.";
	}
	else if( 0 <= n && n <= 59) {
		msg = "You got a F.";
	}
	cout << msg << endl;
	return 0;
}
