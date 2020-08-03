#include "stdc++.h"

using namespace std;

void insertion_sort(long long int A[], int indexArray[], int n){
	int flag = true;
	for(int i=0; i<n-1; i++){
		if(A[i] > A[i+1]){
			flag = false;
		}
	}
	if(flag){
		// cout << "Your array is already sorted." << endl;
		return;
	}
	for(int i=1; i<n; i++){
		long long int value = A[i];
		int index = i;
		int j = i-1;
		while(j>=0 && value > A[j]){
			A[j+1] = A[j];
			indexArray[j+1] = indexArray[j];
			j--;
		}
		A[j+1] = value;
		indexArray[j+1] = index;
	}
	// cout << "Your sorted array is -" << endl;

	return;
}

int max_value(long long int A[], int n){
	long long int returnMax = INT_MIN;
	int returnIndex = 0;
	for(int i=0; i<n; i++){
		if(A[i] > returnMax){
			returnMax = A[i];
			returnIndex = i;
		}
	}
	return returnIndex;
}

int min_value(long long int A[], int n){
	long long int returnMin = INT_MAX;
	int returnIndex = 0;
	for(int i=0; i<n; i++){
		if(A[i] < returnMin){
			returnMin = A[i];
			returnIndex = i;
		}
	}
	return returnIndex;
}

int main(int argc, char const *argv[])
{
	// #ifndef ONLINE_JUDGE
	//     // for getting input from input.txt
	//     freopen("input.txt", "r", stdin);
	//     // for writing output to output.txt
	//     freopen("output.txt", "w", stdout);
	// #endif
	cout << "How many persons were there on dining table?" << endl;
	int n;
	cin >> n;
	long long int A[n];
	int indexArray[n];
	for(int i=0;i<n;i++){
		cout << "How much person " << i+1 << " ate? ";
		cin >> A[i];
		indexArray[i] = i;
	}
	cout << "The person who ate the most is - " << max_value(A, n)+1 << "." << endl;
	cout << "The person who ate the least is - " << min_value(A, n)+1 << "." << endl;
	insertion_sort(A, indexArray, n);

	cout << "The list in order of number of pancakes eaten  - " << endl;
	for(int i=0; i<n; i++){
		cout << "Person "<< indexArray[i] + 1  << ": ate " << A[i] << " pancakes." << endl;
	}
	return 0;
}
