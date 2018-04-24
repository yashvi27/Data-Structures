#include <iostream>
#include <stack>

using namespace std;
std::stack<int> st;
std::stack<int> temp;

class Queue
	/*   			
	Objective: Create a class to implement Queue using STL stack 
	Approach: Class definition provides data member and member functions for the Queue class
	Description: Class definition
	Input parameters: none
	Return Value: none
	*/

{

	int *arr;			// array to store queue elements
	int capacity;			// maximum capacity of the Q

	public:
	~Queue();	
	int dequeue();
	void enqueue(int a);
	void display(); 		//display elements of the queue

};

Queue::~Queue()
{
	/*
 	Objective: The function is a destructor aims at deleting the queue
	Approach: Using STL implementation of stack
	Input Parameters: None
	Return Value: None
	*/
	delete arr;
}
 
void Queue::enqueue(int a)
{	
	/*
 	Objective: The function aims at enqueing the elements on the queue
	Approach: Using STL implementation of stack
	Input Parameters: 
		a: Element to be enqueued on to the queue
	Return Value: None
	*/
	st.push(a);
 } 

int Queue::dequeue()
{
	/*
 	Objective: The function aims at dequeueing the element on the top of the queue
	Approach: Using STL implementation of stack
	Input Parameters: None
	Return Value:
		temp: Element on the top of the queue
	*/
	while(!st.empty())
	{
		temp.push(st.top());
		st.pop();
	}

	int ele=temp.top();
	temp.pop();
	while(!temp.empty())
	{
		st.push(temp.top());
		temp.pop();
	}
		
	return ele;		
 }
 
void Queue::display()
{
	/*
 	Objective: The function is a aims at displaying the queue
	Approach: Using STL implementation of stack
	Input Parameters: None
	Return Value: None
	*/
	while(!st.empty())
	{
		temp.push(st.top());
		st.pop();
	}

	while(!temp.empty())
	{
		cout<<temp.top()<<" ";
		st.push(temp.top());
		temp.pop();
	}		
}  

int main()
{
	
	int x,a;
	char ch,chr;
	Queue ob1;
	do
	{
		cout<<"\nMenu:"
		    <<"\n1. Enqueue \n2. Dequeue \n3. Display \n4. Size of the Queue";
		cout<<"\nEnter your choice: ";
		cin>>a;
		switch(a)
		{
			case 1:do
				  {
					cout<<"\nEnter the element of queue: ";
					cin>>x;
					ob1.enqueue(x);
					cout<<"\nDo you wish to add more elements? ";
					cin>>ch;
				  }while((ch=='y')||(ch=='Y'));
				  break;
			case 2:do
				  {
					int y;
					y=ob1.dequeue();
					cout<<"\nElement deleted is : "<<y;
					cout<<"\nDo you wish to delete more elements? ";
					cin>>ch;
				  }while((ch=='y')||(ch=='Y'));
				  break;
			case 3: cout<<"Queue: \n";
					ob1.display();
					break;
			case 4: cout<<"\nSize of the queue: ";
					cout<<st.size();
					break;
			default:cout<<"\nWrong choice";
				   cin>>a;
		}
		cout<<"\nDo you wish to continue..? ";
		cin>>chr;
	}while((chr=='y')||(chr=='Y'));
	
	return 0;
}

