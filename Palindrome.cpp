#include<iostream>
#include<string>
#include<stack>
#include<queue>

using namespace std;

stack <char> s;
queue <char> q;

bool palin(string str)
{
	/*
	Objective: This functions aims at checking whether a string entered is a palindrome or not
	Approach: STL implementation of Stack and Queue is being used
	Input Parameter:
		str: String entered by the user
	Return Value:
		val: bool value of True or False 
	*/
	bool val=0;
	int len=str.size();
	int l=0;

	while(l<=len/2)
	{
		q.push(str[l]);
		l++;
	}
	
	while(l<len)
	{
		s.push(str[l]);
		l++;
	}
	

	l=0;
	while(l<len/2)
	{
		if(q.front()==s.top())
		{
			val=1;
			q.pop();
			s.pop();
			l++;
		}
		else
			l=len/2;
	}
	return val;
}

int main()
{
	
	string str;
	
	cout<<"Enter the String: ";
	cin>>str;
	if(palin(str))
		cout<<"\nString entered is a palindrome.";
	else
		cout<<"\nString entered is not a palindrome.";
		
	return 0;
}
