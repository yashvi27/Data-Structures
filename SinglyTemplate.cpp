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
	objective: Create a Single LInked List class 
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
	void addFront(const T& e); 		// add to front of list
	void addBack(const T& e); 			// add to back of list
	void removeFront();			 			// remove from front 
	void removeEnd();						// remove from end
	void print(); 							// prints the SLL
	private:
	SNode<T> *head; 							// pointer to the head of list
};

template <class T>
SLinkedList<T>::SLinkedList()
{
	/*
 	Objective: The function is a constructor aims at defining the linked list
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
 	Objective: The function is a constructor aims at defining the linked list
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
 	Objective: The function aims at checking if the linked list is empty or not
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
 	Objective: The function aims at returning the top most element of linked list
	Approach: Using self implementation of singly linked list class
	Input Parameters: None
	Return Value: top most element of the list
	*/
	return head->info;
}

template <class T>
void SLinkedList<T>::addFront(const T& e)
{	
	/*
 	Objective: The function aims at inserting element at the front of the linked list 
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
		SNode<T> *p;
		p=new SNode<T>;
		p->info=e;
		p->next=head;
		head=p;
	}
}

template <class T>
void SLinkedList<T>::addBack(const T& e)
{	
	/*
 	Objective: The function aims at inserting element at the end of the linked list 
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
void SLinkedList<T>::removeEnd()
{	
	/*
 	Objective: The function aims at removing element from the back of the linked list 
	Approach: Using self implementation of singly linked list class
	Input Parameters: None
	Return Value: None
	*/
	if(empty())
		cout<<"\nThe list is empty";
	else if(head->next==NULL)
  	{
    	delete head;
    	head=NULL;
  	}		
	else
	{
  		SNode<T> *temp=head;
  		SNode<T> *t;
  		while(temp->next!=NULL)
  		{
    		t=temp;
    		temp=temp->next;
  		}
  		delete t->next;
  		t->next=NULL; 
	}
}

template <class T>
void SLinkedList<T>::removeFront()
{
	/*
 	Objective: The function aims at removing element from the front of the linked list 
	Approach: Using self implementation of singly linked list class
	Input Parameters: None
	Return Value: None
	*/
	if(empty())
		cout<<"\nThe list is empty";
	
	else
	{
		SNode<T> *beg;
		beg=head->next;
		delete head;
		head=beg;
	 }
}

template <class T>
void SLinkedList<T>::print()
{
	/*
 	Objective: The function aims at displaying the linked list 
	Approach: Using self implementation of singly linked list class
	Input Parameters: None
	Return Value: None
	*/
	if(empty())
		cout<<"\nThe list is empty";
	
	else
	{
		SNode<T> *p;
		p=head;
		cout<<"\nList :\n";
		while(p!=0)
		{
			cout<<p->info<<"  ";
			p=p->next;
		}
	 }
}


int main()
{
	int n,p;
	char ch,s;
	string a;
	SLinkedList<string> ob1;
	do
	{
		cout<<"\t Menu ";
		cout<<"\n 1. Insertion";
		cout<<"\n 2. Deletion";
		cout<<"\n 3. Display the list";
		cout<<"\n 4. Display the element at the top of the list";
		cout<<"\n Enter the operation you wish to perform: ";
		cin>>n;
		switch(n)
		{
			case 1: do
					{
						cout<<" Enter the string you wish to add: ";
						cin>>a;
						cout<<"\nSelect the kind of insertion you wish to perform";
						cout<<"\n 1.At begining"
						   <<"\n 2.At end: ";
						cin>>p;
						switch(p)
						{
							case 1: ob1.addFront(a);
								   break;
							case 2: ob1.addBack(a);
								   break;
							default: cout<<"\n Wrong choice. Enter again. ";
								     cin>>p;
						}
						cout<<"\n Do you wish to continue with insertion ? ";
						cin>>ch;
					} while(ch=='y'||ch=='Y');
					break;
			case 2: do
				   {
					cout<<"\n Select the type of deletion you wish to perform";
					cout<<"\n 1.At begining"
					  <<"\n 2.At end: ";
					cin>>p;
					switch(p)
					{
						case 1: ob1.removeFront();
							   break;
						case 2: ob1.removeEnd();
							   break;
						default: cout<<"\n Wrong Choice. Enter again. ";
							    cin>>p;
					}
					cout<<"\n Do you wish to continue with deletion ? ";
					cin>>ch;
					} while( ch=='y'||ch=='Y');
					break;
			case 3: ob1.print();
				   break;
			case 4: cout<<" The element is: "<<ob1.front();
				break;
			default: cout<<" Wrong choice. Enter again. ";
					 cin>>n;
		}
		cout<<"\nDo you wish to continue ? ";
		cin>>s;

	}while(s=='y'||s=='Y');
	
	return 0;
}
