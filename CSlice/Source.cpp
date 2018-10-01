#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <functional>			//bind1st

#include "Person.cpp"

using namespace std;

// Compare class uses functor
class Compare
{
public:
	Compare(int v) { val = v; }
	bool operator()(int a)
	{
		return val == a;
	}
private:
	int val;
};

// Function to slice from a to b
// No need pass size as a param
template <int size>
vector<int> sliceAB(int(&nums)[size], int a, int b)
{
	vector<int> v;
	for (int i = 0, j = i - a; i < size; i++, j++)
	{
		if (i >= a && i <= b)
		{
			v.push_back(nums[i]);
		}
	}
	return v;
}



void display(vector<int> v)
{
	auto iter = v.begin();
	for (; iter < v.end(); iter++)
	{
		cout << *iter;
	}
	cout << endl;
}





int main()
{
	//Size
	int nums[] = { 3, -2, 4, 5, 5, 1 };
	int size = sizeof(nums) / sizeof(int);

	int newSize = size - 2 - (size - 4);
	vector<int> slice = sliceAB(nums, 2, 4);


	display(slice);


	//Find
	//- Function Object
	int *f = find_if(nums, nums + size, Compare(3));
	cout << *f << endl;

	//- STL: Functional 
	int *g = find_if(nums, nums + size, bind1st(equal_to<int>(), -2));
	int ind = distance(nums, g);
	if (g != end(nums))
	{
		cout << "dist " << ind << endl;
		cout << *g << endl;
	}
	else
		cout << "Null" << endl;


	//Find element in vector
	vector<Person> persons;
	Person a(20, "Laura");
	Person b(30, "Clara");
	Person c(30, "Peter");
	Person d(40, "Lola");

	persons.push_back(a);
	persons.push_back(b);
	persons.push_back(c);
	persons.push_back(d);

	Person t(20, "");
	vector<Person>::iterator iter = find(persons.begin(), persons.end(), t);
	if (iter != persons.end())
	{
		cout << "First compare: " << *iter << endl;
	}
	else
		cout << "Null" << endl;

	//Modern C++ - lambda expression
	auto ite1 = find_if(persons.begin(), persons.end(), [&t](Person& p) { return p == t; });
	if (ite1 != persons.end())
	{
		cout << "Found : " << *ite1 << endl;
	}
	else
		cout << "Null" << endl;


	system("pause");
	return 0;
}
