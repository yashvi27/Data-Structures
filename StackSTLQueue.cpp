#include <iostream>
#include <queue>

using namespace std;
std::queue<int> q1;
std::queue<int> q2;

class Stack
	/*   			
	Objective: Create a class to implement Stack using STL queue 
	Approach: Class definition provides data member and member functions for the stack class
	Description: Class definition
	Input parameters: none
	Return Value: none
	*/

{

	int *arr;			// array to store stack elements
	
	public:
	~Stack();	
	int pop();
	void push(int a);
	void display(); 		//display elements of the stack

};

Stack::~Stack()
{
	/*
 	Objective: The function is a destructor aims at deleting the stack
	Approach: Using STL implementation of queue
	Input Parameters: None
	Return Value: None
	*/
	delete arr;
}
 
void Stack::push(int a)
{	
	/*
 	Objective: The function aims at pushing the elements on the stack
	Approach: Using STL implementation of queue
	Input Parameters: 
		a: Element to be pushed on to the stack
	Return Value: None
	*/
    q2.push(a);
  
    while (!q1.empty())
    {
        q2.push(q1.front());
        q1.pop();
    }
 
    queue<int> q = q1;
    q1 = q2;
    q2 = q;
 } 

int Stack::pop()
{
	/*
 	Objective: The function aims at dequeueing the element on the top of the queue
	Approach: Using STL implementation of stack
	Input Parameters: None
	Return Value:
		temp: Element on the top of the queue
	*/
	if (q1.empty())
            cout<<"\nStack Empty";
    int ele=q1.front();
	q1.pop();		
	return ele;		
 }
 
void Stack::display()
{
	/*
 	Objective: The function is a aims at displaying the stack
	Approach: Using STL implementation of queue
	Input Parameters: None
	Return Value: None
	*/
	while(!q1.empty())
	{
		cout<<q1.front()<<" ";
		q2.push(q1.front());
		q1.pop();
	}
	
	queue<int> q = q1;
    q1 = q2;
    q2 = q;
		
}  

int main()
{
	
	int x,a;
	char ch,chr;
	Stack ob1;
	do
	{
		cout<<"\nMenu:"
		    <<"\n1. Push \n2. Pop \n3. Display \n4. Size of the Stack";
		cout<<"\nEnter your choice: ";
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
			case 3: cout<<"Stack: \n";
					ob1.display();
					break;
			case 4: cout<<"\nSize of the Stack: ";
					cout<<q1.size();
					break;
			default:cout<<"\nWrong choice";
				   cin>>a;
		}
		cout<<"\nDo you wish to continue..? ";
		cin>>chr;
	}while((chr=='y')||(chr=='Y'));
	
	return 0;
}

