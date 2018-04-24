#include <iostream>
#include <cstdlib>

#define SIZE 10

using namespace std;



class Queue 
	/*   			
	Objective: Create a class to implement Queue(circular) using dynamically created array 
	Approach: Class definition provides data member and member functions for the Queue class
	Description: Class definition
	Input parameters: none
	Return Value: none
	*/

{

	int *arr;			// array to store queue elements
	int capacity;			// maximum capacity of the Q
	int front;			// front points to front element in the Q
	int rear;			// rear points to last element in the Q
	int count;			// current size of the Q


	public:
	Queue(int);			// constructor
	~Queue();	
	int dequeue();
	void enqueue(int);
	int peek();  				// returns front element
	int size();				// returns current size of Q
	bool isEmpty();
	bool isFull();
	void display(); 		//display elements of the queue

};

Queue::Queue(int size = SIZE)
{
	/*
 	Objective: The function is a constructor aims at defining the queue
	Approach: Using dynamic implementation of queue class
	Input Parameters: 
		size: Length of the queue as entered by the user
	Return Value: None
	*/
	capacity = size;
	arr = new int[capacity];
	front=rear=-1;
}

Queue::~Queue()
{
	/*
 	Objective: The function is a destructor aims at deleting the queue
	Approach: Using dynamic implementation of queue class
	Input Parameters: None
	Return Value: None
	*/
	delete arr;
}

int Queue::size()
{
	/*
 	Objective: The function aims at returning size of the queue
	Approach: Using dynamic implementation of queue class
	Input Parameters: None
	Return Value: 
		count: size of the stack
	*/
	count=rear+1;
	return count;
}

bool Queue::isEmpty()
{	
	/*
 	Objective: The function aims at checking if the queue is empty or not
	Approach: Using dynamic implementation of queue class
	Input Parameters: None
	Return Value: Boolen value of True or False
	*/
	if(front==-1)
		return 1;
	
	return 0;
}

bool Queue::isFull()
{
	/*
 	Objective: The function aims at checking if the queue is full or not
	Approach: Using dynamic implementation of queue class
	Input Parameters: None
	Return Value: Boolen value of True or False
	*/
	if (((front==0)&&(rear==capacity-1))||(front==rear+1))
		return 1;
	
	return 0;
}
void Queue::enqueue(int a)
{ 
	/*
 	Objective: The function aims at enqueing the elements on the queue
	Approach: Using dynamic implementation of queue class
	Input Parameters: 
		a: Element to be enqueued on to the queue
	Return Value: None
	*/
	if(isFull())
    { 
	 	cout<<"The queue is full.\n";
       	return;
    }
  	else if(rear==capacity-1)
	{ 
		rear=0;
		arr[rear]=a;
	}
   else
       	arr[++rear]=a;
   	
	if(isEmpty())
      	front=0;
}

int Queue::peek()
{
	/*
 	Objective: The function aims at returning the element on the top of the queue
	Approach: Using dynamic implementation of queue class
	Input Parameters: None
	Return Value:
		arr[front]: Element on the top of the queue
	*/
	if (isEmpty())
	{ 
		cout<<"The Queue is empty.\n";
	   	return 0;
	}
   	
	return arr[front];	
}

int Queue::dequeue()
{ 
	/*
 	Objective: The function aims at dequeueing the element on the top of the queue
	Approach: Using dynamic implementation of queue class
	Input Parameters: None
	Return Value:
		temp: Element on the top of the queue
	*/
	int temp;
  	temp=arr[front];
  	if (isEmpty())
	{ 
		cout<<"The Queue is empty.\n";
	   	return 0;
	}
  	if(front==rear)
	{ 
		front=-1;
	   	rear=-1;
	   	cout<<"All elements are deleted.\n";
	}

  	if(front==capacity-1)
      	front=0;
  	else
      	front++;
   	return temp;
}

void Queue::display()
{ 
	/*
 	Objective: The function is a aims at displaying the queue
	Approach: Using dynamic implementation of queue class
	Input Parameters: None
	Return Value: None
	*/
	int temp;
  	temp=front;
  	while(temp!=rear)
    {
	  
	  	cout<<arr[temp];
	  	if(temp==front)
	     	cout<<"<-FRONT";
	  	if(temp==capacity-1)
	     	temp=0;
	  	else
	     	temp++;
		cout<<endl;
    }
  	if(front==rear)
    { 
		cout<<arr[rear]<<"<-FRONT<-REAR\n";
       	return;
    }
  	cout<<arr[rear]<<"<-REAR";
}

int main()
{
	
	int x,a,size;
	char ch,chr;
	cout<<"\nEnter the size of the array:\n";
	cin>>size;
	Queue ob1(size);
	do
	{
		cout<<"\nMenu:"
		    <<"\n1. Enqueue \n2. Dequeue \n3. Peek \n4. Display \n5. Size of the Queue";
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
			case 3:int y;
					y=ob1.peek();
					cout<<"Element on the top of the queue is: "<< y;
					break;
			case 4: cout<<"Queue: \n";
					ob1.display();
					break;
			case 5: cout<<"\nSize of the queue: ";
					cout<<ob1.size();
					break;
			default:cout<<"\nWrong choice";
				   cin>>a;
		}
		cout<<"\nDo you wish to continue..? ";
		cin>>chr;
	}while((chr=='y')||(chr=='Y'));
	
	return 0;
}

