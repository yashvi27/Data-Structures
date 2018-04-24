#include<iostream>
#include<queue>
#include<conio.h>

using namespace std;

class node
{
	/*
	Objective: Create a class for a Node for binary tree
	Approach: Class defines data item is names element with datatype interger and link is named next pf node type
	Input Parameters: none
	Return Value: none
	Description: node class defines the node structure 
	*/
	int info;
	node *left, *right;
	public :
		node(int ele,node *l=0,node * r=0)
		{
			info =ele;
			left=l;
			right=r;
		}
		friend class BinaryTree;
};

class BinaryTree
{	
	/*   			
	objective: Create a binary tree class 
	input parameters: none
	output value: none
	side effects: Class BinaryTree defines binary tree class
	approach: Class definition
	*/
	public:
		int path[100];
		node *root;
		BinaryTree();
		void insert(int);
		void traverse(node *);
		void print(int [], int);
		void paths(node *, int [], int);
};

BinaryTree::BinaryTree()
{
	/*
	Objective: constructor function of binary tree class aims at initializing the tree
	Approach: self implementation of binary trees is being used
	Input Parameters: None
	Return Values: None
	*/
	
	root=0;
}

void BinaryTree::traverse(node *ptr)
{	
	/*
	Objective: function aims at traversing the binary tree
	Approach: self implementation of inorder traversal is being used 
	Input Parameters: 
		*ptr: starting pointer that is the root node
	Return Values: None
	*/
	if(ptr)
	{
	    traverse(ptr->left);
	    cout<<ptr->info<<" ";
	    traverse(ptr->right);
	}
}

void BinaryTree::insert(int el)
{	
	/*
	Objective: function aims at inserting elements to the binary tree
	Approach: self implementation of binary trees is being used
	Input Parameters: 
		el: element to be inserted as entered by the user
	Return Values: None
	*/

	int flag=0;
	if(root==0)
		root=new node(el);
	else
	{
		node *p=root;
		while(p!=0)
		{
			if(p->left)
			{
				if(p->right)
					p=p->left;
				else
				{
					p->right=new node(el);
					flag=1;
					break;
				}
			}
			else
			{
				p->left=new node(el);
				break;
			}
			if(flag==1)
				break;			
		}
	}
	
	
}

void BinaryTree:: print(int path[],int len_path)
{
    /*
    Objective: to print the array from node to leaf
    Approach: all paths stored in path[] are being printed
    Input Parameters: 
		path[]: array to store path values
    	len_path: length of array storing path from node to leaf
    Return Value: None
    Output Value: path from node to leaf
    */
    
    cout<<"\nPaths: "<<endl;
    int i;
    for(i=0;i<len_path;i++)
    {
      cout<<path[i]<<" -> ";
    }
    cout<<path[i];
}


void BinaryTree::paths(node *head,int path[],int len_path)
{
    /*
    Objective: To print all paths from node to leaf
    Approach: Recursive call and call to print is being used
    Input Parameters: 
		head: root value
        path[]: arrray for storing path values
        len_path:length of each path
    Return Value: None
    */

    if (head==NULL)
        return;

    path[++len_path]=head->info;

    if(head->left==NULL && head->right==NULL)
    {
        print(path,len_path);
    }

    else
    {
        paths(head->left,path,len_path);                //recursive call
        paths(head->right,path,len_path);
    }

}

int main()
{
	BinaryTree bt;
	int ch, yes, ans, a;
	
	
	do
	{
		cout<<"1.Insert \n2.Traverse \n3.Find all paths \nEnter your choice: ";
		cin>>ch;
		switch(ch)
		{
			case 1: do
					{
						cout<<"\nEnter the element to be inserted: ";
						cin>>a;
						bt.insert(a);
						cout<<"\nWant to insert more?(type 1 for yes) ";
						cin>>yes;
					}while(yes==1);
					break;
			case 2: cout<<"\nInorder Traversal of tree: ";
					bt.traverse(bt.root);
					break;
			case 3: cout<<"\nAll possible paths are: ";
					bt.paths(bt.root,bt.path,-1);
					break;
			default:cout<<"Wrong choice. Enter Again. ";
					cin>>ch;
		}
		cout<<"\nWant to perform more operations?(type 1 for yes) ";
		cin>>ans;
	}while(ans==1);
}
