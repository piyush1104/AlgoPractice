#include "stdc++.h"

using namespace std;


// This is a order(n) solution. Refer 4.1-5 of CORS.
int max_subarray(int A[], int n){
	int sum_A[n];
	sum_A[0] = A[0];
	for (int i = 1; i < n; ++i)
	{
		sum_A[i] = sum_A[i-1] + A[i];
	}
	int index_min = 0;
	int index_max = 0;
	int j=0;
	int max_sum = INT_MIN;
	while(j<n){
		int new_sum = sum_A[j] - sum_A[index_min] + A[index_min];
		int self_sum = A[j];
		if(self_sum >= max_sum && self_sum >= new_sum){
			index_min = j;
			index_max = j;
			max_sum = self_sum;
		}
		else if(new_sum >= max_sum && new_sum >= self_sum){
			index_max = j;
			max_sum = new_sum;
		}
		j++;
	}
	cout << "( " << index_min+1 << " , " << index_max+1 << " )"<< endl;
	return max_sum;
}

int main(int argc, char const *argv[])
{
	// #ifndef ONLINE_JUDGE
	//     // for getting input from input.txt
	//     freopen("input.txt", "r", stdin);
	//     // for writing output to output.txt
	//     freopen("output.txt", "w", stdout);
	// #endif
	int n;
	cin >> n;
	int A[n];
	for(int i=0; i<n; i++){
		cin >> A[i];
	}
	cout << max_subarray(A, n) << endl;
	return 0;
}
