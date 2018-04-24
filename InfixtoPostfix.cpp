#include<iostream>
#include<cstdlib>
#include<stack>

using namespace std;
 
int prec(char c)
{
	/*
	Objectibve: the function returns precedence of operators
	Approach: Basic self implementation is used
	Input Parameters:
		c: operator whose precedence is to be known
	Return Value:
		int: precedence is being returned
	*/
    if(c == '^')
    return 3;
    else if(c == '*' || c == '/')
    return 2;
    else if(c == '+' || c == '-')
    return 1;
    else
    return -1;
}
 
 
void infixToPostfix(string s)
{
	/*
	Objectibve: the function converts infix expression to postfix expression
	Approach: Basic self implementation is used
	Input Parameters:
		s: expression to be converted
	Return Value: None
	*/
    std::stack<char> st;
    st.push('%');
    int l = s.length();
    string ns;
    for(int i = 0; i < l; i++)
    {
        if((s[i] >= 'a' && s[i] <= 'z')||(s[i] >= 'A' && s[i] <= 'Z'))
        	ns+=s[i];
 
        else if(s[i] == '(')
        	st.push('(');

        else if(s[i] == ')')
        {
            while(st.top() != '%' && st.top() != '(')
            {
                char c = st.top();
                st.pop();
               	ns += c;
            }
            if(st.top() == '(')
            {
                char c = st.top();
                st.pop();
            }
        }      
        else{
            while(st.top() != '%' && prec(s[i]) <= prec(st.top()))
            {
                char c = st.top();
                st.pop();
                ns += c;
            }
            st.push(s[i]);
        }
 
    }

    while(st.top() != '%')
    {
        char c = st.top();
        st.pop();
        ns += c;
    }
     
    cout<<"\nConverted Expression: "<<ns;
 
}


int main()
{
	string exp;
	cout<<"Enter the string: ";
	cin>>exp;
    infixToPostfix(exp);
    return 0;
}
