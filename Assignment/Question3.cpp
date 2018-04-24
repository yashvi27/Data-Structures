#include<iostream>
#include<conio.h>

using namespace std;

class lnode
{
	/*   			
	Objective: Create a class for a Node for Single Linked list
	Approach: Class defines data item is names element with datatype integer and link is named next pf lnode type
	Input Parameters: none
	Return Value: none
	Description: lnode class defines the node structure 
	*/
	public: int info;
			lnode *next;
			lnode()
			{
				info=0;
				next=NULL;
			}
			
			lnode(int a)
			{
				info=a;
				next=NULL;
			}
			
};


class llist
{
	/*   			
	objective: Create a Single LInked List class 
	input parameters: none
	output value: none
	side effects: Class llist defines Single Linked List class
	approach: Class definition
	*/
	private:
			lnode *head;
	
	public:
			llist()
			{
				head=NULL;
			}
			
			void addAtBegin(int a);
			void addAtLast(int a);
			void addAtAny(int a, int pos);					
			void traverse();
			void pairwiseReverse();
};


void llist::addAtBegin(int a)
{	
	/*
 	Objective: The function aims at inserting element at the front of the linked list 
	Approach: Using self implementation of singly linked list class
	Input Parameters: 
		a: integer value to be inserted
	Return Value: None
	*/
	lnode *p=new lnode(a);
	
	if(head==NULL)
	{	
		head=p;	
					
	}
	else
	{
		p->next=head;
		head=p;			
	}
	
}


void llist::addAtLast(int a)
{	
	/*
 	Objective: The function aims at inserting element at the end of the linked list 
	Approach: Using self implementation of singly linked list class
	Input Parameters: 
		a: integer value to be inserted
	Return Value: None
	*/
	lnode *p=new lnode(a);
	if(head==NULL)
	{
		head=p;
	}
	else
	{
		
		lnode *q;
		q=head;
		while(q->next!=NULL)
		{
			q=q->next;
		}
		q->next=p;
	}
	
}

void llist::addAtAny(int a,int pos)
{	
	/*
 	Objective: The function aims at inserting element at the particular position of the linked list 
	Approach: Using self implementation of singly linked list class
	Input Parameters: 
		a: integer value to be inserted
		pos: position of the linked list
	Return Value: None
	*/
	lnode *p=new lnode(a);
	lnode *q;
	q=head;
	while(pos-1>1)
	{
		q=q->next;
		pos=pos-1;	
	}	
	p->next=q->next;
	q->next=p;
} 


void llist::traverse()
{
	/*
 	Objective: The function aims at displaying the linked list 
	Approach: Using self implementation of singly linked list class
	Input Parameters: None
	Return Value: None
	*/
	lnode *p;
	p=head;
	if(p==NULL)
	{
		cout<<"The List is Empty.";
	}
	else
	{
		cout<<"The Linked list is: ";
		while(p!=NULL)
		{
			cout<<p->info<<" ";
			p=p->next;
		}
	}
}


void llist::pairwiseReverse()
{
	/*
 	Objective: The function aims at pairwise reversing the linked list 
	Approach: Using self implementation of singly linked list class
	Input Parameters: None
	Return Value: None
	*/
	lnode *p,*q;
	int temp;
	
	if(head==NULL)
		cout<<"Linked List Empty";
	else
	{
		p=head;
		while(p!=NULL && p->next != NULL)
		{
			q=p->next;
			temp=p->info;
			p->info=q->info;
			q->info=temp;
			p=p->next->next;
		}
	}
}




int main()
{
	int ch,choice,ins,yes,pos,key,index,cnt;
	llist *l=new llist();
	do
	{
		cout<<"\n1. Insertion. \n2. Traversing. \n3. Pairwise Swap";	
		cout<<"\nEnter your choice: ";
		cin>>ch;
		
		switch(ch)
		{
			case 1:
					do
					{
						cout<<"\nEnter the no. you wish to add: ";
						cin>>ins;
						cout<<"1. In the Begining \n2. AT the End \n3. At any position";
						cout<<"\nEnter your choice: ";
						cin>>choice;
						switch(choice)
						{
							case 1: l->addAtBegin(ins);
									l->traverse();
									break;
							case 2: l->addAtLast(ins);
									l->traverse();
									break;		
							case 3:	cout<<"\nEnter the position you wish to add? ";
									cin>>pos;
									if(pos==1)
										l->addAtBegin(ins);
									else
										l->addAtAny(ins,pos);
									l->traverse();
									break;			
						
						}
						cout<<"\n\nDo you wish to add more?(Press 1 to add more): ";
						cin>>yes;
					}while(yes==1);
					break;
					
				case 2: l->traverse();
						break;
						
				case 3:
						cout<<endl;
						l->traverse();
						cout<<endl;
						l->pairwiseReverse();
						l->traverse();
						break;
					
		}
		cout<<"\n\nDo you want to perform other operation?(Press 1 for yes): ";
		cin>>yes;		
	}while(yes==1);
}
			

