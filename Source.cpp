#include <iostream>
#include <fstream>

using namespace std;


int main()
{

	setlocale(LC_ALL, "Rus");
	system("color F0");

	struct WORKER
	{
		char name[15];
		char position[15];
		char number[15];
		int salary;
	};

	const char* FName = "members.txt";
	ofstream out;
	out.open(FName, ios::binary);

	int col;
	cout << "Please , enter the length of array: " << endl;
	cin >> col;
	WORKER* pmember = new WORKER[col];

	for (int i = 0; i < col; i++)
	{
		cout << "Name: " << endl;
		cin >> (pmember + i)->name;
		cout << "Job: " << endl;
		cin >> (pmember + i)->position;
		cout << "Phone number: " << endl;
		cin >> (pmember + i)->number;
		cout << "Salary: " << endl;
		cin >> (pmember + i)->salary;
	}

	out.write((char*)pmember, col * sizeof(WORKER));

	out.close();
	delete[] pmember;


	system("Pause");
	return 0;
}