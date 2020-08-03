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
	srand(time(0));
	int n = rand() % 100 + 1;
	cout << "Please guess the number that is between 1 to 100" << endl;
	int m;
	cin >> m;
	int i = 1;
	while(m!=n){
		if(m < n) {
			cout << "Your guess is too low." << endl;
			cin >> m;
		}
		if(m > n) {
			cout << "Your guess is too high." << endl;
			cin >> m;
		}
		i++;
	}
	i++;
	cout << "You guessed right number in " << i << " guesses." << endl;
	return 0;
}
