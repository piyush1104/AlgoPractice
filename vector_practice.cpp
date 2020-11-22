#include "stdc++.h"

using namespace std;

int main(int argc, char const *argv[])
{
	// Vectors are same as dynamic arrays with the ability to resize itself automatically when an element is inserted or deleted, with their storage being handled automatically by the container.
	// begin() – Returns an iterator pointing to the first element in the vector
	// end() – Returns an iterator pointing to the theoretical element that follows the last element in the vector
	// refer - https://www.geeksforgeeks.org/vector-in-cpp-stl/ for more
	vector<int> v1;
	for (int i = 0; i < 5; ++i)
	{
		v1.push_back(i*10+1);
	}
	for (vector<int>::iterator i = v1.begin(); i != v1.end(); ++i)
	{
		cout << *i << ' ';
	}
	cout << endl;

	cout << "Size: " << v1.size() << endl; // Size: 5
	cout << "Capacity: " << v1.capacity() << endl; // Capacity: 8
	cout << "Max Size: " << v1.max_size() << endl; // Max Size: 4611686018427387903
	cout << endl;

	v1.resize(4);
	for (vector<int>::iterator i = v1.begin(); i != v1.end(); ++i)
	{
		cout << *i << ' ';
	}
	cout << endl;

	cout << "New Size: " << v1.size() << endl;

	if(v1.empty())
	{
		cout << "Vector is Empty." << endl;
	} else {
		cout << "Vector is not empty" << endl;
	}

	v1.shrink_to_fit();

	for (vector<int>::iterator i = v1.begin(); i != v1.end(); ++i)
	{
		cout << '\t' << *i;
	}
	cout << endl;

	cout << endl;

	cout << "front: " << v1.front();
	cout << "\nback: " << v1.back();
	cout << "\nat(2): " << v1.at(2);
	cout << endl;
	cout << endl;
	// cout << "Practicing assign etc." << endl;

	// vector<int> v;

	// fill the array with 10 five times
	// for some reason assign is taking a very long time.
	// v.assign(5, 10);
	// for (vector<int>::iterator i = v.begin(); i != v.end(); ++i)
	// {
	// 	cout << '\t' << *i;
	// }

	// this method of printing vector is also very good.
	// cout << v.size() << endl;
	// for (int i = 0; i < v.size(); ++i)
	// {
	// 	cout << '\t' << v[i];
	// }
	// cout << endl;

	// removes last element
    // v.pop_back();

    // inserts 5 at the beginning
    // v.insert(v.begin(), 5);

    // cout << "\nThe first element is: " << v[0];

    // removes the first element
    // v.erase(v.begin());

    // cout << "\nThe first element is: " << v[0];

    // swap() – It is used to swap the contents of one vector with another vector of same type. Sizes may differ.

     // Swaps v1 and v2
    // v1.swap(v2);


	return 0;
}
