#include <iostream>
#include <stack>

using namespace std;

 void reverseElements(stack <int> s)
 {
 	/*
 	Objective: The function aims at reversing the elements on the stack
	Approach: Each element is referred using top and is then popped out of the stack
	Input Parameters: 
		s: Object of Stack
	Return Value: None
	*/
	
 	if(s.empty())
 		cout<<"\nStack is Empty";
 	cout<<"\nStack after reversal:\n";
 	while(!s.empty())
 	{
 		cout<<s.top()<<endl;
 		s.pop();
	 }
 }
 
 void pushElements(stack <int> s, int len)
 {
 	/*
 	Objective: The function aims at pushing the elements on the stack
	Approach: Using stack template from standard template library
	Input Parameters: 
		s: Object of Stack
		len: Number of elements entered by the user
	Return Value: None
	*/
	
 	cout<<"\nEnter the elements:\n";
 	int ele;
 	for(int i=0; i<len; i++)
 	{
 		cin>>ele;
 		s.push(ele);
	 }
	 reverseElements(s);
 }
 
int main()
{
	/*
	Objective: The program aims to reverse the elements using stack
	Approach: Using stack template from standard template library
	Input Parameters: None
	Return Value: 0 is returned
	*/
	
	stack <int> s;
	
	int n;
	cout<<"\nEnter the number of elements to be pushed on to the stack: ";
	cin>>n;
	
	pushElements(s,n);
 } 
 

