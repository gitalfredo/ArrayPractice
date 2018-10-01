#include <iostream>
#include <string>
#include <vector>


using namespace std;

class Person
{
public:
	Person() {}

	Person(int a, string n) { age = a; name = n; }

	//Getters
	int getAge() { return age; }
	string getName() { return name; }

	//Overload operator
	friend ostream& operator<<(ostream& out, Person& a)
	{
		out << a.getAge() << " " << a.getName() << endl;
		return out;
	}

	friend ostream& operator<<(ostream& out, vector<Person>::iterator iter)
	{
		out << (*iter).getAge() << " " << (*iter).getName() << endl;
		return out;
	}

	//Comparison by age
	bool operator==(Person p)
	{
		return this->age == p.getAge();
	}

private:
	int age;
	string name;
};