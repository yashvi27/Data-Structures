#include<iostream>
#include<stack>
#include<queue>

using namespace std;
stack <int> stk;
queue <int> que;

void initializeQueue()
{
	/*
	Objective: The function initializes the queue from the stack entered by the user
	Approach: STL implementation of stack and queue is being used
	Input Parameters: None
	Return Value: None
	*/
	int x;
	while(!stk.empty())
	{
		x=stk.top();
		que.push(x);
		stk.pop();
	}

}


bool checkConsecutive()
{
	/*
	Objective: the function check consecutive pairs in the stack ignoring the first element if the total is odd
	Approach: STL implementation of stack and queue is being used
	Input Parameters: None
	Return Value: 
		flag: bool value either true or false is being returned
	*/
	bool flag=0;
	if (que.size()%2 != 0)
		que.pop();
	int frst, scnd;
	while(!que.empty())
	{
		frst=que.front();
		que.pop();
		scnd=que.front();
		que.pop();
		if(frst+1==scnd || frst-1==scnd)
			flag=1;
		else
		{
			flag=0;
			break;
		}
	}
	return flag;
}
 


int main()
{
	int value,result;
	char ch;
	do
	{	
		cout<<"\nEnter element to be pushed: ";
		cin>>value;
		stk.push(value);	
		cout<<"\nDo you wish to enter more?(y or n): ";
		cin>>ch;
		
	}while(ch=='y'||ch=='Y');
	
	initializeQueue();
	result=checkConsecutive();
	
	if(result==1)
		cout<<"\nThe elements in the stack are consecutive.";
	else
		cout<<"\nThe elements in the stack are not consecutive.";
	
	return 0;
	
}
