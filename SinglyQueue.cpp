#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

template <class T>
class SNode { 
	/*   			
	Objective: Create a class for a Node for Single Linked list
	Approach: Class defines data item is names element with datatype string and link is named next pf snode type
	Input Parameters: none
	Return Value: none
	Description: SNode class defines the node structure 
	*/
	public:
	  	T info; 
	  	SNode<T> *next; 
	
	template <class X>
	friend class SLinkedList;  // provides SLinkedList access to SNode
};

template <class T>
class SLinkedList { 
	/*   			
	objective: Create a Queue from Single LInked List class 
	input parameters: none
	output value: none
	side effects: Class SlinkedList defines Single Linked LIst class
	approach: Class definition
	*/						
	public:
	SLinkedList();							// empty list constructor
	~SLinkedList();							// destructor
	bool empty() const; 					// is list empty?
	const T& front() const; 			// get front element
	void addBack(const T& e); 			// add to back of list
	T removeFront();			 			// remove from front 
	void print(); 							// prints the SLL
	private:
	SNode<T> *head; 							// pointer to the head of list
};

template <class T>
SLinkedList<T>::SLinkedList()
{
	/*
 	Objective: The function is a constructor aims at defining the queue
	Approach: Using self implementation of singly linked list class
	Input Parameters: None
	Return Value: None
	*/
	head=0;
}

template <class T>
SLinkedList<T>::~SLinkedList()
{
	/*
 	Objective: The function is a destructor aims at defining the queue
	Approach: Using self implementation of singly linked list class
	Input Parameters: None
	Return Value: None
	*/
	head=NULL;
}

template <class T>
bool SLinkedList<T>::empty() const
{
	/*
 	Objective: The function aims at checking if the queue is empty or not
	Approach: Using self implementation of singly linked list class
	Input Parameters: None
	Return Value: bool value of True or False
	*/
	if(head==NULL)
		return 1;
	return 0;
}

template <class T>
const T& SLinkedList<T>::front() const
{
	/*
 	Objective: The function aims at returning the top most element of queue
	Approach: Using self implementation of singly linked list class
	Input Parameters: None
	Return Value: top most element of the list
	*/
	return head->info;
}

template <class T>
void SLinkedList<T>::addBack(const T& e)
{	
	/*
 	Objective: The function aims at inserting element at the end of the queue 
	Approach: Using self implementation of singly linked list class
	Input Parameters: 
		e: string value to be inserted
	Return Value: None
	*/
	if(empty())
	{
		head=new SNode<T>;
		head->info=e;
		head->next=NULL;
	}
	
	else
	{
		SNode<T> *p, *last;
		last=head;
		p=new SNode<T>;
		p->info=e;
		p->next=NULL;
		while (last->next!=NULL)
        	last=last->next;
    	last->next=p;
	}
	
}

template <class T>
T SLinkedList<T>::removeFront()
{
	/*
 	Objective: The function aims at removing element from the front of the queue
	Approach: Using self implementation of singly linked list class
	Input Parameters: None
	Return Value: None
	*/
	if(empty())
		cout<<"\nThe queue is empty";
	
	else
	{
		T temp;
		SNode<T> *beg;
		beg=head->next;
		temp=head->info;
		delete head;
		head=beg;
		return temp;
	 }
}

template <class T>
void SLinkedList<T>::print()
{
	/*
 	Objective: The function aims at displaying the queue
	Approach: Using self implementation of singly linked list class
	Input Parameters: None
	Return Value: None
	*/
	if(empty())
		cout<<"\nThe queue is empty";
	
	else
	{
		SNode<T> *p;
		p=head;
		while(p!=0)
		{
			cout<<p->info<<"  ";
			p=p->next;
		}
	 }
}

int main()
{
	
	int a;
	char ch,chr;
	string x;
	SLinkedList<string> ob1;
	do
	{
		cout<<"\nMenu:";
		cout<<"\n1. Enqueue \n2. Dequeue \n3. Peek \n4. Display";
		cout<<"\nEnter your choice: ";
		cin>>a;
		switch(a)
		{
			case 1:do
				  {
					cout<<"\nEnter the element of queue: ";
					cin>>x;
					ob1.addBack(x);
					cout<<"\nDo you wish to add more elements? ";
					cin>>ch;
				  }while((ch=='y')||(ch=='Y'));
				  break;
			case 2:do
				  {
					string y;
					y=ob1.removeFront();
					cout<<"\nElement deleted is : "<<y;
					cout<<"\nDo you wish to delete more elements? ";
					cin>>ch;
				  }while((ch=='y')||(ch=='Y'));
				  break;
			case 3:
					cout<<"Element on the top of the queue is: "<< ob1.front();
					break;
			case 4: cout<<"Queue: \n";
					ob1.print();
					break;
			default:cout<<"\nWrong choice";
				   cin>>a;
		}
		cout<<"\nDo you wish to continue..? ";
		cin>>chr;
	}while((chr=='y')||(chr=='Y'));
	
	return 0;
}


