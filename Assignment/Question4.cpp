#include<iostream>
#include<conio.h>

using namespace std;

class lnode
{
	/*   			
	Objective: Create a class for a Node for circular Linked list
	Approach: Class defines data item is names element with datatype interger and link is named next pf lnode type
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
	objective: Create a Circular Linked List class 
	input parameters: none
	output value: none
	side effects: Class llist defines circular Linked List class
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
			llist* split();
};



void llist::addAtBegin(int a)
{
		
	/*
 	Objective: The function aims at inserting element at the front of the linked list 
	Approach: Using self implementation of circular linked list class
	Input Parameters: 
		a: integer value to be inserted
	Return Value: None
	*/
	lnode *p=new lnode(a);
	if(head==NULL)
	{
		head=p;
		head->next=head;						
	}
	
	else if(head->next==head)
	{
		head->next=p;
		p->next=head;
		head=p;	
	}
	else
	{
		cout<<"coming";
		lnode *q=head;
		while(q->next!=head)
			q=q->next;
		q->next=p;
		p->next=head;
		head=p;			
	}
	
}



void llist::addAtLast(int a)
{	
	/*
 	Objective: The function aims at inserting element at the end of the linked list 
	Approach: Using self implementation of circular linked list class
	Input Parameters: 
		a: integer value to be inserted
	Return Value: None
	*/
	lnode *p=new lnode(a);
	if(head==NULL)
	{
		head=p;
		head->next=head;
	}
	
	else if(head->next==head)
	{
		head->next=p;
		p->next=head;	
	}

	else
	{
		
		lnode *q;
		q=head;
		while(q->next!=head)
		{
			q=q->next;
		}
		p->next=q->next;
		q->next=p;
	}
}



void llist::addAtAny(int a, int pos)
{	
	/*
 	Objective: The function aims at inserting element at the particular position of the linked list 
	Approach: Using self implementation of circular linked list class
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
	Approach: Using self implementation of circular linked list class
	Input Parameters: None
	Return Value: None
	*/
	
	lnode *p;
	if(head==NULL)
	{
		cout<<"The List is Empty.";
	}
	
	else
	{
		p=head->next;
		int cnt=0;
		cout<<"The Linked list is: ";
		cout<<head->info<<" ";
		while(p->next!=head)
		{
			cnt++;
			cout<<p->info<<" ";
			p=p->next;
		}
		if (head->next!=head)
			cout<<p->info<<" ";
	}
}


llist * llist::split()
{
	/*
 	Objective: The function aims at splitting the linked list into two halves
	Approach: Using self implementation of circular linked list class
	Input Parameters: None
	Return Value: 
		l2: list split is being returned
	*/
	lnode *p,*q,*r;
	llist *l2=new llist();
	int cnt=1;
	p=q=head;
	
	if(head==NULL && head->next==NULL)
		return NULL;
		
	while(q->next!=head)
	{
		if(q==head and cnt!=1)
			break;
		q=q->next->next;
		r=p;
		p=p->next;	
		cnt++;
	}	
	if(q->next==head)
	{	
		r=r->next;
		p=p->next;
	}	

	r->next=this->head;

	l2->head=p;
	r=p;
	while(r->next!=head)
		r=r->next;
	r->next=l2->head;
	
	return l2;
	
}



int main()
{
	int ch,choice,ins,yes,pos,key,index,cnt;
	llist *l=new llist();
	llist *l2=new llist();
	do
	{
		cout<<"\n1. Insertion. \n2. Traversing. \n3. Splitting into two";	
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
				
				case 3: l2=l->split();
						l->traverse();
						cout<<endl;
						l2->traverse();
						
		}
		cout<<"\n\nDo you wish to perform other operation?(Press 1 for yes): ";
		cin>>yes;		
	}while(yes==1);
}
			

