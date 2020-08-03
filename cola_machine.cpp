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
	switch(n){
		case 1:
			msg = "Here is your Coke.";
			break;
		case 2:
			msg = "Here is your Water";
			break;
		case 3:
			msg = "Here is your Sprite";
			break;
		case 4:
			msg = "Here is your drink 4";
			break;
		default:
			msg = "Error. Choice was not valid, here is your money back.";
	}
	cout << msg << endl;
	return 0;
}
