// NullPtrApp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

void fun(int a) {
	cout << "inside a function"<<a << endl;
}

void fun(int* a)
{
	if (a != nullptr)
	{
		cout << "inside fun condition " << (*a) << endl;
	}
	cout << "end of (int* a)" << endl;
}

void universal(void* a) { //universal , allpointers 
	cout << "universal pointer" << endl;
}
int main()
{
	
	fun(NULL);
	fun(nullptr);
	universal(nullptr);

	int a = 20;
	int* b = &a;
	universal(b);
	fun(b);



}



