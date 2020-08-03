#include "stdc++.h"

using namespace std;

int main(int argc, char const *argv[])
{
	// create a set
	set <int, greater <int> > set1;
	set1.insert(30);
	set1.insert(40);
	set1.insert(20);
	set1.insert(50);

	// create a set iterator
	set <int, greater <int> > :: iterator itr;
	for(itr = set1.begin(); itr!= set1.end(); ++itr)
	{
		cout << '\t' << *itr;
	}
	cout << endl;

	// assignment to other set
	// also assignment sorts the set. Thus we can surely say that set is a collection and we can not be sure of its order.
	set <int> set2(set1.begin(), set1.end());
	for(itr = set2.begin(); itr != set2.end(); itr++){
		cout << '\t' << *itr;
	}
	cout << endl;

	// removing elements, erases element(not value but index) upto 30 not including 30
	set2.erase(set2.begin(), set2.find(30));
	for(itr = set2.begin(); itr != set2.end(); itr++ )
	{
		cout << '\t' << *itr;
	}
	cout << endl;

	// erasing a particular value
	set2.erase(50);
	for(itr = set2.begin(); itr != set2.end(); itr++)
	{
		cout << '\t' << *itr;
	}
	cout << endl;

	// useful functions

	// size()
	// empty()
	// iterator insert (iterator position, const g) – Adds a new element ‘g’ at the position pointed by iterator.
	// erase(iterator position) – Removes the element at the position pointed by the iterator.
	// count(const g) – Returns 1 or 0 based on the element ‘g’ is present in the set or not.
	// swap()– This function is used to exchange the contents of two sets but the sets must be of same type, although sizes may differ.
	// operator= – The ‘=’ is an operator in C++ STL which copies (or moves) a set to another set and set::operator= is the corresponding operator function.

	return 0;
}
