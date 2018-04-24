#include<iostream>
#include<cstdlib>

#define MAXSIZE 100

using namespace std;

class MyStack

	/*
	objective: Create a class for implementing Stack dynamically using array
	input parameters: none
	output value: none
	description:  class definition
	approach: Class defines data member and member function of the stack class
	*/



{
	int *arr;					// for dynamic array 
	int top;
	int capacity;					// checks size defined by user
	
	public:
	MyStack(int);					// constructor to create array dynamically
	~MyStack();					// destructor to delete dynamically created array
	void push(int &);
	int pop();
	int peek();
	int size();					// Current size of stack
	bool isEmpty();
	bool isFull();
};

MyStack::MyStack(int size = MAXSIZE)
{
	/*
 	Objective: The function is a constructor aims at defining the stack
	Approach: Using dynamic implementation of stack class
	Input Parameters: 
		size: Length of the stack as entered by the user
	Return Value: None
	*/
	capacity = size;
	arr = new int[capacity];
	top=-1;
}

MyStack::~MyStack()
{
	/*
 	Objective: The function is a destructor aims at deleting the stack
	Approach: Using dynamic implementation of stack class
	Input Parameters: None
	Return Value: None
	*/
	delete arr;
}

bool MyStack::isEmpty()
{	
	/*
 	Objective: The function aims at checking if the stack is empty or not
	Approach: Using dynamic implementation of stack class
	Input Parameters: None
	Return Value: Boolen value of True or False
	*/
	if(top==-1)
		return 1;

	return 0;
}
	
bool MyStack::isFull()
{
	/*
 	Objective: The function aims at checking if the stack is full or not
	Approach: Using dynamic implementation of stack class
	Input Parameters: None
	Return Value: Boolen value of True or False
	*/
	if(top==capacity)
		return 1;

	return 0;
}

int MyStack::size()
{
	/*
 	Objective: The function aims at returning size of the stack
	Approach: Using dynamic implementation of stack class
	Input Parameters: None
	Return Value: 
		top+1: size of the stack
	*/
	return top+1;
}	

void MyStack::push(int &ele)
{
	/*
 	Objective: The function aims at pushing the elements on the stack
	Approach: Using dynamic implementation of stack class
	Input Parameters: 
		ele: Element to be pushed on to the stack
	Return Value: None
	*/
	if(isFull())
	{
		cout<<"\nStack is Full";
		exit(0);
	}
	else
	{
		top++;
		arr[top]=ele;
	}
}

int MyStack::pop()
{
	/*
 	Objective: The function aims at popping the element on the top of the stack
	Approach: Using dynamic implementation of stack class
	Input Parameters: None
	Return Value:
		x: Element on the top of the stack
	*/
	int x;
	if(isEmpty())
	{
		cout<<"\nStack empty";
		return 0;
	}

	else
	{
		x=arr[top];
		top--;
		return x;
	}
}

int MyStack::peek()
{
	/*
 	Objective: The function aims at returning the element on the top of the stack
	Approach: Using dynamic implementation of stack class
	Input Parameters: None
	Return Value:
		arr[top]: Element on the top of the stack
	*/
	if(isEmpty())
	{
		cout<<"\nStack empty";
		return 0;
	}
	else
		return arr[top];
}


int main()
{
	
	int x,a,size;
	char ch,chr;
	cout<<"\nEnter the size of the array:\n";
	cin>>size;
	MyStack ob1(size);
	do
	{
		cout<<"\nMenu:"
		    <<"\n1. Push \n2. Pop \n3. Peek";
		cout<<"\nEnter your choice";
		cin>>a;
		switch(a)
		{
			case 1:do
				  {
					cout<<"\nEnter the element of stack: ";
					cin>>x;
					ob1.push(x);
					cout<<"\nDo you wish to add more elements? ";
					cin>>ch;
				  }while((ch=='y')||(ch=='Y'));
				  break;
			case 2:do
				  {
					int y;
					y=ob1.pop();
					cout<<"\nElement deleted is : "<<y;
					cout<<"\nDo you wish to delete more elements? ";
					cin>>ch;
				  }while((ch=='y')||(ch=='Y'));
				  break;
			case 3:int y;
					y=ob1.peek();
					cout<<"Element on the top of the array is: "<< y;
					break;
			default:cout<<"\nWrong choice";
				   cin>>a;
		}
		cout<<"\nDo you wish to continue..? ";
		cin>>chr;
	}while((chr=='y')||(chr=='Y'));
	
	return 0;
}




