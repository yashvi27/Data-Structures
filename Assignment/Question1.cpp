#include<iostream>

using namespace std;

void checkStack(int *x)
{
	/*
	Objective: the functions checks whether stack grows up or down
	Approach: a local variable to both the main() and udf is being defined and their addresses are compared
	Input Parameters:
		*x: local variable of main() passed as argument
	Return Value: None
	*/
	int local=5;
	cout<<"\nThe address of main variable: "<<x;
	cout<<"\nThe address of local variable of function: "<<&local;
	if(x > &local)
		cout<<"\nStack Grows Downward";
	else
		cout<<"\nStack Grows Upward";
}

int main()
{
	int a=10;
	checkStack(&a);
	return 0;
}
